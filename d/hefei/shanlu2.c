
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
��������ɽ·��������ľ���ƣ��������ţ����������˿������پ�
����һˬ����ʱ�д�ӵĹٱ�����������߹����ŵ�·�ϵİ��ն�����
����ȥ��
LONG);

  set("exits", ([ 

  "northwest":__DIR__"shanlu1",
  "southwest":__DIR__"shanlu3",
       ]));
  
set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

