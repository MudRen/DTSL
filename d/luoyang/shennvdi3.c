
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��Ů��");
  set ("long", @long
�ߵ������ɫ����һ�䣬��ˮ������ת�˸��䣬�������������
����һ��������Ů����Ҳ��Ů���������ֵ�������
long);

  set("exits", ([ 
  
  	"west":__DIR__"shennvdi2",
  	"east":__DIR__"dongbianmen2",
  
  ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

