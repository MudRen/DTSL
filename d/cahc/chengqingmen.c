
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
�����ǳ�����ǰ�ĳ����š�������ȥ���������컧������������ 
�ݶ�����ͭ�ߣ������������֮״��Ρ��׳������ҫ��Ŀ��������ʿ��
������������Ѳ�ӡ�
LONG);

  set("exits", ([ 
 "northup":__DIR__"chengqingdian",
 "south":__DIR__"guangyunmen",
 "west":__DIR__"xuxunyuan",
        ]));

  set("objects",([
           __DIR__"npc/xuanjiabing":2,
        ]));
 
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

