
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ǲ÷��");
  set ("long", @LONG
������������һ���÷�ꡣ����������·����۴󷽣������ϰ�ȴ
�������ƣ��·��ļ۸�Ӹ߲��£����Լ���û��ʲô�����������·���
�ſڵ������Ϸ���һ�鲼�ϣ�ǽ������һ��ֽ������д�ţ����콻����
LONG);

  set("exits", ([ 
 "west":__DIR__"beidajie2",
        ]));
 set("objects",([
	 __DIR__"npc/ma":1,
	 ]));
 set("valid_startroom", 1);
  setup();
 
}

