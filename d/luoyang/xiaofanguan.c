
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","С����");
  set ("long", @LONG
������һ��С���ݡ����������ǽ�����ͻȻ���࣬��������һֱ��
�á���С��æ��æȥ�ܸ���ͣ��ֻ������������ʿ���������̸���ۣ�
�Ա߻�������������̳�ӡ��ƹ�����������ϸ�����ʣ����̴����ž��
�졣
LONG);

  set("exits", ([ 
      "west":__DIR__"qinglongjie1",
  ]));
  set("objects",([
      __DIR__"npc/xiaoer3":1,
  ]));
  set("valid_startroom", 1);
  setup();
 
}

