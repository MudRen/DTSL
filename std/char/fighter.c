//fighter.c
// for fight job
//Create By Yanyan For DT

#include <command.h>
#include <job_money.h>
#include <ansi.h>

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
     if(query("target_id")!=who->query("id"))
     return 0;
     if(sizeof(who->query_enemy())>=4)
     return 0;
     return 1;
}


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

// set_status do the Initialize of the npc

int set_status(object ob)
{
   set("target_id",ob->query("id"));
   if(ob->query("combat_exp")<100000){
     set("combat_exp",ob->query("combat_exp")-1000);
     if(query("combat_exp")<0)
     set("combat_exp",random(1000));
     copy_hp_item(ob,this_object(),"gin",2);
     copy_hp_item(ob,this_object(),"kee",2);
     copy_hp_item(ob,this_object(),"sen",2);
     set("max_force",ob->query("max_force")*3/2);
     set("force",ob->query("max_force")*3/2);
     set_all_skill(this_object(),ob->query("max_pot")-130<=0?50:ob->query("max_pot")-130);
     set("target_lev","low");
     set("eff_times",20);
     
     set("reward_exp",10+random(10));
     set("reward_pot",5+random(10));
   }
   else
   if(ob->query("combat_exp")<150000){
     set("combat_exp",ob->query("combat_exp")-500);
     copy_hp_item(ob,this_object(),"gin",2);
     copy_hp_item(ob,this_object(),"kee",2);
     copy_hp_item(ob,this_object(),"sen",2);
     set("max_force",ob->query("max_force")*3/2);
     set("force",ob->query("max_force")*3/2);
     set_all_skill(this_object(),ob->query("max_pot")-130<=0?100:ob->query("max_pot")-130);
     set("target_lev","mid");
     set("eff_times",30);
     
     set("reward_exp",15+random(10));
     set("reward_pot",8+random(10));
   }
   else{
     set("combat_exp",ob->query("combat_exp"));
     copy_hp_item(ob,this_object(),"gin",2);
     copy_hp_item(ob,this_object(),"kee",2);
     copy_hp_item(ob,this_object(),"sen",2);
     set("max_force",ob->query("max_force")*3/2);
     set("force",ob->query("max_force")*3/2);
     set_all_skill(this_object(),ob->query("max_pot")-120<=0?100:ob->query("max_pot")-120);
     set("target_lev","high");
     set("eff_times",30);
     
     set("reward_exp",20+random(10));
     set("reward_pot",10+random(10));
   }
   set("target_ob",ob);
   set("reward_p",50);
   //set_leader(ob);
   ob->add_temp_array("job_temp_killer",this_object());
   
   return 1;
}

int is_end_fight(object ob)
{
  
  return 1;
}

int end_fight(object killer,object victim)
{
  
  add("eff_times",-1);
  if(query("eff_times")<=0){
    message_vision("\nֻ������һ����$N�Ѿ���ɷ�ĩ�ˣ�\n",this_object());
    destruct(this_object());
  }
  set("kee",query("max_kee"));
  set("eff_kee",query("max_kee"));
  
  set("gin",query("max_gin"));
  set("eff_gin",query("max_gin"));
  
  set("sen",query("max_sen"));
  set("eff_sen",query("max_sen"));
  
  set("force",query("max_force"));
 
  return 1;
}

int surrender(object killer,object victim)
{
  
  add("eff_times",-1);
  if(query("eff_times")<=0){
    message_vision("\nֻ������һ����$N�Ѿ���ɷ�ĩ�ˣ�\n",this_object());
    destruct(this_object());
  }
  set("kee",query("max_kee"));
  set("eff_kee",query("max_kee"));
  
  set("gin",query("max_gin"));
  set("eff_gin",query("max_gin"));
  
  set("sen",query("max_sen"));
  set("eff_sen",query("max_sen"));
  
  set("force",query("max_force"));
 
  return 1;
}

void die()
{
   
    message_vision("\nֻ������һ����$N�Ѿ���ɷ�ĩ�ˣ�\n",this_object());
    destruct(this_object());
   
   return;
}
// This is the chat function dispatcher. If you use function type chat
// message, you can either define your own functions or use the default
// ones.

//Kill ob

void kill_ob(object ob)
{
   message_vision("\nֻ����֨������$N��ʼ��$n����������\n",this_object(),ob);
   return ::kill_ob(ob);
}

int chat()
{
        string *msg;
        int chance, rnd;
        object target;

        if(!environment()) return 0;
               
		if(query("force")>=20&&query("max_force")>=20
			&&(query("race")=="����"||!query("race"))&&!is_busy()
			&&query_skill("force",1)
			&&!query_skill("bencao-shuli",1))
		{
			if(query("eff_sen")>0&&query("sen")*100/query("eff_sen")<=60)
				command("exert shen");
			if(query("eff_kee")>0&&query("kee")*100/query("eff_kee")<=60)
				command("exert qi");
			if(query("eff_gin")>0&&query("gin")*100/query("eff_gin")<=60)
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
	
	if(objectp(target=query_temp("last_damage_from"))
	 &&this_object()->is_fighting(target)
	 &&(query("target_lev")=="mid"||query("target_lev")=="high")
	 &&random(100)>70){
	  if(query("target_lev")=="high"&&random(100)>30)
	   command("perform suimu");
	  else
	  command("apply muren-skill "+(random(4)+1)+" "+(random(10)+1));
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
void cast_spell(string spell)
{
        string spell_skill;

        if(stringp(spell_skill = query_skill_mapped("spells")))
                SKILL_D(spell_skill)->cast_spell(this_object(), spell);
}


int exert_function(string func)
{
     if(!living(this_object())) //not living Npc can't fight. Modify by Yanyan.
      return 0;
     SKILL_D("force")->exert_function(this_object(), func);
}


int perform_action(string action)
{
     string martial_skill;object weapon;
     if(!living(this_object()))
      return 0;
     if(time()-this_object()->query_temp("perform_busy")<5)
     return 0;
     this_object()->delete_temp("perform_busy");
	 if(objectp(weapon=this_object()->query_temp("weapon")))
	 {martial_skill=weapon->query("skill_type");
           if(SKILL_D(martial_skill)->perform_action(this_object(), action)){
             if(!this_object()->query_temp("perform_busy"))
               this_object()->set_temp("perform_busy",time());}
           else return 0;
     }
	 return 1;
}

int apply_action(string arg,int i,int j)  //for apply commands.
{
	if(!living(this_object()))
      return 0;
	command("apply "+arg+" "+i+" "+j+"");
}

void init()
{
  ::init();
  
  add_action("do_enable","jifa");
  
}

int do_enable(string arg)
{
   object ob;
   
   ob=this_player();
   
   if(!arg)
   return notify_fail("��Ҫ��"+query("name")+"����ʲô��������\n");
   
   if(!ob->query_skill(arg,1))
   return notify_fail("��û��ѧ������������ܣ�\n");
   
   if(SKILL_D(arg)->query_type()!="base")
   return notify_fail("��ֻ�ܸ�"+query("name")+"�����������ܣ�\n");
   
   set("reward_skill",arg);
   
   tell_object(ob,"\n"+query("name")+"���꿦�����˼�����\n");
   
   return 1;
}