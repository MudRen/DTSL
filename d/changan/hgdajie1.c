
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�͹���");
  set ("long", @LONG
���Ǻ͹��֣��ϱ����ӳ����ǵĹ⻯�źͺ�ƽ��������ʮ�����֣�
��������������Ϣ����������涼�ǳ��������ϵ���Ҫ��������
LONG);

  set("exits", ([ 
 "north":__DIR__"xishixikou2",
 "south":__DIR__"xpdajie1",
 "east":__DIR__"guiyifang",
 "west":__DIR__"hepingfang",
       ]));
  set("objects",([
         __DIR__"npc/gongzi":1,
         ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

