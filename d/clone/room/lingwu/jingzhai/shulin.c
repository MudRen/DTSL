
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
������һƬ�����������֡����߾���������İ�β�塣������ľï
ʢ���������ﺮ�粻�Ǻܴ󡣵��ϵĻ�ѩ�ܺ񣬼�����û��ϥ�ǡ���˵
���ﾭ����Ⱥ�ǳ�û���㲻��С��������
LONG);

  set("exits", ([ 
 "west":__DIR__"wolong7",
 "east":__DIR__"shulin",
 "south":__DIR__"shulin",
 "north":__DIR__"shulin",
        ]));
  set("outdoors","wolongling");
  
  set("valid_startroom", 1);
  setup();
 
}

