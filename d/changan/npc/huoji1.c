// 大唐双龙传


inherit NPC;

void create()
{
  set_name("伙计", ({"huo ji","huo","ji"}));
  set("long","这是银器店的伙计。\n");
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
     command("say 我们这里的银器绝对上乘，快来买了！");
     break;
    case 1:
     command("say 欢迎光临，随便看看吧。");
   }
   
}

