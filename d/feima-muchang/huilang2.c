
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"����"NOR);
  set ("long", @LONG
�����������ȡ����ߵ�ǽ���Ͽ̻��źܶ�ɽˮ�Ļ���һ����֪����
�Ǹ����Ĺ��������������������������Ƽ򵥣���ʵ�򰵲��˻���֮����
���������ƺ����ѳ�ȥ�ˡ�
LONG);

  set("exits", ([ 
	  "east":__DIR__"huilang"+(1+random(4)),
	  "south":__DIR__"huilang"+(1+random(3)),
	  "west":__DIR__"huilang"+(1+random(3)),
	  "north":__DIR__"huilang"+(1+random(1)),
	  
   ]));

  
  set("valid_startroom", 1);
  setup();
 
}

void reset()
{
   
  set("exits", ([ 
	  "east":__DIR__"huilang"+(1+random(4)),
	  "south":__DIR__"huilang"+(1+random(3)),
	  "west":__DIR__"huilang"+(1+random(3)),
	  "north":__DIR__"huilang"+(1+random(1)),
   ]));
}