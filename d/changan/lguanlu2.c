#include <ansi.h>
inherit ROOM;

void create()
{
  set ("short","��·");
  set ("long", @LONG
������һ����·�����߾��������������ˡ���������˱Ƚ϶��ˣ�
������������������з���������Ͷ�������˺ܶࡣ���Ｘ����������
���ڷ�����������
LONG);

  set("exits", ([ 
"west":__DIR__"lguanlu1",
"east":"/d/luoyang/ximen",
       ]));
 set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

