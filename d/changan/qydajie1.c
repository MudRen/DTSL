
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
���������֣��ϱ����ӳ����ǵ������ź͵����š�����ʮ�����֣�
��������������Ϣ��������һ��լԺ��
LONG);

  set("exits", ([ 
 "north":__DIR__"qydajie2",
 "south":__DIR__"xpdajie5",
 "east":__DIR__"jingzhaolian",
        ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

