
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","С·");
  set ("long", @LONG
������һ��С·���������˺ܶ��ʻ�������ɫ�����ޣ������ޱȣ�
һ����֪���Ƕ������ݡ������������ɵĳ�������ʱ�����ﴫ��������
������ʱ�е���������ȥ��
LONG);
  set("exits",([
	  "west":__DIR__"qingshilu2",
	  "east":__DIR__"chufang",
	  ]));

  set("outdoors","yinkui");

  set("valid_startroom", 1);
  setup();
 
}

