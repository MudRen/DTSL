
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
��������������ϵ������壬������������������Ƕ��͵����¡�
��������ȥ������ԶԶ����������ĸ���ƺ�ͷ����£������￴ȥ����
��������ף�ֻ�м����������±ߵ������ڸ������������֣�����
����
LONG);

  set("exits", ([ 
 "westdown":__DIR__"wolong5",
 "eastdown":__DIR__"wolong7",
        ]));
  set("outdoors","wolongling");
  
  set("valid_startroom", 1);
  setup();
 
}

