
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���칬");
  set ("long", @LONG
���칬���ȫΪ��Ƭ���ߣ�����������Ժǰ���ű߻������ӹ�¥��
�����Ƭ���֣�֦��Ҷï�����йŹ���������ּ�С������ɫ�ǳ�������
���������Ĵ�����������ɽ��������Բ�çç��
LONG);

  set("exits", ([ 
 "westdown":__DIR__"yangtianchi",
 "southeast":__DIR__"shanlu4",
        ]));
  /*set("objects",([
	  __DIR__"npc/yao":1,
	  ]));*/
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
