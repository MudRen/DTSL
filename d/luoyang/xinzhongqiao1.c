
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIC"������"NOR);
  set ("long", @long
���������������Ĵ�����֮һ���������ˮ�������������³�����
֮�⣬���ڿ����������Ƕ����б�ͳ�ε�һ����̶��ѡ�
long);

  set("exits", ([ 
  

  "north":__DIR__"tianjie2",
  "southup":__DIR__"xinzhongqiao2",
         ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

