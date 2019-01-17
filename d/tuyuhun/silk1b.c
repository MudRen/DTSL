
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����Դ�˵�����ɳ�û��������ÿ��ʢ��ҹ����������ɳ�����
Ի�����͵ơ���ɽ��ˮ��Ⱥ�廷�ţ�Ұ�����ף��滨�����������վ���
���˾��ס�
LONG);
        set("outdoors", "tuyuhun");

        set("exits", ([
                "northwest" : __DIR__"silk1a",
                "northeast" : __DIR__"silk",
        ]));
        set("objects",([
          __DIR__"npc/youke":1,
         ]));

        setup();
}

void init()
{
  add_action("do_linghui","linghui");

}

int do_linghui()
{
   object ob;
   string time,msg;
   
   ob=this_player();
   
   if(ob->query_skill("kuangsha-daofa",1)<160)
   return 0;
   if(ob->query("perform_quest/kuangsha"))
   return 0;
   if(ob->query_skill("feiwo-whip",1))
   return 0;
   
   time=NATURE_D->game_time();
   if(strsrch(time,"îʱ����")==-1
     )
    return notify_fail("������ʲôҲ��᲻������\n");
   
   msg="$N����������ɳ�����������еġ����־����˸������ʶ��\n";
   message_vision(msg,ob);
   ob->set_temp("perform_quest/kuangsha_action1",1);
   if(ob->query_temp("perform_quest/kuangsha_action1")
    &&ob->query_temp("perform_quest/kuangsha_action2")
    &&ob->query_temp("perform_quest/kuangsha_action3")
    &&ob->query_temp("perform_quest/kuangsha_action4")
    &&ob->query_temp("perform_quest/kuangsha_action5")
     ){
    msg="$N΢΢һЦ����ɳ������Ȼ�����ɾͣ�\n";
    message_vision(msg,ob);
    ob->set("perform_quest/kuangsha",1);
    ob->delete_temp("perform_quest");
   }
   return 1;
}