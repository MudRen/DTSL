inherit NPC;

void create()
{
  set_name("��Ů",({ "beauty girl","girl"}) );
        set("gender", "Ů��" );
        set("age", 18);
   set("per",30);
   set("long", "һ�������Ľ�����Ů��Ư���ǳ���\n");

   set("attitude", "friendly");
   setup();
    carry_object(__DIR__"shayi")->wear();
}

void init()
{
        object ob,ob2;
        ob=this_player();
        ob2=this_object();
        ::init();
        if(!ob||!present(ob,environment())||ob2->is_fighting()) return;
        call_out("wink",1,ob,ob2);
}

void wink(object ob,object ob2)
{
   if(!ob||!present(ob,environment())||ob2->is_fighting())
    return;
        switch(random(2))
        {
        case 0: message_vision("$N΢΢Ц��Ц����Ů��ֵ����ʱ����֪���뵽˭�ˡ�\n",ob2);
        break;
        case 1: message_vision("$N�����˵�������$nգ��գ��!\n",ob2,ob);
        }
        remove_call_out("wink");
        return;
}
