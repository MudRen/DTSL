
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","Сʯ·");
  set ("long", @LONG
��������Сʯ·�����ﲻʱ�ؿ��Կ��������ɵĵ��ӡ��ϱ߾�����
���ɵ�ɽ���ˡ�������һ����԰��������Ӱϡ�٣��ǳ��ž���͸©��һ
�ɹ�������ա�
LONG);
  set("exits",([
	  "south":__DIR__"door",
	  "north":__DIR__"huayuan",
	  ]));

  set("outdoors","yingui");
  set("valid_startroom", 1);
  setup();
 
}

