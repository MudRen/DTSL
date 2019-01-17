// 大唐双龙传


inherit NPC;

void create()
{
  set_name("小贩", ({"xiao fan","xiao","fan"}));
  set("long","这是一个卖东西的小贩。\n");
  set("gender", "男性");
  set("combat_exp",80000);

  set_skill("unarmed", 10);
  set_skill("dodge", 40);
  set_skill("parry", 30);
  
  setup();
  carry_object(__DIR__"obj/cloth")->wear();
}

void init()
{
   object ob;
   
   ob=this_player();
   
   if(!ob||is_fighting()) return;
   
   remove_call_out("welcome");
   call_out("welcome",1,ob);
   
}

void welcome(object ob)
{
   if(!ob) return;
   if(environment(ob)!=environment(this_object()))
   return;
   
   switch(random(2)){
    case 0:
     command("say 看看我的货物，长安数一数二的！");
     break;
    case 1:
     command("say 都来看看了，瞧瞧了，我的货物老少无欺。");
   }
   
}

