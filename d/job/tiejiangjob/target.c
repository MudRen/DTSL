

#include <ansi.h>
#include <job_money.h>

inherit JOBNPC;

string _invocation(object who, int level);
int expeward, pot_reward;
int other_kee=0, other_sen=0;

string *dirs1 = ({
"/d/chengdu","/d/changan","/d/yangzhou","/d/luoyang","/d/xiangyang"
});

string *dirs2 = ({
"/d/suiye","/d/huashan","/d/emeishan","/d/hengshan"
});

string *dirs3 = ({
"/d/dabashan","/d/taishan","/d/taishan"  
});

int killer_type=0;

void _leave();
void leave();

void setname1()
{
	set_name("������",({ "mengmian ren","ren" }) );

	set("race", "����");
      set("gender", "����");
	killer_type=1;
}

void setname2()
{
    set("race", "����");
    set("gender","����");
    set_name("������",({ "mengmian ren","ren" }) );
    killer_type=2;
}


void create()
{
        if(random(2)==0)
	    setname1();
	else
	    setname2();

	set("chat_chance", 5);
	set("chat_msg", ({
	     (: random_move :)
	}) );

	set("chat_chance_combat", 5);

	set("age", 20+random(80));
	set("combat_exp", 3000);
	set_skill("unarmed", 10);
	set_skill("dodge", 10);
	set_temp("apply/armor",10+random(5));
	
	
        setup();
}

void _leave()
{
    object me=this_object();
    
    // if in fighting, then don't disappear.
    if(me->is_fighting() || me->is_busy())
	return;
    leave();
}

void leave()
{
      if(this_object()) { 
        if(environment())
          message("vision",HIB + name() + 
		  "����һ�����ټ�������\n" NOR,environment());
        destruct(this_object());
      }
      return;
}

string invocation(object who, int level)
{
        int exp;
        object me=this_object();
        
        exp=who->query("combat_exp");
        
	if(exp<150000){
         set_this_skills("low");
         me->set("combat_exp",who->query("combat_exp")/3);
         set_all_skill(me,who->query("max_pot")/3); 
         copy_hp_item(who,me,"kee",1/2); //copy ��Ѫ
         copy_hp_item(who,me,"gin",1/2); //copy ��Ѫ
         copy_hp_item(who,me,"sen",1/2); //copy ����
        }
        else
        if(exp<500000){
         set_this_skills("middle");
         me->set("combat_exp",who->query("combat_exp")/3);
         set_all_skill(me,who->query("max_pot")/3); 
         copy_hp_item(who,me,"kee",1/2); //copy ��Ѫ
         copy_hp_item(who,me,"gin",1/2); //copy ��Ѫ
         copy_hp_item(who,me,"sen",1/2); //copy ����
        }
        else
        if(exp<1000000){
         set_this_skills("high");
         me->set("combat_exp",who->query("combat_exp")/3);
         set_all_skill(me,who->query("max_pot")/3); 
         copy_hp_item(who,me,"kee",1/2); //copy ��Ѫ
         copy_hp_item(who,me,"gin",1/2); //copy ��Ѫ
         copy_hp_item(who,me,"sen",1/2); //copy ����
        }
        else{
         set_this_skills("high");
         me->set("combat_exp",who->query("combat_exp")/3);
         set_all_skill(me,who->query("max_pot")/3); 
         copy_hp_item(who,me,"kee",1/2); //copy ��Ѫ
         copy_hp_item(who,me,"gin",1/2); //copy ��Ѫ
         copy_hp_item(who,me,"sen",1/2); //copy ����
        }
        
        me->set("max_force",who->query("max_force")/3);//ɱ�������������Ĵ�������
        me->set("force",who->query("max_force")/3);
        
        me->set("target_id",who->query("id"));//ֻ�������������ɱ��������ɱ���ˡ�
        me->set("difficult",level*8);//ɱ�ֳ�perform�ĸ��ʡ�
	
	return _invocation(who, level);
}

