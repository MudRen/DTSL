
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ˮ��");
  set ("long", @LONG
��ˮ���ǳ�͢���������������ר�ų���ˮ·��ͨ���ӵ���ʯ�ţ�
��ͷ�ȶ��ڹ�Ͻ��Χ�ڡ�
LONG);

  set("exits", ([ 
 "west":__DIR__"tianjie2",
         ]));
    set("valid_startroom", 1);
  setup();
 
}

