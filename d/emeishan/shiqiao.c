
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ʯ��");
  set ("long", @LONG
��������ʯ�š���������ǰ����ǡ�ÿ��Կ���һ�����ʯ�����ڿ�
�ƹ��������������������ҡ�һ���ٲ����������£��ֺ��Ƶ�ˮ������
�컯֮����ʵ��������̾���ѡ�
LONG);

  set("exits", ([ 
 "east":__DIR__"jietuopo",
 "southup":__DIR__"jingxinan",
      ]));
  set("outdoors","emeishan");
 set("valid_startroom", 1);
  setup();
 
}

