
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

string *names1 = ({
  WHT"��"NOR,"chen",
  WHT"��"NOR,"du",
  WHT"��"NOR,"li",
  WHT"��"NOR,"zhang",
  WHT"��"NOR,"wang",
  WHT"��"NOR,"he",
  WHT"ŷ"NOR,"ou",
  WHT"��"NOR,"zhou",
  WHT"��"NOR,"hu",
  WHT"��"NOR,"ma",
  WHT"��"NOR,"mai",
  WHT"ʷ"NOR,"shi",
  WHT"��"NOR,"liao",
  WHT"��"NOR,"lin",
  WHT"��"NOR,"bai",
  WHT"��"NOR,"cai",
  WHT"��"NOR,"jin",
  WHT"��"NOR,"chao",
  WHT"¬"NOR,"lu",
  WHT"��"NOR,"wu",
  WHT"��"NOR,"huang",
  WHT"��"NOR,"yan",
});

string *names2 = ({
  WHT"��"NOR,"xiao",
  WHT"ΰ"NOR,"wei",
  WHT"��"NOR,"wen",
  WHT"��"NOR,"fu",
  WHT"��"NOR,"xiong",
  WHT"��"NOR,"chang",
  WHT"��"NOR,"yi",
  WHT"��"NOR,"wei",
  WHT"��"NOR,"jian",
  WHT"��"NOR,"jun",
  WHT"��"NOR,"ji",
  WHT"��"NOR,"song",
  WHT"ҵ"NOR,"ye",
  WHT"��"NOR,"hui",
  WHT"��"NOR,"chuan",
  WHT"ʯ"NOR,"shi",
  WHT"��"NOR,"bai",
  WHT"��"NOR,"zhen",
});

string *names3 = ({
  YEL"��"NOR,"feng",
  YEL"��"NOR,"fei",
  YEL"��"NOR,"liang",
  YEL"��"NOR,"hui",
  YEL"��"NOR,"rong",
  YEL"��"NOR,"yang",
  YEL"��"NOR,"kun",
  YEL"��"NOR,"wei",
  YEL"��"NOR,"yu",
  YEL"��"NOR,"zhou",
  YEL"��"NOR,"fa",
  YEL"��"NOR,"dong",
  YEL"Ȼ"NOR,"ran",
  YEL"ƽ"NOR,"ping",
  YEL"��"NOR,"ling",
  YEL"��"NOR,"jiang",
  YEL"��"NOR,"ren",
  YEL"Ƚ"NOR,"ran",
  YEL"ׯ"NOR,"zhuang",
  YEL"ҵ"NOR,"ye",
});

string *names4 = ({
	WHT"ŷ��"NOR,"ouyang",
	WHT"�Ϲ�"NOR,"shangguan",
	WHT"����"NOR,"yuwen",
	WHT"����"NOR,"tengtang",
	WHT"����"NOR,"jingshang",
	WHT"�ɵ�"NOR,"songdao",
	WHT"��ľ"NOR,"duanmu",
	WHT"ľ��"NOR,"muchuan",
	WHT"ӣľ"NOR,"yingmu",
	WHT"����"NOR,"liuchuan",
	WHT"Ԫ��"NOR,"yuanyan",
	WHT"˾ͽ"NOR,"situ",
	WHT"ʮ����"NOR,"shiwenzi",
	WHT"�ñ�"NOR,"tangben",
	WHT"ʸ��"NOR,"shichui",
	WHT"�ݳ�"NOR,"caochu",
	WHT"����Ŀ"NOR,"erbenmu",
	WHT"����"NOR,"jichuan",
	WHT"��Ŀ"NOR,"chimu",
	WHT"����"NOR,"jiashen",
	WHT"ɽ��"NOR,"shanqi",
	WHT"����"NOR,"longtang",
});

int killer_type=0;

void _leave();
void leave();

void setname1()
{
        int i,j,k;
	string name, *id;

	i=(random(sizeof(names1)/3))*2;
	j=(random(sizeof(names2)/3))*2;
	k=(random(sizeof(names3)/3))*2;

	name=names1[i]+names2[j]+names3[k];
	id=({names1[i+1]+" "+names2[j+1]+names3[k+1], names1[i+1]});

	set_name(name,id);

	set("race", "����");
      set("gender", "����");
	killer_type=1;
}

