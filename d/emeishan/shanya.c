
#include <ansi.h>
#include <job_money.h>
inherit ROOM;

int do_claw(string arg);
void create ()
{
  set ("short","ɽ��");
  set ("long", @LONG
������һ��ɽ�¡������кܶ�Ұ���Ĳ�ҩ�����ҽ��ר�ŵ������
��ҩ��
LONG);

  set("exits", ([ 
 "south":__DIR__"xuanya",
       ]));
   set("outdoors","emeishan");
 set("valid_startroom", 1);
  setup();
 
}

