
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
 "south":__DIR__"tulu2",
 "west":__DIR__"nongtian2",
 "north":__DIR__"nongtian1",
 "east":__DIR__"nongtian3",
        ]));
 set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

