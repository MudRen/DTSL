
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
  

  "northup":__DIR__"xinzhongqiao2",
  "south":__DIR__"tianjie3",
         ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

