
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����¯");
  set ("long", @LONG
����¯�ഫΪ̫���Ͼ����ƽ𵤵ĵط����ʷ��ֳƵ��塣��������
����������ģ��С����ǰ�������Ƶ�¯һ�����⡶����ͼ�ᡷ�أ���¯
�����࣬�߿����ߡ���������¼�������ص����Ӷ��Ӵ�������������
���¼������ڴˡ�
LONG);

  set("exits", ([ 
 "northdown":__DIR__"julingzu",
 "southeast":__DIR__"yangtianchi",
 "east":__DIR__"pubu",
       ]));
  /*set("objects",([
	  __DIR__"npc/yao":1,
	  ]));*/
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
