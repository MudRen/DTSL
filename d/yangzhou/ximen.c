
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"����"NOR);
  set ("long", @LONG
���������ݳǵ����š���������˽������������������Թž��ǽ�
ͨ��Ŧ�������̻�ʤ�أ���Ȼ�����˺ܶ��ˡ������м����ٱ��������
���������ˡ�
LONG);

  set("exits", ([ 
 "east":__DIR__"xidajie1",
 "west":__DIR__"guanlu1",
 "northwest":"/d/jiujiang/dalu4",
        ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  __DIR__"npc/wujiang":1,
	  ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

