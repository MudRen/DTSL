
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�������");
  set ("long", @LONG
�����ڹ�������ϣ�������ֺ�᳤���Ƕ��������������ţ�����
����ţ��ǳ����ǵ����ɵ�֮һ���ϱ�ͨ��Ĵ����������֡�
LONG);

  set("exits", ([ 
 "north":__DIR__"yadajie2",
 "south":__DIR__"xishidongkou1",
 "east":__DIR__"gmdajie5",
 "westup":__DIR__"gmqiao",
        ]));
   set("objects",([
	  __DIR__"npc/qinshubao":1,
	  ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

