
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
����������ɽ�����յ�֮һ������ʲԺ�ɫ��������������������
�������ƺ������ٷ�����Ͽ�ȣ���Լ�����ף��������ߣ���ͻ��
�գ��������������ߣ������ҡ�������ƶˣ����շǳ���
LONG);

  set("exits", ([ 
 "northdown":__DIR__"woniutai",
 "southup":__DIR__"wuyunfeng",
       ]));
  /*set("objects",([
	  __DIR__"npc/yao":1,
	  ]));*/
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
