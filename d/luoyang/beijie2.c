
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @long
�����������ı���֣���ȥ��������ջ������������������������
��Ժ��
long);

  set("exits", ([ 
  
      "south":__DIR__"beijie1",
      "north":__DIR__"beijie3",
         ]));
  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
}

