
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
���������ȡ��������μұ������������ȵ�ǽ���Ͽ̻���һЩ����
�ıڻ������෱�࣬��ɽˮ������ȡ��������㹤����������ʱ��һЩ
�μұ����Ӵ�������ԴҴ��߹���
LONG);

  set("exits", ([ 

  "east":__DIR__"zhengting",
  "west":__DIR__"xilang2",
       ]));
  set("objects",([
	  __DIR__"npc/yahuan":1,
	  ]));
  set("objects",([
	  "/d/clone/npc/liu":1,
	  ]));
  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

