
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
������һ������ɽɽ���е�ɽ·����������˲��Ǻܶ࣬���ܴ���
�ܲ����ʻ��̲��������֣�����ɽ���ﴵ����������磬������������
������һЩ�����Ļ��㡣
LONG);

  set("exits", ([ 
"northeast":"/d/taiyuan/road8c",
"southup":__DIR__"shandao4",
        ]));
 set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

