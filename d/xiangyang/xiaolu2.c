
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","С·");
  set ("long", @LONG
������һ��С·����������Կ���������ӿ�Ĳ��Ρ����･���Ե�
��Щ�����ˡ���ʱ�д�ӵĹٱ�����������߹����ŵ�·�ϵİ��ն���
������ȥ������羰������ɽˮ�续���������¡�
LONG);

  set("exits", ([ 
 "northwest":__DIR__"xiaolu1",
 "south":__DIR__"jiangbei",
        ]));
 set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

