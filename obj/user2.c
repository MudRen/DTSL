// user.c

#include <origin.h>
#include <user.h>
#include <ansi.h>

inherit CHARACTER;
inherit F_AUTOLOAD;
inherit F_SAVE;
inherit F_ENCODING;

static int last_age_set;
static int pk_msg_time;//pk ��Ϣ���ʱ�䡣add by yanyan

void create()
{
	::create();
	set_name("ʹ�������", ({ "user object", "user", "object" }) );
}

void terminal_type(string term_type)
{
	set_temp("terminal_type", term_type);
	message("system", "�ն˻���̬�趨Ϊ " + term_type + "��\n", this_object());
}
//ͨ���� ��Ϣ add by yanyan
int show_pk_msg(object me)
{
	object *usr;
	
	pk_msg_time++;
	if(pk_msg_time>=20)
		pk_msg_time = 0;
	else
		return 1;	

	usr=users();
	usr=filter_array(usr,"filter_listen",this_object());
	message("vision",HIM"��ҥ�ԡ�ĳ�ˣ���˵"+me->name()+HIM+"��"+
         MISC_D->find_place(environment(me))+HIM+"һ�����\n"NOR,usr);
	return 1;
}

int filter_listen(object ob)
{
  if(ob==this_object()) return 0;
  return 1;
}

void reset()
{
	
	if(query("killer_time")&&(time()-query("killer_time")>3600)){
		delete("killer");
		delete("killer_time");
	}
	
	if(query("pker")&&query("pker_time")&&(time()-query("pker_time")>=3600*query("pker"))){
		delete("pker");
		delete("pker_time");
		message("vision",HIR"�����Ʒ��ơ�"+HIY+"��˵��"+HIG+query("name")+HIY+"��ͨ�������ˣ�\n"NOR,users());
	}
	if(query("zuolao")&&(time()-query("zuolao_time")>=3600*query("zuolao"))){
		delete("zuolao");
		delete("zuolao_time");
		move("/d/yangzhou/hotel");
		message("vision",HIR"�����Ʒ��ơ�"+HIY+"��˵"+HIG+query("name")+HIY+"�����ͷ��ˣ�\n"NOR,users());
	}
	
	if(query("thief"))
	 add("thief",-1);
}

// This is used by F_SAVE to determine the filename to save our data.
string query_save_file()
{
	string id;

	id = geteuid();
	if( !id ) id = getuid();
	if( !stringp(id) ) return 0;
	return sprintf(DATA_DIR "user/%c/%s", id[0],id);
}

int save()
{
	int res;

	save_autoload();
	
	res = ::save();
	clean_up_autoload();		// To save memory
	return res;
}

// This function updates player's age, called by heart_beat()

void clear_last_age()
{
	last_age_set=0;
}

void update_age()
{
	//��һ�� 24 Сʱ���ڶ��� 25Сʱ�������� 26 Сʱ ... ...
       if(environment()&&environment()->query("no_time")){
        
        last_age_set = time();
        return;
    }
    if( !last_age_set ) last_age_set = time();
	add("mud_age", time() - last_age_set);
	last_age_set = time();
	
	if(query("age")>0)//��һ�ε�½
		set("old_age",query("age"));
	else
		set("old_age",10);
		
	set("age", 10 + (int)query("age_modify")/86400 +
							query("add_age")+ 
						  (query("mud_age")-query("old_mud_age"))/
						  (86400+(query("age")-9)*3600) );
	
	if(query("age")>=200)
	  set("age",query("old_age"));
	if(query("age")>query("old_age")){
		add("add_age",query("age")-query("old_age"));
		set("old_mud_age",query("mud_age"));
	}
	if(query("age")>query("old_age")&&
	query("family/family_name")!="�Ⱥ���ի"){
	 set("kar",10+random(11)+random(11));
	 tell_object(this_object(),HIY"\n\n����һ���ȥ�ˣ���֪��һ�����������ô����\n\n"NOR);
	}
	
	
}
void check_skills(object ob)
{
  int i;
  mapping skill;mixed *skills;
  skill=ob->query_skills();
if(!skill) return;
  skills=keys(skill);
  for(i=0;i<sizeof(skills);i++)
  {
    if(ob->query_skill(skills[i],1)>ob->query("max_pot")-100&&
    SKILL_D(skills[i])->query_type()!="knowledge"&&
    SKILL_D(skills[i])->query_type()!="literate")
    ob->set_skill(skills[i],ob->query("max_pot")-100);
   }
  return;
}

void check_force(object ob)
{
   if(ob->query("max_force")>ob->query_skill("force",1)*63/4){
     ob->set("max_force",ob->query_skill("force",1)*63/4);
     ob->set("force",ob->query_skill("force",1)*63/4);
     log_file("bug_force_player",ob->query("name")+"   "+ob->query("id")+"��\n");
     tell_object(ob,"\n\n����������޳���������ֵ�����ڱ����񽵵��ˣ�\n"+
                    "����˺��Ѿ�����¼�ڰ���\n\n");
   }
   return;
}
   

void setup()
{
	// We want set age first before new player got initialized with
	// random age.
	
	update_age();

	::setup();
	restore_autoload();
	
	check_skills(this_object());
	check_force(this_object());
	
}

private void user_dump(int type)
{
	switch(type) {
		case DUMP_NET_DEAD:
			tell_room( environment(), query("name") + "���߳��� "
				+ NET_DEAD_TIMEOUT/60 + " ���ӣ��Զ��˳�������硣\n");
			this_object()->enable_player();
			command("quit");
			break;
		case DUMP_IDLE:
			if( !wizardp(this_object())) {
			tell_object( this_object(), "�Բ������Ѿ��������� " 
				+ IDLE_TIMEOUT/60 + " �����ˣ����´�������\n");
			tell_room( environment(), "һ��紵�����������е�" + query("name")
				+ "��Ϊһ�ѷɻң���ʧ�ˡ�\n", ({this_object()}));
			this_object()->enable_player();
			this_object()->start_busy(0);
			command("quit");
			}
			break;
		default: return;
	}
}

// net_dead: called by the gamedriver when an interactive player loses
// hir network connection to the mud.
private void net_dead()
{
	object link_ob;

	set_heart_beat(0);
	if( objectp(link_ob = query_temp("link_ob")) )
		destruct(link_ob);

	// Stop fighting, we'll be back soon.
	remove_all_enemy();

	set_temp("netdead", 1);
	if( userp(this_object()) ) {
		call_out("user_dump", NET_DEAD_TIMEOUT, DUMP_NET_DEAD);
	    tell_room(environment(), query("name") + "�����ˡ�", this_object());
	    CHANNEL_D->do_channel(this_object(), "sys", "�����ˡ�");
	} else {
		command("quit");
	}
}

// reconnect: called by the LOGIN_D when a netdead player reconnects.
void reconnect()
{
	set_heart_beat(1);
	set_temp("netdead",0);
	remove_call_out("user_dump");
	tell_object(this_object(), "����������ϡ�\n");
}

