
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","̫����");
  set ("long", @LONG
������̫�����ǰ��̫���š�������ȥ���������컧������������ 
�ݶ�����ͭ�ߣ������������֮״��Ρ��׳������ҫ��Ŀ��������ʿ��
������������Ѳ�ӡ�
LONG);

  set("exits", ([ 
 "northup":__DIR__"taijidian",
 "south":__DIR__"tjgc",
        ]));
  set("objects",([
          "/d/cahc/npc/xiaoyu":1,
          ]));
   set("outdoors","changan");
   set("valid_startroom", 1);
  setup();
 
}

