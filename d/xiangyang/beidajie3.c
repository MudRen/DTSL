
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @LONG
�����������ı��֡�������������ı����ˡ���������˲��Ǻܶࡣ
������һ�Ҳ�ݣ�[����Ʈ����]�ķ�������ӭ����չ����Զ�Ϳ��������
������
LONG);

  set("exits", ([ 
 "north":__DIR__"beimen",
 "south":__DIR__"beidajie2",
 "west":__DIR__"chaguan",
        ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

