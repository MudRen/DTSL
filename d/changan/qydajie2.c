
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
 "north":__DIR__"qydajie3",
 "south":__DIR__"qydajie1",
         ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

