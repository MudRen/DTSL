
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIC"�����"NOR);
  set ("long", @long
��������������Ĵ�����֮һ����Ҳ������������һ����־������
������������������Χ�ľ�ɫ�ں���һ�𣬲���������һ����
long);

  set("exits", ([ 
  

  "northup":__DIR__"tianjinqiao2",
  "south":__DIR__"luoshuidi2",
         ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

