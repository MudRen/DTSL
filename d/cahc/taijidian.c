
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","̫����");
  set ("long", @LONG
������Ǵ��ƵĽ�𽱦�����Ҫ��ȫ�������ﴦ�����ڳ��軪
���������������֮״����ΰ׳����������ԡ����������������Ժ���
�ʻ����Ŵ��ϲ�Ƕ���⻨���ƣ��²���������ͼ������龴������Կ���
�Ƶ��̽�ͭҶ�����ڽ�ש�̵أ������豦���������Ŵ��Ƶ���������Ԩ�� 
LONG);

  set("exits", ([ 
 "north":__DIR__"liangyidian",
 "southdown":__DIR__"taijimen",
        ]));
  set("objects",([
          "/d/changan/npc/liyuan":1,
          "/d/cahc/npc/wei":1,
          ]));

   set("valid_startroom", 1);
  setup();
 
}

