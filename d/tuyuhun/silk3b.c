
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һ������Ķ�Ѩ����������ʯѤ�����ˣ��������档��Ϭţ��
�¡��������졢����ƺ��������������������ݡ���ľ�ŵȣ�������
ǧ������Ѱζ��һֱ���Ŷ������ߣ����ܵ�����Ȫ�ˡ�
LONG);
        set("outdoors", "tuyuhun");

        set("exits", ([
                "eastup" : __DIR__"silk3a",
                "west" : __DIR__"silk3c",
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
   
   msg="$N����������ɳ�����������еġ��ơ��־����˸������ʶ��\n";
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