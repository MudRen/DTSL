// jobnpc.c
//for jobs.

#include <command.h>
inherit CHARACTER;
inherit F_CLEAN_UP;

object carry_object(string file)
{
        object ob;

        if(!objectp(ob = new(file))) return 0;
        ob->move(this_object());
        return ob;
}

object add_money(string type, int amount)
{
        object ob;

        ob = carry_object("/obj/money/" + type);
        if(!ob) return 0;
        ob->set_amount(amount);
}

int accept_fight(object who)
{
        string att;

        att = query("attitude");

        if(is_fighting()){       
                switch(att) 
                {
                case "heroism":
                        command("say �ߣ����аɣ�\n");
                        break;
                default:
                        command("say ���ж�Ϊʤ���ⲻ������̫����\n");
                        return 0;
        }}

        if((int)query("gin") * 100 / (int)query("max_gin") >= 90
        && (int)query("kee") * 100 / (int)query("max_kee") >= 90)
        {
                switch(att) 
                {
                case "friendly":
                        command("say " + RANK_D->query_self(this_object())
                                + "���������" + RANK_D->query_respect(who)
                                + "�Ķ��֣�\n");
                                return 0;
                case "aggressive":
                case "killer":
                        command("say �ߣ����аɣ�\n");
                        break;
                default:
                        if(!is_fighting())
                                command("say ��Ȼ" + RANK_D->query_respect(who)
                                        + "�ͽ̣�" + RANK_D->query_self(this_object())
                                        + "ֻ�÷��㡣\n");
                }
                return 1;
        } else
                return 0;
}

// This function is called by the reset() of the room that creates this
// npc. When this function is called, it means the room demand the npc
// to return its startroom.
int return_home(object home)
{
        // Are we at home already?
        if(!environment()
        || environment() == home)
                return 1;

        // Are we able to leave?
        if(!living(this_object())
        || is_fighting()
        || !mapp(environment()->query("exits"))) 
                return 0;

        // Leave for home now.
        message("vision", this_object()->name() + "����ææ���뿪�ˡ�\n",
                environment(), this_object());
        return move(home);
}

// This is the chat function dispatcher. If you use function type chat
// message, you can either define your own functions or use the default
// ones.
int chat()
{
        string *msg,*pfm;
        int chance, rnd;

        if(!environment()) return 0;
		if(query("force")>=20&&query("max_force")>=20
			&&(query("race")=="����"||!query("race"))&&!is_busy()
			&&query_skill("force",1)
			&&!query_skill("bencao-shuli",1))
		{
			if(query("eff_sen")>0&&query("sen")*100/query("eff_sen")<=50)
				command("exert shen");
			if(query("eff_kee")>0&&query("kee")*100/query("eff_kee")<=50)
				command("exert qi");
			if(query("eff_gin")>0&&query("gin")*100/query("eff_gin")<=50)
			        command("exert jing");
		}
		if(query("force")>=20&&query("max_force")>=20
			&&(query("race")=="����"||!query("race"))&&!is_busy()
			&&query_skill("force",1)
			&&query_skill("bencao-shuli",1)&&!is_fighting())
		{
		    if(query("eff_gin")<query("max_gin")||
		       query("eff_kee")<query("max_kee"))
		       command("exert heal");
		}
		
		pfm=query("can_perform");
		if(query("combat_exp")>=800000&&is_fighting()&&random(100)>query("pfm_rate")
      			&&arrayp(pfm)){
     		set("apply_points",250);
     		command("perform "+pfm[random(sizeof(pfm))]);
     		return 1;
   		}

        if(!chance = (int)query(is_fighting()? "chat_chance_combat": "chat_chance"))
                return 0;

        if(arrayp(msg = query(is_fighting()? "chat_msg_combat": "chat_msg"))) 
        {
                if(random(100) < chance) 
                {
                        rnd = random(sizeof(msg));
                        if(stringp(msg[rnd]))
                                say(msg[rnd]);
                        else if(functionp(msg[rnd]))
                                return evaluate(msg[rnd]);
                }
                return 1;
        }
}

// Default chat function: Let the npc random move to another room.
int random_move()
{
        mapping exits;
        string *dirs;

        if(!mapp(exits = environment()->query("exits"))) return 0;
        dirs = keys(exits);
        command("go " + dirs[random(sizeof(dirs))]);
}

