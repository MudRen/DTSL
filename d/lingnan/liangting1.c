
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","��ͤ");
  set ("long", @LONG
�����Ǹ���ͤ����������μұ������䳡�ˡ���ʱ�������ȵ�������
��ͤ�������ϻ��˺ܶྫ���ıڻ������ǳ�������Ĺ���֮�֡�
LONG);

  set("exits", ([ 

   "west":__DIR__"yuedongmen",
   "east":__DIR__"wuchang",
       ]));

  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

