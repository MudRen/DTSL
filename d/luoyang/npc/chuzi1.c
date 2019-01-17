
inherit NPC;

void create()
{
   set_name("厨子",({ "chu zi","chu","zi" }) );
        set("gender", "男性" );
        set("age", 30);
   set("long", "这是洛阳皇宫的一个厨子。\n");
       
   set("combat_exp", 50);
   set("str", 10);
   set("per", 22);
   set("attitude", "friendly");
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
	switch(random(2))
	{
	case 0:
	command("say 不是我吹牛，我做的这道菜皇上最爱吃了！");
	break;
	
	case 1:
	command("say 皇上冬天要春笋，夏天要冰水，可真是难死我们厨子了！");
	}
	
}
