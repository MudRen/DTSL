
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ��");
  set ("long", @LONG
�����Ǹ�ɽ�ȣ�����Ⱥɽ���ƣ���ɫ�����������кܶ�Ư����Ұ����
�ѹ�Ӣ��ֲ���ʱ��Ұ�ô���Ľ��������������ɽ������һ�����
LONG);

  set("exits", ([ 

  "westup":__DIR__"shanlu5",
 "northeast":__DIR__"shanlu7",
 "south":__DIR__"caodi1",
 "northup":"/d/job/sjbjob/biyunfeng",
         ]));
  set("objects",([
	  __DIR__"npc/monkey":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

