
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��լ");
  set ("long", @LONG
�����ǹ���ص��������µĹ�Ա����ס�ĵط�����Ȼ��Щ���ӣ���
�ǲ�ʧ���
LONG);

  set("exits", ([ 
      "east":__DIR__"qinglongjie3",
  ]));
  set("valid_startroom", 1);
  setup();
 
}

