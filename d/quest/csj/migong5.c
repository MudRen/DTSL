
inherit ROOM;
#include <ansi.h>

void create()
{
	set("short",HIB"����"NOR);
	set("long", @LONG
������һ�����ң����ܺڶ����ģ����������۸��ӣ��ƺ���������
·��
LONG);
        set("exits",([
          "east":__DIR__"migong2",
          "west":__DIR__"migong6",
          "south":__DIR__"migong3",
          "north":__DIR__"migong1",
          "up":"/d/yangzhou/feiyuan",
          ]));
	setup();      
}