// Default chat function: Let the npc cast his/her enabled spells

int exert_function(string func)
{
     if(!living(this_object())) //not living Npc can't fight. Modify by Yanyan.
      return 0;
     command("exert "+func);
     return 1;
}


int perform_action(string action)
{
     if(!living(this_object()))
      return 0;
     command("perform "+action);
     return 1;
}

int apply_action(string arg,int i,string j)  //for apply commands.
{
	if(!living(this_object()))
      return 0;
	command("apply "+arg+" "+i+" "+j+"");
      return 1;
}

mapping *middle_skills=({
 ([
    "skill":"moxin-lianhuan",
    "base":"strike",
    "weapon":0,
    "perform_quest":0,
 ]),
 ([
    "skill":"linglong-yuquan",
    "base":"cuff",
    "weapon":0,
    "perform_quest":0,
 ]),
 ([
    "skill":"tiangang-quan",
    "base":"cuff",
    "weapon":0,
    "perform_quest":0,
 ]),
 ([
    "skill":"dujie-zhi",
    "base":"finger",
    "weapon":0,
    "perform_quest":0,
 ]),
 ([
    "skill":"rulai-shenzhang",
    "base":"strike",
    "weapon":0,
    "perform_quest":0,
 ]),
 ([
    "skill":"fumo-zhangfa",
    "base":"staff",
    "weapon":"staff",
    "perform_quest":0,
 ]),
 ([
    "skill":"tiandao-bajue",
    "base":"blade",
    "weapon":"blade",
    "perform_quest":0,
 ]),
 ([
    "skill":"dijian-jue",
    "base":"sword",
    "weapon":"sword",
    "perform_quest":0,
 ]),
 ([
    "skill":"shuiyun-xiufa",
    "base":"whip",
    "weapon":"whip",
    "perform_quest":0,
 ]),
 ([
    "skill":"leiting-chuifa",
    "base":"hammer",
    "weapon":"hammer",
    "perform_quest":0,
 ]),
 ([
    "skill":"piaomeng-jianfa",
    "base":"sword",
    "weapon":"sword",
    "perform_quest":0,
 ]),
 ([
    "skill":"zhehua-baishi",
    "base":"blade",
    "weapon":"blade",
    "perform_quest":0,
 ]),
 ([
    "skill":"sekong-jianfa",
    "base":"sword",
    "weapon":"sword",
    "perform_quest":0,
 ]),
 ([
    "skill":"jiuzhuan-jianjue",
    "base":"sword",
    "weapon":"sword",
    "perform_quest":0,
 ]),
 ([
    "skill":"wuba-daofa",
    "base":"blade",
    "weapon":"blade",
    "perform_quest":0,
 ]),
 ([
    "skill":"fuying-spear",
    "base":"spear",
    "weapon":"spear",
    "perform_quest":0,
 ]),
 ([
    "skill":"kuangsha-daofa",
    "base":"blade",
    "weapon":"blade",
    "perform_quest":0,
 ]),
 ([
    "skill":"feiwo-whip",
    "base":"whip",
    "weapon":"whip",
    "perform_quest":0,
 ]),
 
});

