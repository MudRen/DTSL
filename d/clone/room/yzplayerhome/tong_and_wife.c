
inherit ROOM;
#include <ansi.h>
void create()	
{
	set("short",HIG"˪����"NOR);
	set("long", @LONG
������˪�����ˡ��������Ů��������������Ȼ�����򸾶�
�����ڽ����϶����������������ָ��֡�������ͨ�������̳���
���ϡ��쵶��һ�ɡ�������һ��С�ݣ�������������Ȼ�������ˡ�
LONG);
    set("exits", ([
	        "east" : __DIR__"nandajie1",
	        "west":__DIR__"tong_wife_woshi",
 	]));
      set("no_fight",1);
      setup();
      replace_program(ROOM);
	
}
