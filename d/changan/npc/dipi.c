// 大唐双龙传


inherit NPC;

void create()
{
  set_name("地痞", ({"di pi","di","pi"}));
  set("long","这是长安的一名小地痞。\n");
  set("gender", "男性");
  set("combat_exp", 90000);

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
     command("say 都给我滚开，别挡老子的路！");
     break;
    case 1:
     command("say 大爷我今天气不顺，别在老子面前晃来晃去的。");
   }
   
}

