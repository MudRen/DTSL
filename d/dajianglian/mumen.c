
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short","ľ��");
  set ("long", @LONG
��������һ��ľ��ǰ���м����غ���ľ���Աߡ��кܶ��˴������
������������ϸһ���������Ա�����һ������(pai)��
LONG);

  set("exits", ([ 
	  "north":__DIR__"caodi",
	  "south":"/d/jiujiang/wguanlu2",
    ]));
set("outdoors","dajiang");
  set("objects",([
	  __DIR__"npc/dizi":2,
	  ]));
  set("item_desc",([
      "pai":HIG"�����ֶ�\n"NOR,
      ]));
  set("valid_startroom", 1);
  setup();
"/obj/board/dajiang_b.c"->foo();
 
}

int valid_leave(object me,string dir)
{
   if(me->query("shili/name")!="dajiang_b"
     &&dir=="north"&&!wizardp(me)
     &&present("di zi",environment(me)))
     return notify_fail("������ס���㣺�٣��������Ҫ�ȹ�����һ�أ�\n");
     return ::valid_leave(me,dir);
}
     
