
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"��̲"NOR);
	set("long", @LONG
�����Ǻ�̲��һ�󺣷紵�����������ҡ��ϱ���һƬ���֡���ʱ��
���ֳ��ĳ�һ��ֻҰ�ã�Ȼ����Ѹ�ٵ��ܿ���
LONG);
	set("exits", ([
		"west":__DIR__"haitan1",
                "north":"/d/quest/dmchuifa/haitan",
		"southeast":__DIR__"shulin2",
		
	]));
	set("objects",([
	  __DIR__"npc/haigui":1,
	  ]));
      set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

