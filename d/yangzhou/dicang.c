
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ײ�");
  set ("long", @long
����ѻ���һЩѹ�����һЩ������𣬲���û�д�����Կ������
���õ���Щ���ڹ���������Ƶġ�
long);

  set("exits", ([ 
 "up":__DIR__"chuancang5",
 ]));
 
  set("valid_startroom", 1);
  setup();
 
}

