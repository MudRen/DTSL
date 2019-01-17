
inherit NPC;

void create()
{
   set_name("龟公",({ "gui gong","gui","gong" }) );
        set("gender", "男性" );
        set("age", 22);
   set("long", "这是扬州瘦西湖边的龟公，每天忙来忙去。\n");
       
   set("combat_exp", 200);
   set("str", 18);
   set("per", 22);
   set("attitude", "friendly");
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

void init()
{
	object ob,ob2;
	ob=this_player();
	ob2=this_object();
	::init();
	if(!ob||!present(ob,environment())||ob2->is_fighting()) return;
	call_out("welcome",1,ob,ob2);
	
}

void welcome(object ob,object ob2)
{
   if(!ob||!present(ob,environment())||ob2->is_fighting()) return;
	switch(random(2))
	{
	case 0: message_vision("$N笑道:船上姑娘各个漂亮，包您满意!\n",ob2);break;
	case 1: message_vision("$N朝$n笑道：这位客官请了!\n",ob2,ob);
	}
	remove_call_out("welcome");
	return;
}

int accept_object(object who,object ob)
{
	if(ob->query("money_id") && ob->value() >= 1000)
	{tell_object(who,"龟公微笑道：这位客官，您请进去喊船吧!\n");
	 who->set_temp("gived_money",1);
	}
    else tell_object(who,"龟公笑道：本画舫住宿，一晚10两白银.\n");
    return 1;
}
