
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIR"��԰"NOR);
  set ("long", @LONG
������һ����԰��������û����ƽ����ĵ������ҩ�ȣ��������˺�
�࿴������ҩ�ĵĻ�����ѩ�׵ģ����ʺ�ģ�������ɫ��һ������һ��
�����������һ����֪���Ƕ������ݡ�
LONG);
  set("exits",([
	  "south":__DIR__"xiaoshilu1",
	  "north":__DIR__"guangchang",
	  ]));
  set("objects",([
	  __DIR__"npc/dizi1":1,
      //__DIR__"npc/dizi2":1,
     // __DIR__"npc/changzhen":1,
    ]));
  set("valid_startroom", 1);
  set("outdoors","yinkui");
  setup();
 
}

