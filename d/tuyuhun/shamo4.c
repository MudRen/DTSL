
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

int valid_leave(object me, string dir)
{
        if ( dir == "west") me->add_temp("mark/steps",1);
        if ( dir == "east") me->add_temp("mark/steps",-1);

     if (me->query_temp("mark/steps") == 5){
         me->move("/d/suiye/dadao2");
         me->delete_temp("mark/steps");
         tell_room(environment(me), me->name()+"���ϱߵĴ�ɳĮ���˹�����\n", ({ me }));
         return notify_fail("���۵ð���������߳���ɳĮ��\n");
         }  
     if (me->query_temp("mark/steps") == -5){  
         me->move("/d/tuyuhun/silk9");
         me->delete_temp("mark/steps");
         tell_room(environment(me), me->name()+"�����ߵĴ�ɳĮ���˹�����\n", ({ me }));
         return notify_fail("���۵ð���������߳���ɳĮ��\n");
         }
        return ::valid_leave(me,dir);
}
