
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ݵ�");
  set ("long", @LONG
����Ƭ�ݵء��ϱ߾��������ĸ��ʺ���������һƬ���֣�Ҳ��֪��
��û��Σ�ա��뵽�����������㲻���ӱ�С��������
LONG);

  set("exits", ([ 
 "north":__DIR__"shulin1",
 "southwest":__DIR__"gaoyouhu",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

