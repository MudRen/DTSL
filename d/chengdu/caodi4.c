
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ݵ�");
  set ("long", @LONG
������Ƭ�ݵء�����ϸ������������ʮ������������Ǹ����䳡��
��ʱ�����ﴫ�����ȵ��������м������𱤵��Ӵ�������ԴҴ��߹���
LONG);

  set("exits", ([ 
	  "north":__DIR__"wuchang",
	  "south":__DIR__"xilang2",
	  "west":"/d/clone/room/orgsaferoom/duzun/duzuntang",
        ]));
 set("outdoors","chengdu");
  set("valid_startroom", 1);
  setup();
 
}
