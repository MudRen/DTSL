
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�������");
  set ("long", @LONG
�����ڹ�������ϣ�������ֺ�᳤���Ƕ��������������ţ�����
����ţ��ǳ����ǵ����ɵ�֮һ�����澲���ĵġ��ϱ�ͨ��Ĵ������
�ɴ�֡�
LONG);

  set("exits", ([ 
 "north":__DIR__"wxdajie2",
 "south":__DIR__"dongshixikou1",
 "east":__DIR__"dongshibeikou2",
 "west":__DIR__"gmdajie3",
        ]));
  set("objects",([
	   __DIR__"npc/chengyaojin":1,
	   ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

