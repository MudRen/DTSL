
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
�����������������𷻡��������ߣ����������������ˡ���������
��˷���������Ƥ��ҩඣ����ΰٲ������鲻ҪǮ���������Ǻ�«ඣ�
�����ִ࣡��... ...
LONG);

  set("exits", ([ 
  

  "north":__DIR__"luoshuidi2",
  "south":__DIR__"baihujie2",
         ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

