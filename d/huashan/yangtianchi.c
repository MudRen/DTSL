
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @LONG
����ز���һ�׼������ӯ�ߡ��˳ر����ҳ���̫�ҳء�����
���Ӳ��󣬡���ͨ���ɴ����������ú����ԣ����Բ��磬�����ﶬ����
ˮʼ����һ��
LONG);

  set("exits", ([ 
 "northwest":__DIR__"liandanlu",
 "southup":__DIR__"luoyanfeng",
 "eastup":__DIR__"jintiangong",
       ]));
  /*set("objects",([
	  __DIR__"npc/yao":1,
	  ]));*/
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
