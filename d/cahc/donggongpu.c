
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
������Ƕ������ˣ���ר�Ű����̫���йص�һ������Ĳ��ţ�̫
���ǹ��ҵ�δ����һ�ж������������Դ�̫�ӵĲ������������ල��
������ҫ����������
LONG);

  set("exits", ([ 
 "west":__DIR__"tianjie1",
 
        ]));
  set("valid_startroom", 1);
  setup();
 
}

