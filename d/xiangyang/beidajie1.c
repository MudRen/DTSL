
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @LONG
�����������ı���֡�������������������ˡ����ڽ���ս�����꣬
���Խ��ϵ����˲��Ǻܶࡣ�����м�����ͷ�߹�����������һЩ�ֻ�����
������Ѱ��ͨ������
LONG);

  set("exits", ([ 
 "north":__DIR__"beidajie2",
 "south":__DIR__"guangchang",
        ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

