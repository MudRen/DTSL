
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short","��·");
  set ("long", @LONG
������һ����·�����в�ʱ���Դ�����ˮ������������������һ��
��ͤ�����治ʱ����̸Ц��������
LONG);

  set("exits", ([ 
	  "north":__DIR__"juyiting",
	  "east":__DIR__"tulu1",
	  "west":"/d/clone/room/orgsaferoom/dajiang/juyitang",
    ]));
set("outdoors","dajiang");
  /*set("objects",([
	  __DIR__"npc/dizi":2,
	  ]));*/
  set("valid_startroom", 1);
  setup();
 
}

