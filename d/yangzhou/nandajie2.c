
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ϴ��");
  set ("long", @LONG
���������ݳǵ��ϴ�֡����������Ŀ��˺ܶࡣ�ϱ߾�����������
�ֵļ���--�ϼ��С��ּۻ��ۺͳ�������������������ͷ��������һ
�Ҿ�¥��Ʈ��������ľ��㣬�����ȵ���������Ŀ��˵Ļ�ȭ����ʱ��
���ڴ������������ķ����ҡ�
LONG);

  set("exits", ([ 
 "west":__DIR__"jiulou",
 "north":__DIR__"nandajie1",
 "southwest":__DIR__"nanjishi",
        ]));
  set("objects",([
	  __DIR__"npc/shangren":1,
	  "/d/clone/npc/yushiji":1,
	  ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

