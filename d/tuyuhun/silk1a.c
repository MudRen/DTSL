
inherit ROOM;

void create()
{
        set("short", "ˮ����");
        set("long", @LONG
����Ⱥ����ʣ������������֣����·ת��ʯ����¶���й��ζ��ߣ�
����ˮ����̦�����̰ವ����ʯ���ס��꼾ɽ������ֱ����ˮ�������д�
����
LONG);
        set("outdoors", "tuyuhun");

        set("exits", ([
                "southeast" : __DIR__"silk1b",
                "northeast" : __DIR__"silk1",
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
   if(strsrch(time,"��ʱ����")==-1
     )
    return notify_fail("������ʲôҲ��᲻������\n");
   
   msg="$N����������ɳ�����������еġ������־����˸������ʶ��\n";
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
