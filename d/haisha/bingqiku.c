
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short","������");
  set ("long", @LONG
�����Ǻ�ɳ��ı������ˣ�������Ÿ��ָ����ı�����������ɢ��
�ذڷ���һ�أ�������ɳ��������д������ˡ�
LONG);

  set("exits", ([ 

  "southwest":__DIR__"caodi1",
         ]));
  /*set("objects",([
	  __DIR__"npc/bing":2,
	  ]));*/
  set("valid_startroom", 1);
  setup();
 
}

