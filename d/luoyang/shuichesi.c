
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ˮ����");
  set ("long", @LONG
��������ռ�ع�󣬼�ʹ������Ӵ�����䣬��Ȼ���ⲻ�˻��ֵ�
Σ�գ����������Ȼ���йٷ���ˮ������ִ��սʱ��ƽʱ�ľȻ�����
LONG);

  set("exits", ([ 
      "east":__DIR__"qinglongjie1",
  ]));
  set("valid_startroom", 1);
  setup();
 
}

