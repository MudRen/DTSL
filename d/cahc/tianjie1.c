
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���");
  set ("long", @LONG
����һ��������ʯ���ɵ�ƽ̹�������ʮ�ɣ�������㳡������
ȸ�ţ��ǻʳ�������һ���֣��������˶���Ϊ����֡��������������
��һ������ʽ�����Ľ�������͢�ĸ������������ֱ������������
LONG);

  set("exits", ([ 
 "north":__DIR__"tianjie2",
 "south":__DIR__"zhuquemen",
 "southeast":__DIR__"anshangmen",
 "southwest":__DIR__"hanguangmen",
 "east":__DIR__"donggongpu",
 "west":__DIR__"gongbu",
        ]));
   set("outdoors","changan");
   set("valid_startroom", 1);
  setup();
 
}