void setname2()
{
    int i, j;
    string name, *id;
    i=(random(sizeof(names4)/3))*2;
    j=random(2);
 name=names4[i]+(j?YEL"����"NOR:YEL"��ʿ"NOR);
    id=({names4[i+1]+" "+(j?"xingzhe":"yinshi"),
	    (j?"xingzhe":"yinshi")});    
// name=names4[i]+(j?YEL"��"NOR:YEL"����"NOR:YEL"��"NOR:YEL"����"NOR:YEL"С����"NOR:YEL"�Ҷ�"NOR:YEL"����"NOR:YEL"����"NOR:YEL"��"NOR:YEL"����"NOR:YEL"�޵�"NOR:YEL"��һ"NOR:YEL"ǧ��"NOR:YEL"ȴ��"NOR:YEL"��"NOR:YEL"ǧ��"NOR:YEL"��"NOR:YEL"ҫ"NOR);
// id=({names4[i+1]+" "+(j?"long":"zhenwu":"jing":"cangyue":"xiaocilang":"xinger":"chaizhou":"guanxian":"lei":"huaji":"wudi":"guangyi":"qianzhou":"queda":"ren":"qianhe":"yan":"yao"),
//	    (j?"long":"zhenwu":"jing":"cangyue":"xiaocilang":"xinger":"chaizhou":"guanxian":"lei":"huaji":"wudi":"guangyi":"qianzhou":"queda":"ren":"qianhe":"yan":"yao")});

    set("race", "����");
    set("gender","����");
    set_name(name,id);
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
	set_temp("apply/armor",5+random(5));
	
	
	
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
         copy_hp_item(who,me,"kee",1,2); //copy ��Ѫ
         copy_hp_item(who,me,"gin",1,2); //copy ��Ѫ
         copy_hp_item(who,me,"sen",1,2); //copy ����
        }
        else
        if(exp<500000){
         set_this_skills("middle");
         me->set("combat_exp",who->query("combat_exp")/3);
         set_all_skill(me,who->query("max_pot")/3); 
         copy_hp_item(who,me,"kee",1,2); //copy ��Ѫ
         copy_hp_item(who,me,"gin",1,2); //copy ��Ѫ
         copy_hp_item(who,me,"sen",1,2); //copy ����
        }
        else
        if(exp<1000000){
         set_this_skills("high");
         me->set("combat_exp",who->query("combat_exp")/3);
         set_all_skill(me,who->query("max_pot")/3); 
         copy_hp_item(who,me,"kee",1,2); //copy ��Ѫ
         copy_hp_item(who,me,"gin",1,2); //copy ��Ѫ
         copy_hp_item(who,me,"sen",1,2); //copy ����
         set("jiali",1);
        }
        else{
         set_this_skills("high");
         me->set("combat_exp",who->query("combat_exp")/3);
         set_all_skill(me,who->query("max_pot")/3); 
         copy_hp_item(who,me,"kee",1,2); //copy ��Ѫ
         copy_hp_item(who,me,"gin",1,2); //copy ��Ѫ
         copy_hp_item(who,me,"sen",1,2); //copy ����
         set("jiali",2);
        }
               
        me->set("max_force",who->query("max_force")/3);//ɱ�������������Ĵ�������
        me->set("force",who->query("max_force")/3);
        
        me->set("target_id",who->query("id"));//ֻ�������������ɱ��������ɱ���ˡ�
        me->set("pfm_rate",60+level*2);//ɱ�ֳ�perform�ĸ��ʡ�
      me->delete("perform_quest");
	
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
        long="һλ"+name()+"����׷ɱ����"+
	  chinese_number((query("combat_exp")/1000/10)*10>60?60:
	  (query("combat_exp")/1000/10)*10)+
	  "����ˡ���";
        if(random(2)==0) {
	  set("long",long+"ͨ��͸��һ��ɱ����\n");
        } else {
	  set("long",long+"��������ɱ�����ˡ�\n");
        }
	} else if(killer_type==2) {
	    int dx=query("combat_exp");
	    long="һλ"+query("name")+
		"����"+({"��ɽ��","������","Ұ��",
			"��ԭ��","Ұ����","��ɽ��",
			"ç����","çԭ��","�����",
			})[random(9)]+
	        "�����"+({"�ܳ�","һ��","һ�γ�"})[random(3)]+
		    "ʱ�䣬�������ڱ��˷��֡�\n";
            set("long",long);
	    
	    if(dx>=10000000)
		long=HBYEL HIW" ħ ͷ "NOR;
	    else if(dx>=1000000)
		long=HBRED HIW" ǿ �� "NOR;
	    else if(dx>=100000)
		long=HBBLU HIW" �� �� "NOR;
	    else if(dx>10000)
		long=HIR"�� ʿ"NOR;
	    else
		long=HIY"�� å"NOR;
	    
	    set("title",long);
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

int accept_object (object who, object ob)
{
  object me;
  me = this_object();

  if ((! ob) ||
       ob->value() < 100000)
  {
    message_vision ("$Nһ���ۣ�����㶫����������ˣ�����\n", me);
    return 1;
  }
  who->set_temp("cisha/allow_to_go", 1);
  message_vision ("$N�ٺٺټ�����Ц���������ˣ������"
	  +"�ɱ������ٿ����㣡\n",me);
  return 1;
}

void check_room()
{
    object me=this_object();
    object env=environment(me);
    
    if(!living(me)) return;
    if(env && (env->query("no_fight") ||
               env->query("sleep_room")||
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
	   // add_action("do_block","",1);
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
    int t;
    
    if(wizardp(who) && !visible(who)) return 0;
    if(me->is_fighting()) return 0;

    if(verb!="go" &&
	    !(environment() && environment()->query("exits/" + verb)))
	return 0;

    if(who->query_temp("cisha/allow_to_go")) {
	who->delete_temp("cisha/allow_to_go");
	who->delete_temp("cisha/leave_time");
	return 0;
    }
    t=who->query_temp("cisha/leave_time");
    if(t>0 && time()>t) {
	who->delete_temp("cisha/leave_time");
	message_vision("$n��$Nһ����ע�⣬��æ���˹�ȥ��\n",me,who);
	return 0;
    }
    if(t==0) {
        t=time()+30+random(90);
        who->set_temp("cisha/leave_time",t);
	message_vision("$N�͵�����������$n��ǰ�������е���\n"+
		"          ��ɽ���ҿ������������ԣ�\n"+
		"          Ҫ���·����������·�ƣ�\n\n",me,who);
    } 
    
    tell_object(who,me->name()+"һ��ץס���㣡\n");
    return 1;
}


void die()
{
        object killer;
       

        killer=query_temp("last_damage_from");//�õ���ǰɱ�������˵������
        
        if(!killer) return ::die();
        
        if(killer->query("id")!=query("target_id"))//���Ƿ������������
         return ::die();
        
        JOBSYS_D->give_reward_killerjob(killer);
                      
        killer->delete_temp("cisha/name");
        killer->delete_temp("cisha/ob");
        killer->delete_temp("dtsl_job");
        killer->set("busy_time",time());
        return ::die();
}

