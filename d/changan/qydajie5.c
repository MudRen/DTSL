
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
���������֣��ϱ����ӳ����ǵ������ź͵����š�����ʮ�����֣�
��������������Ϣ��
LONG);

  set("exits", ([ 
 "north":__DIR__"tydajie6",
 "south":__DIR__"qydajie4",
]));
   set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

