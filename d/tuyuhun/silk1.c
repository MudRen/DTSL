
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "���ɽ");
        set("long", @LONG
����������ţ������Ƹߣ�ɽ��εض���ֱ�����졣ɽ��ƽ��ǧ
Ķ���羰������������ģ������ºͣ�Ȫˮ�࣬ʤ����ɽ�����ʯɫ��
�죬��ˮ����ǿ����������С�����ܡ�ԶԶ���Կ������ϱ���һ����ΰ
�Ĺذ���
LONG);
        set("outdoors", "tuyuhun");

        set("exits", ([
                "southeast" : __DIR__"silk",
                "north" : __DIR__"silk2",
                "southwest" : __DIR__"silk1a",
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