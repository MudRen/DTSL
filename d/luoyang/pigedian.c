
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","Ƥ���");
  set ("long", @long
һ��������������̸о���һ�����˶��ĵ���ζ�˱Ƕ�����û��
��������Ǵ���Ƥ��Ĺ����в�������ζ��
long);

  set("exits", ([ 
      "north":__DIR__"luoshuidi1",
  ]));

  set("valid_startroom", 1);
  setup();
 
}

