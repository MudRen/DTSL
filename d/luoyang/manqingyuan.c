
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"����Ժ"NOR);
  set ("long", @LONG
����������������¥����Ժ��ÿ��������������������м���Ư
����Ů�����������͡�����Ҳ���������İ����������������Χ����
��Ժ�����˾���������İ����Ϲ�����
LONG);

  set("exits", ([ 
	  "east":__DIR__"beijie3",
	  "enter":__DIR__"huayuan",
         ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}
