
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @LONG
������ڱ�����������һ��ƽ̨�ϡ���ʱ�Ժ��������̨;�м�
�е��ţ��Ű�ҷ�𣬼�����ǵ��̨��ԭ��������ʯ��������ܴ󣬺���
�������Գɵ�Ժ���䴦�������ţ���ľ��ӳ��������Ȼ�ɾ����Ŵ���
����ʿ���������������ԡ�
LONG);

  set("exits", ([ 
 "northdown":__DIR__"yuquanyuan",
 "westdown":__DIR__"baichixia",
 "eastup":__DIR__"woniutai",
       ]));
  /*set("objects",([
	  __DIR__"npc/yao":1,
	  ]));*/
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
