
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
�����������ɳ��ϱ߲����������ˡ����ϵı�������������롣ǽ
�Ϲ���һ�����������еİ��費�Ǻܶ࣬�Ե���Щ���塣û���������
��û���˸������볤�ϵ����ҵġ�
LONG);
  set("exits",([
	  "east":__DIR__"xiaojing1",
	  ]));

  set("objects",([
	  __DIR__"npc/bianbu-fu":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

