
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"��ʯ·"NOR);
  set ("long", @LONG
������ͨ�������ʹ��󹬵���ʯ·������ÿ���ϳ����˳���Ҫ����
������������ǻʹ����صأ���͢�����ر���������������·��
������������໨�ݡ�
LONG);

  set("exits", ([ 
  
  "north":__DIR__"beilang1",
  "east":__DIR__"zhiban-room",
  "south":__DIR__"houdian",
         ]));
  set("objects",([
	  __DIR__"npc/guanbing":4,
	  ]));
  
  set("valid_startroom", 1);
  setup();
 
}

