
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"�ɻ���"NOR);
  set ("long", @LONG
�����Ǹ��ɻ��ء�����ν��С�ɲ�¶���š�������ľ�ɫ������
�����������ܵļ�ɽ�������£����������һ�񣬲������ס�
LONG);

  set("exits", ([ 
	  "south":__DIR__"huayuan2",
	  "northeast":__DIR__"ting",
    ]));

  set("outdoors","feima");
  set("valid_startroom", 1);
  setup();
 
}

