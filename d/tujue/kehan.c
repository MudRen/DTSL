

inherit NPC;

#include <ansi.h>
#include <job_money.h>

int do_action1();

void create()
{
   set_name("颉利大汗",({ "da han","da","han" }) );
   set("gender", "男性" );	
   set("age", 50);
   set("combat_exp",1000000);
   set("str", 25);
   set("per", 22);
   
   set_skill("dodge",200);
   set_skill("parry",200);
   set_skill("force",200);
   set_skill("whip",200);
   set_skill("literate",200);
  
   set_skill("yanyang-dafa",200);
   set_skill("canglang-jue",200);
   set_skill("youlong-shenfa",200);
   set_skill("feiwo-whip",200);
   set("max_gin",3000);
   set("max_kee",3000);
   set("max_sen",3000);
   set("force",3000);
   set("max_force",3000);
   set("inquiry",([
    "飞挝鞭法":(:do_action1:),
    ]));
   create_family("突厥",2,"大汗");
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
   carry_object(__DIR__"obj/whip")->wield();
  
}

string *dirs=({
"/d/saiwai",
});

int do_action1()
{
  object ob,horse;
  
  ob=this_player();
  
  if(ob->query("tujue_jun")!="金狼军"){
         command("say 你没加入我们金狼军，我是不会告诉你任何秘诀的！");
         return 1;
  }
  if(ob->query("perform_quest/kun")){
     command("say 你已经掌握了飞挝鞭法的诀窍，自己去好好提高吧！");
     return 1;
  }
  if(ob->query("perform_quest/kuangsha")){
     command("say 你已经掌握了狂沙刀法的诀窍，无法领会飞挝鞭法的诀窍！");
     return 1;
  }
  if(ob->query_skill("feiwo-whip",1)<160){
    command("say 你的飞挝鞭法修为太低，无法领会其中的精髓之处！");
    return 1;
  }
  if(ob->query_temp("perform_quest/kun_action1")){
     command("say 你快去帮我找汗血宝马吧！");
     return 1;
  }
  horse=new(__DIR__"horse");
  horse->set_status(ob);
  if(!random_place(horse,dirs)){
    command("say 你等等... ...");
    return 1;
  }
  if(!environment(horse)){
    command("say 你等等... ...");
    return 1;
  }
  ob->set_temp("perform_quest/kun_action1",1);
  ob->add_temp_array("job_temp_killer",horse);
  command("say 听说在"+MISC_D->find_place(environment(horse))+"有一只汗血宝马，你去帮我带来吧！");
  
  return 1;
}

int accept_object(object ob,object obj)
{
   if(!ob->query_temp("perform_quest/kun_action1"))
   return 0;
   if(!obj->query("perform_quest_kun_obj"))
   return 0;
   if(obj->query("owner_ob")!=ob)
   return notify_fail("这是我让你抓的那只马吗？\n");
   
   ob->delete_temp("perform_quest/kun_action1");
   command("pat "+ob->query("id"));
   command("say 好，干的不错！我这就传授你飞挝鞭法的精髓之处！");
   message_vision("$N凑到$n耳边低语几句，$n若有所悟。\n",this_object(),ob);
   ob->set("perform_quest/kun",1);
   return 1;
}