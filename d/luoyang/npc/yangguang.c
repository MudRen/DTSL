
inherit NPC;

void create()
{
   set_name("���",({ "yang guang","yang","guang" }) );
        set("gender", "����" );
        set("age", 32);
   set("long", "�����峯�Ļʵ���㣬ÿ�ճ����ھ�ɫ֮�У���������Щ������˯�����ӡ�\n");
       
   set("combat_exp", 600000);
   set("str", 28);
   set("per", 22);
   set_skill("unarmed",160);
   set_skill("parry",160);
   set_skill("dodge",160);
   set_skill("force",160);
   set("max_gin",1000);
   set("max_sen",1000);
   set("max_kee",1000);
   set("force",1500);
   set("max_force",1500);
   set("attitude", "peaceful");
   setup();
   carry_object(__DIR__"obj/longpao")->wear();
   carry_object(__DIR__"obj/longxue")->wear();
  
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
	case 0: message_vision("$N���˸���Ƿ�������Ū������Ů����!\n",ob2);break;
	case 1: message_vision("$N���˿�$n��Ц�������Ǹ�������Ů������\n",ob2,ob);
	}
	remove_call_out("welcome");
	return;
}
