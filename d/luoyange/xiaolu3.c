
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","С·");
  set ("long", @LONG
�����Ѿ�����ʦ�ľ����ˡ��������������ܶ�������ʿ����������
ȥ���������ġ��������һƬ�������Ĵ���ȥһƬƽ̹�������������
���ͷ�Ϸɹ���
LONG);

  set("exits", ([ 
  "southwest":__DIR__"xiaolu2",
  "northwest":__DIR__"shanlu1",
  "east":"/d/yangzhoubei/xiaolu4",
        ]));
 set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

