
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIM"����"NOR);
  set ("long", @LONG
�����������ɵ�����Ϣ�ĵط������ϵı���ǳ����ң����ߵ�ǽ��
�����ż�������ͼ���м�����������������˯�����������������Щ
���ˡ�
LONG);
  set("exits",([
	  "north":__DIR__"lianwuchang",
	  ]));

  set("sleep_room",1);
  set("valid_startroom", 1);
  setup();
 
}

