
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ϼ���");
  set ("long", @LONG
���������ݳǵ������ֵļ���--�ϼ��С������������������ַǷ���
�����кܶ�С�ԣ����꣬��������Ļ��Ƕ����һ�Ұ��ӵꡣ�����кܶ�
���յģ���ˣ�ģ���ʱ�������Ƚкõ�������
LONG);

  set("exits", ([ 
 "east":__DIR__"baozidian",
 "northeast":__DIR__"nandajie2",
 "southeast":__DIR__"nandajie3",
 "west":__DIR__"zahuopu",
        ]));
  set("objects",([
	  __DIR__"npc/zhongnian":1,
	  "/d/clone/npc/feiyun":1,
	  ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

