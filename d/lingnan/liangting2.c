
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","��ͤ");
  set ("long", @LONG
����������ͤ����ͤ�������ϻ��˺ܶྫ���ıڻ������ǳ�������
�Ĺ���֮�֡����߾������ǵ������ˡ��м���Ѿ��������������롣
LONG);

  set("exits", ([ 

  "east":__DIR__"woshi2",
  "south":__DIR__"qingshilu2",
      ]));

  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

