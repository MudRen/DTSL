
inherit NPC;

void create()
{
   set_name("和尚",({ "he shang","bonze","he","shang"}));
        set("gender", "男性" );
        set("age", 22);
   set("long", "这是净念禅院的和尚。看起来他的武功也是不俗。\n");
   set("class","bonze");
   set("combat_exp", 400000);
   set("str", 28);
   set("per", 22);
   set("attitude", "peaceful");
   set_skill("dodge",80);
   set_skill("parry",90);
   set_skill("staff",90);
   // set_skill("wuxiang-zhangfa",90);
   // set("staff",({"wuxiang-zhangfa"}));
   setup();
   carry_object(__DIR__"obj/sengyi")->wear();
   carry_object(__DIR__"obj/staff")->wield();

}

void init()
{
	object ob,ob2;
	ob=this_player();
	ob2=this_object();
	::init();
	if(!ob||!present(ob,environment())) return;
	call_out("welcome",1,ob,ob2);

}

void welcome(object ob,object ob2)
{
   if(!ob||!present(ob,environment())) return;
	switch(random(2))
	{
	case 0: message_vision("$N低声诵道：阿弥陀佛!\n",ob2);break;
	case 1: message_vision("$N对$n道：佛渡有缘人。\n",ob2,ob);
	}
	remove_call_out("welcome");
	return;
}
