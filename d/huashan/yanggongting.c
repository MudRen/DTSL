
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","Сͤ");
  set ("long", @LONG
������һ��С����ͤ������İ���ǳ��򵥣�ֻ�м���ʯ���ӡ�ʯ
���ӡ��м����ο�����������Ϣ���졣���ܾ�ɫ�����������������
���ɵ����˸е������
LONG);

  set("exits", ([ 
 "northeast":__DIR__"shanlu4",
       ]));
  /*
  set("objects",([
	  __DIR__"npc/yao":1,
	  ]));*/
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
