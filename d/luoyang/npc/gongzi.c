
inherit NPC;

void create()
{
   set_name("����",({ "gongzi","gong","zi" }) );
        set("gender", "����" );
        set("age", 22);
   set("long", "����һ���������εĹ��ӣ�ƽʱ�������й䡣\n");
       
   set("combat_exp", 500);
   set("str", 20);
   set("per", 22);
   set("attitude", "peaceful");
   set("inquiry",([
	   "����":"������Ŷ��������������ĵ��̰�!\n",
	   "�����":"����赣���˵�ڳ��Ͻ�����������.\n",
	   ]));
   setup();
   carry_object(__DIR__"obj/chouyi")->wear();
  
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
	case 0: message_vision("$N������һ�ۣ��������ȥ��\n",ob2);break;
	case 1: message_vision("$N��$nЦ������������ʲô�����ľ����Һ���!\n",ob2,ob);
	}
	remove_call_out("welcome");
	return;
}
