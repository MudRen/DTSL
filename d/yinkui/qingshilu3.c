
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ʯ·");
  set ("long", @LONG
����������ʯ·��������������ġ�����û��ʲô�ˡ�����������
�ɵ����¹㳡�������������ɵ����䳡�����ﲻʱ���������ߺ������
LONG);
  set("exits",([
	  "east":__DIR__"guangchang",
	  "west":__DIR__"lianwuchang",
	  ]));

  set("outdoors","yinkui");

  set("valid_startroom", 1);
  setup();
 
}

