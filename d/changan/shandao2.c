
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
"northdown":__DIR__"shandao1",
"southup":__DIR__"shanyao",
"eastdown":__DIR__"shangu",
        ]));
 set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

