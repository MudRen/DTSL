
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"��̲"NOR);
	set("long", @LONG
�����Ǻ�̲��һ�󺣷紵�����������������Щ�����ˡ��ϱ���һ
�����£�ƽʱ��������ȥ���
LONG);
	set("exits", ([
		"southwest":__DIR__"shanya2",
		"east":__DIR__"haitan1",
	]));
	set("objects",([
	   __DIR__"obj/yezishu":1,
	   ]));
      set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

