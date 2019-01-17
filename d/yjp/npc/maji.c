// 大唐双龙传


inherit NPC;

int do_action1();

void create()
{
  set_name("马吉", ({"ma ji", "ma", "ji"}));
  set("gender", "男性");
  set("long","这是人称“脏手”的马吉，专做接赃的生意。\n");
  set("age", 36);
  set("max_kee",400);
  set("max_gin",400);
  set("max_sen",400);
  set("max_force",400);
  set("force",400);
  set("combat_exp",600000);
 
  set_skill("force", 160);
  set_skill("dodge", 160);
  set_skill("parry", 160);
  set_skill("fengxue-leg",160);
  
  set("inquiry",([
    "入籍":(:do_action1:),
    ]));
  setup();
  add_money("gold",3);
  
}

int do_action1()
{
  object ob;
  
  ob=this_player();
  
  if(ob->query("family")
    &&ob->query("family/family_name")!="弈剑派"){
    command("say 你已经是其他门派的弟子了，无法再入我高丽籍了！");
    return 1;
  }
  if(ob->query("family")
    &&ob->query("family/family_name")=="弈剑派"){
    command("say 你已经是我高丽的弟子了，快去学习武艺吧！");
    return 1;
  }
  if(!ob->query_temp("bai_yjp_action2")){
    command("say 想成为高丽弟子你还差得远呢！");
    return 1;
  }
  ob->set_temp("bai_yjp_action3",1);
  ob->delete_temp("bai_yjp_action2");
  command("say 现在到处战乱，这件事情我可不敢轻易做主。");
  command("grin "+ob->query("id"));
  return 1;
}

int accept_object(object ob,object who)
{
   if(!who->query("money_id")){
     return notify_fail("我只要钱的，别的什么也不要！\n");
     
   }
   if(!ob->query_temp("bai_yjp_action3")){
     return notify_fail("没事你给我钱干什么？不要！！\n");
    
   }
   if(who->value()<10000){
     return notify_fail("这点钱也太少了吧！你打发要饭的呢？？\n");

   }
   ob->set_temp("bai_yjp_action4",1);
   ob->delete_temp("bai_yjp_action3");
   command("say 好吧！那你就去找盖苏文看看吧！");
   return 1;
}