
#include <ansi.h>
#include <job_money.h>
inherit ROOM;


void create ()
{
  set ("short","С��");
  set ("long", @LONG
������С���ͨ�İ����ǲ���������ġ�ֻ������Ĳ���������
��ʱ���ֽ�����̵�����������һȺ������������������Ÿֵ����ƺ�
��������ȥ�����γ���������м���׳����������һ������ģ���˵�
Ǯ�ơ�
LONG);

  set("exits", ([ 
 "southwest":__DIR__"xiaoxiang1",
        ]));
  set("outdoors","xiangyang");
set("valid_startroom", 1);
  setup();
 
}

