
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���䳡");
  set ("long", @LONG
�����������ɵ����䳡�������ɵĵ���ƽʱ����������ϰ�书��ֻ
�����ȵ�������ʱ���������м���������Զ����ϰ�������ɵ��ڹ�����
�Ϻ�����֣�͸©��һ�ɹ�������ա����䳡�ĵ����书������Ҳ�Ǹ�
�������������ޱȡ�
LONG);
  set("exits",([
	  "east":__DIR__"qingshilu3",
	  "north":__DIR__"bingqifang",
	  "south":__DIR__"woshi3",
	  ]));
  set("objects",([
	  __DIR__"npc/dizi1":2,
	  __DIR__"npc/yun":1,
	  ]));
  set("outdoors","yinkui");

  set("valid_startroom", 1);
  setup();
 
}

