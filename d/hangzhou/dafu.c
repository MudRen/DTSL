
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��֮��");
  set ("long", @LONG
������һ����֮�ҡ���˵��ҵ�����������Ǻ��ݵ��׸�������
Ů������Ҫ���б������ף������˲���������ʿ��
LONG);

  set("exits", ([ 

  "east":__DIR__"nandajie1",
  "enter":__DIR__"tingyuan",
      ]));

set("outdoors","hangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

