
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ʯ·");
  set ("long", @LONG
����������ʯ·�����������������ש��������������ġ�����û
��ʲô�ˡ��ϱ��������ɵ����¹㳡������һ����ʯ·��
LONG);
  set("exits",([
	  "south":__DIR__"guangchang",
	  "north":__DIR__"qingshilu2",
	  ]));

  set("outdoors","yinkui");

  set("valid_startroom", 1);
  setup();
 
}

