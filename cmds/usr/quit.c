// quit.c

#include <command.h>
#include <ansi.h>
#include <job_money.h>

inherit F_DBASE;
inherit F_CLEAN_UP;

int do_drop(object me, object obj);

void create() 
{
	seteuid(getuid());
	set("channel_id", "����ָ��");
}

int main(object me)
{
	int i,j;
	object link_ob,where;
	where=environment(me);
	link_ob = me->query_temp("link_ob");
	if(me->query_temp("quitting"))
	return notify_fail("�����˳���Ϸ��\n");
	if (me->query_temp("no_move")) return notify_fail("�㱻��ס�ˣ������˵ó���Ϸ��\n");
 if(me->query("pker")&&time()-me->query("pker_time")<1800)
 return notify_fail("��������ͨ��������ʱ�����˳���Ϸ��\n");
	if(environment(me)&&!environment(me)->query("exits"))
	return notify_fail("���ﲻ���˳���Ϸ��\n");
	if(!me->query_temp("suicide_countdown")&&!me->query_temp("netdead")){
		if(me->is_busy()) return notify_fail("( ����һ��������û����ɣ������˳���)\n");
	} 
	if( !wizardp(me) && environment(me) && environment(me)->query("no_quit") && link_ob ) return notify_fail("���ﲻ׼�˳���Ϸ��\n");

	where=environment(me);
	link_ob = me->query_temp("link_ob");
	
	// We might be called on a link_dead player, so check this.
	if( link_ob ){
	// Are we possessing in others body ?
		if( link_ob->is_character()){
			write("��Ļ��ǻص�" + link_ob->name(1) + "�����ϡ�\n");
			exec(link_ob, me);
			link_ob->setup();
			return 1;
		}
		link_ob->set("last_on", time());
		link_ob->set("last_from", query_ip_name(me));
		link_ob->save();
		destruct(link_ob);
	}
//    me->set("startroom",file_name(where));
	me->set_temp("quitting",1);
	write(YEL"\n����׼���뿪��Ϸ... ...\n\n"NOR);
	CHANNEL_D->do_channel(this_object(), "sys",me->name()  +"(" + me->query("id") + ")"+"׼���뿪��Ϸ�ˡ�");
	if(!wizardp(me))
	call_out("do_quit",8,me,link_ob);
	else{
	tell_object(me,"\n��Ϊ��ʦ�������Ѹ�����ߡ�\n\n");
	call_out("do_quit",1,me,link_ob);}
	return 1;
}

void do_quit(object me,object link_ob)
{
  
  object *inv;
  int i,j;
  
  if(!me) return;
  
  inv=all_inventory(me);
  if( !wizardp(me) && (!link_ob || (link_ob && !link_ob->is_character()))){
		
		
		for(i=0; i<sizeof(inv); i++){
		     if(inv[i]->unequip());
		   	if(!inv[i]->query_autoload())
			do_drop(me, inv[i]);}
	}

  j=JOBSYS_D->clear_job_npc(me);
  tell_object(me,HIW"\n\n�������ʹ�ù��û�����¼����ȷ�� Zmud ���Ƿ������ʺŵ����룬\n"+ 
                 HIR+"�Ա�������ʺű����˵��ã�\n"+NOR+
                 HIY+"��ӭ�´ι��٣��ټ�����\n\n"NOR); 
  message("system", me->name() + "�뿪��Ϸ��\n", environment(me), me);
  CHANNEL_D->do_channel(this_object(), "sys",me->name()  +"(" + me->query("id") + ")"+"�뿪��Ϸ�ˡ�");
  CHANNEL_D->do_channel(this_object(), "sys","����� "+j+" ���������\n");
  me->delete_temp("dtsl_job");
  
  if(me->query_temp("medicine_add_temp_force")){
    me->add("force",-me->query_temp("medicine_add_temp_force"));
    if(me->query("force")<0)
     me->set("force",0);
  }
  
  if(me->query_temp("medicine_add_temp_maxforce")){
    me->add("max_force",-me->query_temp("medicine_add_temp_maxforce"));
    if(me->query("max_force")<0)
     me->set("max_force",0);
  }
  
  me->save();
  destruct(me);
  return;
}

int do_drop(object me, object obj)
{
	if (obj->query("no_drop"))
	{
		destruct(obj);
		return 0;
	}
	if (obj->move(environment(me)))
	{
		if(obj->is_character()) message_vision("$N��$n�ӱ��Ϸ������������ڵ��ϡ�\n", me, obj);
		else 
		{
			message_vision( sprintf("$N����һ%s$n��\n", obj->query("unit")), me, obj );
			if( !obj->query("value") && !obj->value()&&!obj->is_character() )
			{
				tell_object(me,"��Ϊ������������ֵǮ���������ǲ�����ע�⵽���Ĵ��ڡ�\n");
				destruct(obj);
			}
		}
		return 1;
	}
	return 0;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : quit

������Ҫ��ʱ�˳���Ϸʱ�������ô�һָ�
HELP);
	return 1;
}