string _invocation(object who, int level)
{       
	
	object me=this_object(), env;
        string *dirs; 
        int exp, i, lvl;
	string where, long, killer_name;
	
	dirs=dirs1;
         
       
        set("owner", who->query("id"));
        set("owner_ob", who);

	if(killer_type==1) {
        long="һλ"+name()+"��ר����������ˡ���";
        if(random(2)==0) {
	  set("long",long+"ͨ��͸��һ��ɱ����\n");
        } else {
	  set("long",long+"��������ɱ�����ˡ�\n");
        }
	} else if(killer_type==2) {
	    int dx=query("combat_exp");
	    long="һλ"+query("name")+"����һ����գ������õı����Ͳ�ϧ���۵ĵõ���\n";
            set("long",long);
	    
	}

	lvl=level;
	
	// choose npc type.
	i=random(1000);
	if(i<10) {
	    set("type","aggressive");
	} else if(i<20) {
	    set("type","blocker");
	} else if(i<220) {
	    set("type","aggressive_on_owner");
	} else 
	    set("type","normal");
	
	if(random(10)==0) {
	    set("env/wimpy",40);
	    if(lvl<9) lvl=lvl+1; // as more difficult to kill.
	} else {
	    set("env/wimpy",1);
	}

	// determine reward
		
	if(exp<1000000) {
	  
	    dirs=dirs1;
//+dirs2;
	} else if(exp<3000000) {
	    dirs=dirs+dirs2;
	} else {
	    dirs=dirs+dirs2+dirs3;
	}

	
	me->set("stay_time", time()+1800);
		
	if(!random_place(me, dirs)) {
	    leave();
	    return 0;
	}
	
	env=environment(me);
	killer_name=me->query("name")+"("+me->query("id")+")";
	where=killer_name;
	if(env)
	    where +="��"+MISC_D->find_place(env);
	return where;
}

void check_room()
{
    object me=this_object();
    object env=environment(me);
    
    if(!living(me)) return;
    if(env && (env->query("no_fight") ||
               env->query("sleep_room")||env->query("no_select")||
		env->query("no_exert"))) {
	random_move();
    }
}

void init()
{
    object me=this_object();
    object who=this_player();
    string type;
    int t=query("stay_time");

    ::init();
    
    if(t && time()>t) {
	remove_call_out("_leave");
	call_out("_leave",300);
    }
    
    if(!userp(this_player())) return;
    if(!living(this_object())) return;
    
    type=query("type");
    switch (type) {
	case "aggressive": {
	    object leader=query_leader();
	    int exp, myexp;
	    if(leader && present(leader, environment(me))) {
		if(!is_fighting()) kill_ob(leader);
		break;
	    }
	    exp=(who->query("combat_exp"))/3;
	    myexp=(query("combat_exp"))/3;
	    if(exp>myexp*3 || exp<myexp)
		break;
            if(query("owner")==this_player()->
		    query("id")){
	      set_leader(who);
	      message_vision("$N����$n�����������ĺ���Ц�����ٺ٣�����\n",
		    this_object(), who);
	      kill_ob(who);
	    }
	    break;
	}
	case "aggressive_on_owner":
	    if(query("owner")==this_player()->
		    query("id")) {
		message_vision("$N����$n�����һ�������ڱ��˷����ˣ���Ҫɱ����ڣ���\n",
			this_object(), who);
		kill_ob(this_player());
		this_player()->kill_ob(this_object());
	    }
	    break;
	case "blocker": {
//            add_action("do_block","",1);
	    break;
	}
    }
    remove_call_out("check_room");
    call_out("check_room",2);
}

int do_block(string arg)
{
    object me=this_object();
    object who=this_player();
    string verb=query_verb();
    
    if(wizardp(who) && !visible(who)) return 0;
    if(me->is_fighting()) return 0;

    if(verb!="go" &&
	    !(environment() && environment()->query("exits/" + verb)))
	return 0;

    
    tell_object(who,me->name()+"һ��ץס���㣡\n");
    return 1;
}


void die()
{
        object killer;
        object me=this_object();
        killer=query_temp("last_damage_from");//�õ���ǰɱ�������˵������
        
        if(!killer) return ::die();
                
        if(killer->query("id")!=query("target_id"))//���Ƿ������������
         return ::die();
	    killer->set_temp("tiejobkiller",1);
          killer->delete_temp("tiejobkiller_come");
         // tell_object(killer,"\nhere is ok!\n"); ������䡣��Ϊ����ʱ��
         //�ǲ����������--Yanyan         
          return ::die();
//   	destruct(this_object());

}

