
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
��������ɽ·���ϱ߾��ǳ����ı��ˣ��������������ˮ��������
��ʱ�д�ӵĹٱ�����������߹����ŵ�·�ϵİ��ն���������ȥ��
LONG);

  set("exits", ([ 

  "northeast":__DIR__"shanlu2",
  "south":__DIR__"caodi2",
       ]));
  
set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

