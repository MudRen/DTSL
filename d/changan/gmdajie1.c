
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�������");
  set ("long", @LONG
�����ڹ�������ϣ�������ֺ�᳤���Ƕ��������������ţ�����
����ţ��ǳ����ǵ����ɵ�֮һ�����澲���ĵġ��ϱ�ͨ��Ĵ���ǳ�
����֡�
LONG);

  set("exits", ([ 
 "north":__DIR__"csdajie2",
 "south":__DIR__"dongshidongkou1",
 "east":__DIR__"dongmen",
 "west":__DIR__"dongshibeikou1",
        ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

