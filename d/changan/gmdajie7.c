#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�������");
  set ("long", @LONG
�����ڹ�������ϣ�������ֺ�᳤���Ƕ��������������ţ�����
����ţ��ǳ����ǵ����ɵ�֮һ�����澲���ĵġ��������ϱ�ͨ��Ĵ�
���Ǻ͹��֡�
LONG);

  set("exits", ([ 
 "north":__DIR__"hgdajie2",
 "south":__DIR__"xishixikou1",
 "east":__DIR__"xishibeikou1",
 "west":__DIR__"ximen",
        ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}


