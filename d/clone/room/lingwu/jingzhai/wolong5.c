
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
��������������ϵ������壬������������������Ƕ��͵����¡�
��������ȥ������ԶԶ����������ĸ���ƺ�����������ҫ�£���ѩ��
��Ĺ�â�Ѹ���ƺװ�εĺ���һ����ӡ������������������ǡ�
LONG);

  set("exits", ([ 
 "westdown":__DIR__"wolong2",
 "eastup":__DIR__"wolong6",
        ]));
  set("outdoors","wolongling");
  
  set("valid_startroom", 1);
  setup();
 
}

