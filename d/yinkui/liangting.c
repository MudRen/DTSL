
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ͤ");
  set ("long", @LONG
������һ����ͤ����紵������ʱ��������Ŀˬ��������һ�����ȣ�
��ʱ�������ɵĵ��Ӵ�������������ͤ�ϰ��ż����ʻ�������ɫ��������
����ޱȡ�
LONG);
  set("exits",([
	  "east":__DIR__"changlang",
	  "southwest":__DIR__"zhulin",
	  ]));

  set("outdoors","yinkui");

  set("valid_startroom", 1);
  setup();
 
}

