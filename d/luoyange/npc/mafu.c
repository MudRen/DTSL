
inherit NPC;

void create()
{
   set_name("���",({ "ma fu","ma","fu" }) );
        set("gender", "����" );
        set("age", 30);
   set("long", "���Ƿ������������\n");
       
   set("combat_exp", 80000);
   set("str", 25);
   set("per", 22);
   set("attitude", "peaceful");
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

void init()
{
	object ob,ob2;
	ob=this_player();
	ob2=this_object();
	::init();
	if((!ob||!present(ob,environment())||ob2->is_fighting())&&ob->query("race")=="����") return;
	call_out("welcome",1,ob,ob2);
	
}

void welcome(object ob,object ob2)
{
   if(!ob||!present(ob,environment())||ob2->is_fighting()) return;
	switch(random(2))
	{
	case 0: message_vision("$N��$nЦ��:��λ"+RANK_D->query_respect(ob)+",�������������?\n",ob2,ob);break;
	case 1: message_vision("$N��$n˵��:��λ"+RANK_D->query_respect(ob)+",�����������,��������������ɻ!\n",ob2,ob);
	}
	remove_call_out("welcome");
	return;
}
