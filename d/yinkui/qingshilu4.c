
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ʯ·");
  set ("long", @LONG
������һ����ʯ·��·�������Ϻõ���ש�̳ɡ������������ɵ���
�¹㳡��������������ģ�ƽʱû��ʲô�����
LONG);
  set("exits",([
	  "west":__DIR__"guangchang",
	  "east":__DIR__"qingshilu5",
	  ]));
  /*
  set("objects",([
      __DIR__"npc/fanan":1,
      ]));*/
  set("outdoors","yinkui");

  set("valid_startroom", 1);
  setup();
 
}

