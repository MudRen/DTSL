
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�������");
  set ("long", @LONG
�����ڹ�������ϣ�������ֺ�᳤���Ƕ��������������ţ�����
����ţ��ǳ����ǵ����ɵ�֮һ�����澲���ĵġ��ϱ�ͨ��Ĵ���ǰ�
�ϴ�֡�
LONG);

  set("exits", ([ 
 "north":__DIR__"asdajie4",
 "south":__DIR__"asdajie3",
 "east":__DIR__"gmdajie3",
 "west":__DIR__"guangchang",
 "northwest":"/d/cahc/anshangmen",
        ]));
  set("objects",([
   __DIR__"npc/xiaojie":1,
   ]));
   
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

