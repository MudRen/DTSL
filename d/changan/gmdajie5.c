
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�������");
  set ("long", @LONG
�����ڹ�������ϣ�������ֺ�᳤���Ƕ��������������ţ�����
����ţ��ǳ����ǵ����ɵ�֮һ�����澲���ĵġ��ϱ�ͨ��Ĵ���ǰ�
����֡�
LONG);

  set("exits", ([ 
 "north":__DIR__"ahdajie4",
 "south":__DIR__"ahdajie3",
 "east":__DIR__"guangchang",
 "west":__DIR__"gmdajie6",
 "northeast":"/d/cahc/hanguangmen",
        ]));
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

