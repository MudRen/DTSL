
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
 "north":__DIR__"tianjie4",
 "south":__DIR__"tianjie2",
 "east":__DIR__"shaofujian",
 "west":__DIR__"dafusi",
        ]));
   set("outdoors","changan");
   set("valid_startroom", 1);
  setup();
 
}

