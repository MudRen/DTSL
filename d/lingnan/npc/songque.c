
inherit F_MASTER;
inherit NPC;
#include <ansi.h>
#include <org.h>

string do_quest();
int do_action1();
int do_action2();

void create()
{
   int i;
   object *ob;
   set_name("宋缺",({ "song que","song","que" }) );
   set("gender", "男性" );
   set("nickname",HIG"天刀"NOR);
   set("age", 52);
   set("long", "他就是宋家堡的堡主，人称「天刀」。他的刀法据说为武林第一。\n");
       
   set("combat_exp",8000000);
   set("str", 35);
   set("per", 25);
   
   set_skill("blade",500);
   set_skill("sword",500);
   set_skill("dijian-jue",500);
    set_skill("dodge",400);
    set_skill("parry",400);
    set_skill("force",400);
    set_skill("tiandao-bajue",500);
    set_skill("anxiang-fuying",400);
    set_skill("tiangang-sanjue",400);
    set_skill("poyu-quan",400);
    set_skill("cuff",400);
    set_skill("wangdao-jue",400);
    set_skill("literate",400);
    set("jiali",200);

    set("apply_points",2000);
    set("perform_quest/bajue",1);
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
        (: command("perform bajue") :),
        (: command("execute wangdao") :),
        (: command("exert zhanyi") :),
        (: command("exert ningxin") :),
    }));
  
    set("max_gin",5000);
    set("max_kee",6000);
    set("max_sen",6000);
    set("max_force",15000);
    set("force",15000);
   
   
   create_family("宋家堡",3,"掌门");
   set("shili",([
      "name":"songjia_b",
      "leader":"songjia_b",
      ]));
   set("shili_id","songque");
    set("npc_id","songque");
   
   set("inquiry",([
     "岭南一刀":(:do_quest:),
    // "考验":(:do_action1:),
     "天刀八诀":(:do_action2:),
     ]));
   setup();
   carry_object(__DIR__"obj/chouyi")->wear();
   
   ob=children(__DIR__"obj/chanyidao");
   for(i=0;i<sizeof(ob);i++)
     if(environment(ob[i])&&userp(environment(ob[i]))){
     tell_object(environment(ob[i]),"你手中的"+ob[i]->query("name")+"被它的主人收回去了！\n");
     if(ob[i]->query("equipped"))
      ob[i]->unequip();
     destruct(ob[i]);}
     else if(environment(ob[i])){
     tell_object(environment(ob[i]),ob[i]->query("name")+"被一阵风卷走了。\n");
     destruct(ob[i]);}
     else destruct(ob[i]);
   
   ob=children(__DIR__"obj/shuixian");
   for(i=0;i<sizeof(ob);i++)
     if(environment(ob[i])&&userp(environment(ob[i]))){
     tell_object(environment(ob[i]),"你手中的"+ob[i]->query("name")+"被它的主人收回去了！\n");
     if(ob[i]->query("equipped"))
      ob[i]->unequip();
     destruct(ob[i]);}
     else if(environment(ob[i])){
     tell_object(environment(ob[i]),ob[i]->query("name")+"被一阵风卷走了。\n");
     destruct(ob[i]);}
     else destruct(ob[i]);
   
   ob=children(__DIR__"obj/tanlangtun");
   for(i=0;i<sizeof(ob);i++)
     if(environment(ob[i])&&userp(environment(ob[i]))){
     tell_object(environment(ob[i]),"你手中的"+ob[i]->query("name")+"被它的主人收回去了！\n");
     if(ob[i]->query("equipped"))
      ob[i]->unequip();
     destruct(ob[i]);}
     else if(environment(ob[i])){
     tell_object(environment(ob[i]),ob[i]->query("name")+"被一阵风卷走了。\n");
     destruct(ob[i]);}
     else destruct(ob[i]);
     
   carry_object(__DIR__"obj/chanyidao")->wield();
   carry_object(__DIR__"obj/shuixian");
   carry_object(__DIR__"obj/tanlangtun");
   
  
}

void init()
{
   object ob;
   
   ob=previous_object();
   
   if(!ob->query("dtsl_quest_badao_help_ok")
     &&ob->query("combat_exp")>=800000
     &&ob->query("nickname")=="天君"+NOR
     &&ob->query("PKS")>=10
     &&ob->query("deadtimes")<3
     &&!ob->query_temp("dtsl_quest_badao_help_ok")
     ){
     ob->set_temp("dtsl_quest_badao_help_ok",1);
     call_out("do_hit_ob",1,ob);
   }
   
}

