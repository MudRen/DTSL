
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��Ů��");
  set ("long", @long
���ﱱ�������ţ���ͨ���Ĵ�֣����������ţ���������һ����Ҫ
�Ľ�ͨҪ����
long);

  set("exits", ([ 
  
  	"north":__DIR__"kaiheqiao3",
  	"west":__DIR__"shennvdi1",
  	"east":__DIR__"shennvdi3",
  	"south":__DIR__"changxiajie1",
  
  ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

