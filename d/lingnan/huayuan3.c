
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","��԰");
  set ("long", @LONG
�����Ǹ���԰���������˺ܶ�����Ļ��ݣ�һ��紵���������˱ǡ�
Ⱥ�����涷�ޣ����࿪�š��м����������������޼��Ż��ݡ��ϱ���һƬ
�ݵء�
LONG);

  set("exits", ([ 

  "north":__DIR__"xiaojing2",
 "south":__DIR__"caodi2",
     ]));

  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

