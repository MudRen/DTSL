
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
����������·�������Ǻ�����һ��紵�����д�����ɬ����Ϣ����
���Ѿ��Ǳ����ˣ�������Щ���ˡ�
LONG);

  set("exits", ([ 
 "west":__DIR__"haibin7",
 "northeast":__DIR__"shanlu7",
 "south":"/d/gaoli/jiangbei",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

