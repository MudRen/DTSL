
inherit NPC;

void create()
{
   set_name("��",({ "da han","da","han" }) );
        set("gender", "����" );
        set("age", 32);
   set("long", "���Ǻ�ɳ��İ��ڡ�\n");
       
   set("combat_exp", 6000);
   set("str", 24);
    set("attitude", "friendly");
    set("shili",([
      "name":"haisha_b",
      ]));
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
	case 0: message_vision("$N������������һ����Ҳ�������Ǻ�ɱ����������!\n",ob2);break;
	case 1: message_vision("$N������$n����\n",ob2,ob);
	}
	remove_call_out("welcome");
	return;
}
