
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����ɽ��");
  set ("long", @LONG
������һ������ɽ�ŵ�ɽ·����������˲��Ǻܶ࣬���ܴ����ܲ���
�ʻ��̲��������֣�����ɽ���ﴵ����������磬������������������
һЩ�����Ļ��㡣
LONG);

  set("exits", ([ 
"northdown":__DIR__"shandao",
"southup":__DIR__"shandao2",
        ]));
 set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

