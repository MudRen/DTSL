
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ٳ�Ͽ");
  set ("long", @LONG
�ٳ�Ͽ�ǵǻ�ɽ�ĵڶ����վ������ٳ�Ͽ��Ҳ�С������¡�������
һ��Σʯ���ţ�ֱ���Ʊ�����������η�ĵط���Ͽ�����ڼ�����Ҫ��
����һ���м�ȴ������ʯ��ſ����˴�ʯͷ���������ս�ľ�������
ʯ������ڼ��������
LONG);

  set("exits", ([ 
 "eastup":__DIR__"konglingfeng",
       ]));
  /*set("objects",([
	  __DIR__"npc/yao":1,
	  ]));*/
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