void do_hit_ob(object ob)
{
  if(!ob)
   return;
  
  command("say 你敢用这个名号来我宋家堡，真是活得不耐烦！");
  
  kill_ob(ob);
}

void attempt_apprentice(object ob)
{   
	
	if(ob->query("family"))
	if(ob->query("family/family_name")=="宋家堡")
	if((int)ob->query("family/generation",1)<=3)
	{   
	   command("say 此话从何说起？\n");
	   return;
	}
	
        if(ob->query_skill("tiangang-sanjue",1)<150){
        command("say 你的天罡三诀修为太低了，我不收这样的弟子！");
        return;
        }
	if(ob->query("office_number")<50){
        command("say 你的功绩这么低，宋家堡可不要这么懒惰的弟子！\n");
        return;
        }
        if(ob->query("deposit")<500000){
         command("say 我们宋家堡乃岭南一大阀，象你这么不懂敛财的人我可不要！");
         return;
        }
        if(ob->query("kill_same_party_flags")){
          command("heng");
          command("say 象你这样杀害同门的人我不杀你是你运气，快滚吧！");
          return;
        }
        if(ob->query("kill_good_party_flags")){
          command("heng");
          command("say 我宋家乃一名门正派，你杀害正派弟子，我怎么能收你为徒？");
          return;
        }
        /*
        if(!ob->query("char_lev/bai_songque_ok")){
          command("say 你没有经过我的考验，我不会收你为弟子的！");
          return;
        }
        */
        ob->set("lingnan_menpai/lingnan_MKS",ob->query("MKS"));
        ob->set("lingnan_menpai/lingnan_PKS",ob->query("PKS"));
        ob->set("lingnan_menpai/lingnan_deadtimes",ob->query("deadtimes"));
        if(!ob->query("menpai/songjia3")){
          ob->set("menpai/songjia3",1);
	  
	}
	command("say 真是长江后浪推前浪！希望你能助宋家堡称霸天下！\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "song3");
}
int accept_enroll(object me)
{
	object ob;
	ob=this_object();
	if(me->query("shili"))
	if(me->query("shili/name")!=ob->query("shili/name"))
	 return notify_fail("我们宋家堡可不要其他帮派的人！\n");
	if(!ORG_D->is_leader("songque"))
	 return notify_fail("我已经不是堡主了，和我说没用的！\n");
	if(me->query("shili/name")==ob->query("shili/name"))
	 return notify_fail("你高声喊道：宋家堡称雄岭南！\n");
	me->set_temp("mark_join",ob->query("shili/name"));
	message_vision("$N朝$n笑道：希望$n能好好干，使我们宋家堡在岭南雄霸一方！\n",ob,me);
	tell_object(me,HIW"\n请去势力名单榜处打 "HIG"join"HIW" 命令就算加入了！\n\n"NOR);
	
	return 1;
}
string do_quest()
{
  object ob,obj;
  
  ob=this_player();
  if(ob->query_skill("tiangang-sanjue",1)<200)
  return "你的功夫太低了，现在还无法享有[岭南一刀]这个绰号！\n";
  if(ob->query("family_lingwu")=="songjia")
   return "长江后浪推前浪，你已经突破境界了，还是快去领悟吧！\n";
  if(ob->query_temp("quest_fighter"))
  return "你还是快去战胜木人吧！\n";
  ob->set_temp("gage_song",1);
  
  obj=new(__DIR__"q_songque");
  obj->set("name",ob->name()+"的木人");
  obj->set("target_id",ob->query("id"));
  obj->set_temp("owner_ob",ob);
  ob->set_temp("quest_fighter",obj);
  ob->add_temp_array("job_temp_killer",obj);
  
  obj->move(environment(ob));
  
  return "好啊，你想成为岭南一刀，看你能否突破自身的障碍，和这个木人切磋一下吧。\n";
}
/*
int surrender(object killer,object victim)
{
   object ob;
   if(!killer->query_temp("gage_song"))
   return 1;
   message("vision",HIG"【宋家堡】:宋缺仰天长笑道："+killer->name()+HIG+"战胜了我，宋家堡终于后继有人了！\n"NOR,users());
   tell_object(killer,"你去我宋家堡的白虎堂，那里有我们门派的一个秘密！\n"+
                      "能不能领悟，就看你自己的造化了！\n");
   killer->set("family_lingwu","songjia");
   killer->set("title","岭南一刀");
   return 1;
}
int end_fight(object killer,object victim)
{
  if(!victim->query_temp("gage_songjia"))
   return 1;
  message_vision("$N朝$n叹了口气，你还是回去再磨练磨练吧！\n",killer,victim);
  return 1;
}
*/
int accept_gage(object me)
{
   message_vision("$N朝$n笑道:好吧，只要你能接住我的三刀，就可以接任我的职位了！\n",
    this_object(),me);
   
   add_temp("apply/damage",-900);
   COMBAT_D->do_attack(this_object(),me,this_object()->query_temp("weapon"),0,1);
   COMBAT_D->do_attack(this_object(),me,this_object()->query_temp("weapon"),0,1);
   COMBAT_D->do_attack(this_object(),me,this_object()->query_temp("weapon"),0,1);
   add_temp("apply/damage",900);
   if(living(me)){
   message_vision("$N朝$n笑道：果真是长江后浪推前浪，以后宋家堡就交给你了！\n",
   this_object(),me);
   ORG_D->del_leader("songque");
   ORG_D->set_leader_log(me,this_object());
   
   me->set("shili/leader",this_object()->query("shili/leader"));
   CHANNEL_D->do_channel(this_object(), "rumor",
   me->name()+"成为了宋家堡的堡主！\n");}
   return 1;
}

int do_action1()
{
  object ob,book;
  string msg;
  
  ob=this_player();
  
  if(ob->query("family"))
  if(ob->query("family/family_name")!="宋家堡"){
      command("say 此话从何说起？\n");
      return 1;
  }
  if(ob->query("family"))
  if(ob->query("family/family_name")=="宋家堡")
  if((int)ob->query("family/generation",1)<=4){   
      command("say 此话从何说起？\n");
      return 1;
  }
  if(ob->query_skill("tiangang-sanjue",1)<150){
        command("say 你的天罡三诀修为太低了，经不住我的考验的！");
        return 1;
  }
  if(present("bai_songque_linghui_book",ob)){
  	command("heng");
  	return 1;
  }
  if(ob->query("char_lev/bai_songque_ok")){
    command("say 既然你已经领会了其中的诀窍，就拜我为师吧！");
    return 1;
  }
  if(ob->query("char_lev/bai_songque_fail")){
    command("say 其中的诀窍你懂就是懂，不懂就是不懂，我看你还是算了！");
    return 1;
  }
  book=new(__DIR__"obj/book");
  book->move(ob);
  msg="$N给了$n一"+book->query("unit")+book->query("name")+"。\n"+
      "我向来收徒严格，你如果能领会(linghui)这书中的诀窍，我就收你！\n";
  message_vision(msg,this_object(),ob);
  return 1;
}

int do_action2()
{
   object ob,obj;
   
   ob=this_player();
   
   if(ob->query("perform_quest/ditian")){
     command("say 你已经学习了地剑诀的精髓，是没有精力再来学天刀的！");
     return 1;
   }
   if(ob->query("perform_quest/bajue")){
     command("say 你已经学习了天刀八诀的精髓，自己去提高吧！");
     return 1;
   }
   if(ob->query_skill("tiandao-bajue",1)<190){
     command("say 你的天刀八诀修为太低，现在还无法领会其中的精髓！");
     return 1;
   }
   if(ob->query("family/master_name")!=query("name")){
     command("say 我没有收你为徒，你如何领会天刀八诀的精髓？");
     return 1;
   }
   if(present("perform_bajue_blade",ob)){
     command("say 你快练习拔刀吧！");
     return 1;
   }
   ob->set_temp("perform_quest/bajue_action1",1);
   obj=new(__DIR__"obj/blade2");
   obj->move(ob);
   tell_object(ob,query("name")+"给了你一"+obj->query("unit")+obj->query("name")+"。\n");
   command("say 要发挥天刀的最大威力，最重要的是拔刀，你先练习一下拔刀的技术吧！");
   return 1;
}
