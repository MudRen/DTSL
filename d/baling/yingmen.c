
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��Ӫ����");
  set ("long", @LONG
������������פ����Ӫ�����Ｘ��û�����˽��������Ķ��ǹٱ���
��ʱҲ����������������ſ�������ʿ����վ�ڣ�����һ�������
���ý����ġ�
LONG);

  set("exits", ([ 

  "southeast":__DIR__"guandao3",
  "north":__DIR__"yingdi",
       ]));
set("objects",([
	  __DIR__"npc/bing":2,
	  ]));
set("outdoors","baling");
  
  set("valid_startroom", 1);
  setup();
 
}

