
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��װ�");
  set ("long", @long
�����ǻ����ĺ�װ壬��������Թ��͵������������ľ�ɫ��
long);

  set("exits", ([ 
 "south":__DIR__"chuancang5",
 ]));
  set("outdoors","yangzhou");
  set("valid_startroom", 1);
  setup();
 
}