mapping *high_skills=({
 ([
    "skill":"qianbian-tongxiao",
    "base":"sword",
    "weapon":"sword",
    "perform_quest":"perform_quest/wanhuan",
 ]),
 ([
    "skill":"tianmo-zhan",
    "base":"dagger",
    "weapon":"dagger",
    "perform_quest":"perform_quest/lingxiao",
 ]),
 ([
    "skill":"tianmo-dai",
    "base":"whip",
    "weapon":"whip",
    "perform_quest":"perform_quest/yulong",
 ]),
 ([
    "skill":"tiangang-quan",
    "base":"cuff",
    "weapon":0,
    "perform_quest":"perform_quest/tiangang",
 ]),
 ([
    "skill":"dujie-zhi",
    "base":"finger",
    "weapon":0,
    "perform_quest":"perform_quest/liudao",
 ]),
 ([
    "skill":"rulai-shenzhang",
    "base":"strike",
    "weapon":0,
    "perform_quest":"perform_quest/pudu",
 ]),
 ([
    "skill":"fumo-zhangfa",
    "base":"staff",
    "weapon":"staff",
    "perform_quest":"perform_quest/fumo",
 ]),
 ([
    "skill":"tiandao-bajue",
    "base":"blade",
    "weapon":"blade",
    "perform_quest":"perform_quest/bajue",
 ]),
 ([
    "skill":"dijian-jue",
    "base":"sword",
    "weapon":"sword",
    "perform_quest":"perform_quest/ditian",
 ]),
 ([
    "skill":"shuiyun-xiufa",
    "base":"whip",
    "weapon":"whip",
    "perform_quest":"perform_quest/yanyu",
 ]),
 ([
    "skill":"leiting-chuifa",
    "base":"hammer",
    "weapon":"hammer",
    "perform_quest":"perform_quest/pili",
 ]),
 ([
    "skill":"piaomeng-jianfa",
    "base":"sword",
    "weapon":"sword",
    "perform_quest":"perform_quest/duomeng",
 ]),
 ([
    "skill":"zhehua-baishi",
    "base":"blade",
    "weapon":"blade",
    "perform_quest":"perform_quest/zhi",
 ]),
 ([
    "skill":"sekong-jianfa",
    "base":"sword",
    "weapon":"sword",
    "perform_quest":"perform_quest/zhi",
 ]),
 ([
    "skill":"jiuzhuan-jianjue",
    "base":"sword",
    "weapon":"sword",
    "perform_quest":"perform_quest/xingchen",
 ]),
 ([
    "skill":"wuba-daofa",
    "base":"blade",
    "weapon":"blade",
    "perform_quest":"perform_quest/sanfen",
 ]),
 ([
    "skill":"fuying-spear",
    "base":"spear",
    "weapon":"spear",
    "perform_quest":"perform_quest/fengyu",
 ]),
 ([
    "skill":"kuangsha-daofa",
    "base":"blade",
    "weapon":"blade",
    "perform_quest":"perform_quest/kuangsha",
 ]),
 ([
    "skill":"feiwo-whip",
    "base":"whip",
    "weapon":"whip",
    "perform_quest":"perform_quest/duo",
 ]),
 
});

mapping *low_skills=({
 ([
    "skill":"tianmo-jianfa",
    "base":"sword",
    "weapon":"sword",
    "perform_quest":0,
 ]),
 ([
    "skill":"jiutian-huanzhang",
    "base":"strike",
    "weapon":0,
    "perform_quest":0,
 ]),
 ([
    "skill":"luohan-quan",
    "base":"cuff",
    "weapon":0,
    "perform_quest":0,
 ]),
 ([
    "skill":"fengxue-leg",
    "base":"leg",
    "weapon":0,
    "perform_quest":0,
 ]),

});

string *dodge_skills=({
"liuyun","tianmo-huanzong","anxiang-fuying","nishang-piaoming",
"luohua-step","lingyun-shenfa","xingyun-dodge","youlong-shenfa",
});
string *force_skills=({
"wuxiang-shengong","tianmo-dafa","tiangang-sanjue","bihai-force",
"flower-force","qingxin-force","jiuxuan-dafa","yanyang-dafa",
"huachan","wuwang-jing","tianmo-jue","bikouchan",
"wangdao-jue","canglang-jue","dongming-xinfa","yijian-shu",
});

void setDAD(int damage,int armor,int dodge)
{
string msg;
	
add_temp("apply/damage",damage);
add_temp("apply/parry",armor);
add_temp("apply/dodge",dodge);

msg = "";
if(damage>0)
	msg = msg+"�������书����\n";
if(armor>0)
	msg = msg+"�������мܺ�ǿ\n";
if(dodge>0)
	msg = msg+"��������ʮ�����\n";
	
set("long",query("long")+msg);

add_temp("expand_exp",(damage+armor+dodge)/5);	
	
}

