
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ũ��");
  set ("long", @LONG
������һƬһ���޼ʵ�ũ�������˶���Ը���Ϊ������������
�ش�����ƽԭ�����ʷ��֣�����������������䲻��ԣ�����������Ҳ
���������ط�������������ࡣ
LONG);

  set("exits", ([ 
 "south":__DIR__"nongtian",
 "west":__DIR__"nongshe2",
 "north":__DIR__"tanxi",
 "east":__DIR__"nongshe1",
        ]));
   set("objects",([
      __DIR__"npc/gengniu":2,
      ]));
 set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

