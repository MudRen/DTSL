
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ݵ�");
  set ("long", @LONG
����Ƭ�ݵء��ϱ��ǻƺӵı��������������ߣ����Ǻ����ˡ�����
�紵��������һ����ɬ����Ϣ��
LONG);

  set("exits", ([ 
 "northeast":__DIR__"haibin1",
 "southwest":__DIR__"huanghebei",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

