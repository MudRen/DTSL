
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ӻ���");
  set ("long", @long
�����ǻ�������ӻ��ĵط���������ȥ���Ǻ�װ��ˡ�
long);

  set("exits", ([ 
 "north":__DIR__"chuancang6",
 "down":__DIR__"dicang",
 "south":__DIR__"chuancang2",
 ]));
 
  set("valid_startroom", 1);
  setup();
 
}

