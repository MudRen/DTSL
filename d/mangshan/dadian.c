
#include <ansi.h>
#include <job_money.h>
inherit ROOM;


void create ()
{
  set ("short",HIR"���"NOR);
  set ("long", @LONG
�������Ͼ��۵�����������̫���Ͼ���ʯ�񣬵����Ѿ�������
�ҳ����Ա߷��ż������ź�ľ�㣬��Ҳ�������������Ծ��ˡ�һ��΢��
������һ����ɪ����֮����Ȼ������
LONG);

  set("exits", ([ 

  "south":__DIR__"tingyuan",
        ]));

  set("valid_startroom", 1);
  setup();
 
}

