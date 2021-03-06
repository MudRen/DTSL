
inherit F_MASTER;
inherit NPC;
#include <ansi.h>

int do_action1();
int do_action2();

void create()
{
   set_name("尚明",({ "shang ming","shang","ming" }) );
   set("gender", "男性" );
   set("nickname","明帅");
   set("age", 28);
   set("long", "这是东溟派人称“明帅”的尚明。\n");
       
   set("combat_exp",600000);
   set_skill("dodge",150);
   set_skill("parry",150);
   set_skill("force",150);
   set_skill("hammer",150);
  
   set_skill("dongming-xinfa",150);
   set_skill("bihai-force",150);
   set_skill("leiting-chuifa",150);
   set_skill("nishang-piaoming",150);
   set_skill("literate",150);
   
   set("max_gin",2000);
   set("max_sen",2000);
   set("max_kee",2000);
   set("force",2000);
   set("max_force",2000);
   create_family("东溟派",5,"弟子");
   
   set("inquiry",([
     "东溟公主":(:do_action1:),
     "讨好公主":(:do_action2:),
     ]));
   
   setup();
   carry_object(__DIR__"obj/hammer")->wield();
  
}

void attempt_apprentice(object ob)
{   
	int lev;
	
	if(ob->query("family"))
	if(ob->query("family/family_name")=="东溟派")
	if((int)ob->query("family/generation",1)<=5)
	{   
	   command("say 此话从何说起？\n");
	   return;
	}
	
	if(ob->query("gender")=="女性"){
	
	command("say 我不收女弟子的！你如果诚心投入本派，去找单霞吧！\n");
	return;
        }
        
        if(ob->query_skill("bihai-force",1)<100){
          command("say 碧海神功是我们东溟派的根基，你不好好学我怎么能收你为弟子呢？");
          return;
        }
        if(ob->query("office_number")<30){
        command("say 你的功绩这么低，我可不要这么懒惰的弟子！\n");
        return;
        }
        
        if(!ob->query_temp("bai_shangming/ok")){
          command("say 我正在为琬晶烦恼呢，你先等会吧！");
          return;
        }
        
        lev=ob->query_skill("strike",1);
        lev=lev*lev/(lev+100);
        ob->party_reward_skill("hammer",lev);
        tell_object(ob,HIY"你从基本掌法中领略到了基本锤法！\n"NOR);
		
	command("say 我们男弟子在东溟派向来充当护派重任，你也要好好学习武艺！\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "dongming2");
}

int do_action1()
{
   object ob;
   
   ob=this_player();
   
   if(ob->query("family"))
   if(ob->query("family/family_name")=="东溟派")
   if((int)ob->query("family/generation",1)<=6){   
       command("say 琬晶经常四处云游，认识了不少男人。\n");
       return 1;
   }
   if(!ob->query("family")){   
       command("say 琬晶经常四处云游，认识了不少男人。\n");
       return 1;
   }
   if(ob->query("family"))
   if(ob->query("family/family_name")!="东溟派"){   
       command("say 琬晶经常四处云游，认识了不少男人。\n");
       return 1;
   }
   if(ob->query_skill("bihai-force",1)<100){   
       command("say 琬晶经常四处云游，认识了不少男人。\n");
       return 1;
   }
   
   ob->set_temp("bai_shangming/action1",1);
   command("say 琬晶经常四处云游，认识了不少男人。\n");
   command("sigh");
   return 1;
}

int do_action2()
{
   object ob;
   
   ob=this_player();
   
   if(!ob->query_temp("bai_shangming/action1")){
      command("say 我是堂堂男儿，怎么能做这样的事！\n");
       return 1;
   }
   if(ob->query("family"))
   if(ob->query("family/family_name")=="东溟派")
   if((int)ob->query("family/generation",1)<=6){   
       command("say 我是堂堂男儿，怎么能做这样的事！\n");
       return 1;
   }
   if(!ob->query("family")){   
       command("say 我是堂堂男儿，怎么能做这样的事！\n");
       return 1;
   }
   if(ob->query("family"))
   if(ob->query("family/family_name")!="东溟派"){   
       command("say 我是堂堂男儿，怎么能做这样的事！\n");
       return 1;
   }
   if(ob->query_skill("bihai-force",1)<100){   
       command("say 我是堂堂男儿，怎么能做这样的事！\n");
       return 1;
   }
   
   ob->set_temp("bai_shangming/ok",1);
   ob->delete_temp("bai_shangming/action1");
   command("say 我怎么没有想到呢。东溟派以女系为主，若我武功大进，必能重振男系，琬晶定会回我身边。\n");
   return 1;
}