void setOtherAttack(int t_force,int t_applypoints,int t_busy)
{
string msg;
	
set("otherattack_t_force",t_force);//���е��˵�����	
set("otherattack_t_applypoints",t_applypoints);//������	
set("otherattack_t_busy",t_busy);//æ

msg = "";
if(t_force>0)
	msg = msg+"��������һ������ȡ�����������书\n";
if(t_applypoints>0)
	msg = msg+"��������һ������ȡ�������Ƶ��书\n";
if(t_busy>0)
	msg = msg+"��������һЩ��Ѩ�Ĺ���\n";
	
set("long",query("long")+msg);

add_temp("expand_exp",(t_force+t_applypoints)/8);
add_temp("expand_exp",t_busy*100);	
	
}

void die()
{
object target;

target = query_temp("last_damage_from");
if(!target){
	::die();
	return;
}

target->add("combat_exp",query_temp("expand_exp"));

tell_object(target,"\n��õ��� "+chinese_number(query_temp("expand_exp"))+" �㾭�飡\n\n");

::die();
	
}

void hit_ob(object me,object victim)
{
if(random(10)<5)
	return;

if(query("otherattack_t_force")){
	victim->add("force",-query("otherattack_t_force"));
	if(victim->query("force")<0)
		victim->set("force",0);
}

if(query("otherattack_t_applypoints")){
	victim->add("apply_points",-query("otherattack_t_applypoints"));
	if(victim->query("apply_points")<0)
		victim->set("apply_points",0);
}

if(query("otherattack_t_busy"))
	victim->start_busy(random(3));	
	
}

void set_this_factor(string arg)
{
int i;

if(arg=="low")
	return;
	
i = random(100);

if(arg=="middle"){
	
	if(i<=40)
		return;
	else
	if(i<=60)
		setDAD(0,100+random(100),0);
	else
	if(i<=80)
		setDAD(0,0,100+random(100));
	else
	if(i<=90)
		setDAD(100+random(100),0,0);
	else
		setDAD(100+random(50),100+random(50),100+random(50));
		
	return;
}

if(i<=40) 
	return;
			
if(i<=60)
	setDAD(0,100+random(100),100+random(100));
else
if(i<=70)
	setDAD(150+random(100),150+random(100),150+random(100));
else
if(i<=80)
	setOtherAttack(300+random(200),random(80),0);
else
if(i<=90){
	setDAD(150+random(200),150+random(100),150+random(100));
	setOtherAttack(300+random(200),random(80),0);
}
else
if(i<=95){
	setDAD(150+random(200),150+random(100),150+random(100));
	setOtherAttack(500+random(200),random(80),0);
}
else
if(i<=98){
	setDAD(200+random(200),200+random(100),150+random(100));
	setOtherAttack(500+random(200),random(80),0);
}
else{

	setOtherAttack(500+random(200),random(80),1);
}
		
}

int set_this_skills(string arg)
{
    int i;
    mapping skill;
    string *pfm;
    object weapon;
       
    set_skill("force",10);
    set_skill("dodge",10);
    set_skill("parry",10);
    
    for(i=0;i<sizeof(force_skills);i++)
    set_skill(force_skills[i],10); 
    
    set_skill(dodge_skills[random(sizeof(dodge_skills))],10);  
    
    if(arg=="low")
      skill=low_skills[random(sizeof(low_skills))];
    else
    if(arg=="middle")
      skill=middle_skills[random(sizeof(middle_skills))];
    else
      skill=high_skills[random(sizeof(high_skills))];
      
      pfm=SKILL_D(skill["skill"])->query_perform();
      
      set("can_perform",pfm);
      set("pfm_rate",95);
      set_skill(skill["skill"],10);
      set_skill(skill["base"],10);
      
      if(skill["weapon"]){
      	weapon=new("obj/weaponclass/"+skill["weapon"]);
      	if(weapon){
      	  weapon->move(this_object());
      	  weapon->wield();
      	}
      }
      if(skill["perform_quest"])
       set(skill["perform_quest"],1);
       
    
    set_this_factor(arg);
     
    return 1;
    
}

/*void relay_message(string msgclass, string msg)
{
	string *pfm;
	
	if(!query("rec")){
		set("rec",1);
		if(strsrch(msg,"�������˼�����")!=-1){
			pfm=query("can_perform");
			if(query("combat_exp")>=800000&&is_fighting()&&random(100)>80
      				&&arrayp(pfm)){
     			set("apply_points",250);
     			command("perform "+pfm[random(sizeof(pfm))]);
   			}
   		}
		delete("rec");
	}
}*/