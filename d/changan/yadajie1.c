
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�������");
  set ("long", @LONG
����������֣��������ӳ����ǵľ�ҫ�ţ��������������ƽ���ݹ�
�������������ڳ����������������������������У��������˴�����
�����а�С̯���ձ�����黨�ģ���ը�͸⡢�������ģ����ַǳ���
LONG);

  set("exits", ([ 
 "north":__DIR__"xishidongkou2",
 "south":__DIR__"xpdajie2",
         ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

