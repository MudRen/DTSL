
#include <room.h>
inherit ROOM;
void create()
{ 
       set("short","��ɳĮ");
       set("long", @LONG
����һƬһ���޼ʵĴ�ɳĮ����һ��������ʧ�˷��򡣿���Ҫ�߳�
���ɳĮ�������¡�
LONG);
        set("outdoors", "shamo");
        set("exits", ([
                "east" : __DIR__"shamo"+(1+random(4)),
                "west" : __DIR__"shamo"+(1+random(4)),
                "south" : __DIR__"shamo2",
                "north" : __DIR__"shamo"+(1+random(4)),
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
   
   if(ob->query_skill("fuying-spear",1)<160)
   return 0;
   if(ob->query("perform_quest/fengsha"))
   return 0;
   if(ob->query("perform_quest/fengyu"))
   return 0;
   
   time=NATURE_D->game_time();
   if(strsrch(time,"����")==-1
    &&strsrch(time,"����")==-1
     )
    return notify_fail("������ʲôҲ��᲻������\n");
   
   msg="$N����ɳĮ�з�ɳ�����ɵöԷ�ӥǹ�����˸������ʶ��\n";
   message_vision(msg,ob);
   ob->set("perform_quest/fengsha",1);
   return 1;
}