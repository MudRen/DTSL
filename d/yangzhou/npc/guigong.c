
inherit NPC;

void create()
{
   set_name("�깫",({ "gui gong","gui","gong" }) );
        set("gender", "����" );
        set("age", 22);
   set("long", "���������������ߵĹ깫��ÿ��æ��æȥ��\n");
       
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
	case 0: message_vision("$NЦ��:���Ϲ������Ư������������!\n",ob2);break;
	case 1: message_vision("$N��$nЦ������λ�͹�����!\n",ob2,ob);
	}
	remove_call_out("welcome");
	return;
}

int accept_object(object who,object ob)
{
	if(ob->query("money_id") && ob->value() >= 1000)
	{tell_object(who,"�깫΢Ц������λ�͹٣������ȥ������!\n");
	 who->set_temp("gived_money",1);
	}
    else tell_object(who,"�깫Ц����������ס�ޣ�һ��10������.\n");
    return 1;
}
