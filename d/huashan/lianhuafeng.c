
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
������Ϊһ��������ʯ����Ȼ��ɡ���������ǧ�̣��Ƶ�����أ�
�䶸��Ρ�롢����ͦ��֮���ǻ�ɽɽ��֮������˹��˳��ѻ�ɽ����
ɽ�������弫ĿԶ��������Ⱥɽ�������ϼ��������Ұ��������μ������
�����������������񸮣��������һɨ���ա�
LONG);

  set("exits", ([ 
 "eastdown":__DIR__"julingzu",
       ]));
  /*set("objects",([
	  __DIR__"npc/yao":1,
	  ]));*/
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
