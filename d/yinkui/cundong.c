
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�嶫");
  set ("long", @LONG
�����Ǵ��ӵĶ��档������Ӿ�˵�Ѿ��ܾ�û����ס�ˡ���������
�����ģ���������ȥ���
LONG);

  set("exits",([
	  "east":__DIR__"xiaolu1",
	  "west":__DIR__"cunzhong",
	  ]));
  set("outdoors","yinkui");
  set("valid_startroom", 1);
  setup();
 
}

