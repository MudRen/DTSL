
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
������һ��ɽ·��������һ�������ɽ�����в�����������˲���
�ܶ࣬��������������Ⱥ��������Ϊ��Ԥ��ǿ����һ��紵����������
���ɳ��һ�ɲ���֮����Ȼ������
LONG);

  set("exits", ([ 
"west":__DIR__"guanlu2",
"northeast":__DIR__"bianquemu",
"southeast":__DIR__"shanlu2",
        ]));
 set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

