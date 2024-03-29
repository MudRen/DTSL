inherit	F_MASTER;
inherit NPC;
#include <ansi.h>
string do_quest();
void create()
{
   set_name("单美仙",({ "shan meixian","shan","meixian" }) );
        set("gender", "女性" );
		set("title",HIR"东溟夫人"NOR);
        set("age", 32);
   set("long", "这是东溟派的派主东溟夫人.\n");

   set("combat_exp",2000000);
   set("str", 25);
   set("per", 25);
   set("attitude", "peaceful");
   set_skill("unarmed",300);
   set_skill("dodge",300);
   set_skill("cuff",300);
   set_skill("parry",300);
   set_skill("force",300);
   set_skill("sword",300);
   set_skill("strike",300);
   set_skill("literate",300);
   set_skill("youyue-zhangfa",300);
   set_skill("dongming-xinfa",300);
  //  set_skill("bihai-jianfa",300);
   set_skill("piaomeng-jianfa",300);
   set_skill("shuiyun-xiufa",300);
  //  set_skill("yuxiao-quanfa",300);
   set_skill("nishang-piaoming",300);
   set("dodge",({"nishang-piaoming"}));
   set("force_skill",({"dongming-xinfa"}));
   set("sword",({"piaomeng-jianfa"}));
   set("hand",({"shuiyun-xiufa","youyue-zhangfa"}));
   set("max_gin",5000);
   set("max_sen",5000);
   set("max_kee",5000);
   set("force",6000);
   set("max_force",6000);
   create_family("东溟派",2,"派主");
   set("chat_msg_combat",({
	   (:apply_action,"piaomeng-jianfa",1+random(4),9:),
	   (:apply_action,"youyue-zhangfa",1+random(4),9:),
	   (:perform_action,"lianhuan":),
	   (:perform_action,"liuyun":),
   }));
   set("inquiry",([
     "东溟战将":(:do_quest:),
     ]));
   setup();
   carry_object(__DIR__"obj/caiyi")->wear();
   carry_object(__DIR__"obj/changjian")->wield();

}
void attempt_apprentice(object ob)
{
    object me;me=this_object();
	if(ob->query("family"))
		if(ob->query("family/family_name")=="阴癸派")
		{ message_vision("$N朝$n冷笑道：向你这种邪派也敢来拜师！\n",me,ob);
		me->kill_ob(ob);return;}
    if((int)ob->query_skill("dongming-xinfa",1)<180)
	{ command("say 你的[东溟心法]太差劲了，叫我如何收你为徒？\n");
	return;}
	command("say 好,希望你在东溟好好干，将来多做些行侠仗义之事!\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "dongming3");
}
string do_quest()
{
  object ob;
  ob=this_player();
  if(ob->query_skill("dongming-xinfa",1)<300)
  return "你的功夫太低了，现在还无法超越的！\n";
  if(ob->query("family_lingwu")=="dongming")
  return "长江后浪推前浪，你已经超越我了，还是快去领悟吧！\n";
  ob->set_temp("gage_zhu",1);
  return "好啊，你想成为东溟战将，必须先打赢我[fight shan]\n";
}

int surrender(object killer,object victim)
{
   object ob;
   if(!killer->query_temp("gage_shan"))
   return 1;
   message_vision(HIC"$N微微一笑：没想到我东溟派还有你这样的后起之秀！\n"NOR,victim);
   message_vision(HIC"$N脸色突然严肃起来，轻声道：来，我告诉你一个本派的秘密！\n"NOR,victim);
   tell_object(killer,"你来到东溟夫人身旁，东溟夫人道：本派有一个修炼东溟心法的地方，\n"+
                      "据说在海边的悬崖处。我一直没有找到，看你能不能找到，光大本派了！\n");
   killer->set("family_lingwu","dongming");
   killer->set("title",HIG"东溟战将"NOR);
   return 1;
}
int end_fight(object killer,object victim)
{
  if(!victim->query_temp("gage_shan"))
   return 1;
  message_vision("$N朝$n叹了口气，你还是回去再磨练磨练吧！\n",killer,victim);
  return 1;
}
