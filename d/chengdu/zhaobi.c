
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ʯ���ձ�");
  set ("long", @LONG
������һ��ʯ���ձڡ�ǽ�����и���������ͼ�������෱�࣬��ɽ
ˮ���������ȵȣ�һ�����ǳ�����������֮�֡��ձڵĴ���ʯҲ��
���е���Ʒ��
LONG);

  set("exits", ([ 
  
	  "south":__DIR__"paifang",
	  "north":__DIR__"neibao",
	
         ]));
  set("objects",([
	  __DIR__"npc/fangyimin":1,
	  ]));
 set("outdoors","chengdu");
  set("valid_startroom", 1);
  setup();
 
}
