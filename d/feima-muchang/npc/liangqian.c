
inherit NPC;

void create()
{
   set_name("��ǫ",({ "liang qian","liang","qian" }) );
        set("gender", "����" );
		
        set("age", 30);
   set("long", "���Ƿ�������ר�����µĸ���,�������˶�Ҫ����������\n");
       
   set("combat_exp",300000);
   set("str", 26);
   set("per", 22);
   set("attitude", "peaceful");
   set_skill("unarmed",120);
   set_skill("dodge",120);
   set_skill("parry",120);
   set("dodge",({"babu-ganchan"}));

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
	case 0: message_vision("$N˵��:�������,���Ե����������һ��.\n",ob2);break;
	case 1: message_vision("$N�����۴�����$n\n",ob2,ob);
	}
	remove_call_out("welcome");
	return;
}
