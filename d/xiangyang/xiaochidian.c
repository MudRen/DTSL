
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ζС��");
  set ("long", @LONG
������һ��С�Ե꣬����ķ��˱��һ�������˺ܶ��ˡ�ֻ����
�ڹ���һ�������������д���ĸ����֣���ζС�ӡ��ſڻ�����һ����
�ӣ�д��ÿ��Ĳ��ס���С��������ȥ��æ����ͣ��
LONG);

  set("exits", ([ 
 "north":__DIR__"xidajie2",
        ]));
  set("objects",([
	  __DIR__"npc/xiaoer3":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

