
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIB"有间客栈"NOR);
	set("long", @LONG
这里是一间普通的客栈，门上悬挂着一个歪的牌匾，上面写着有间
客栈四个大字。门前的两个大灯笼已经破碎，在微风中不住地摇晃着。
客栈的门已经破碎，只剩几块碎木头悬挂在那里。里面的桌子、椅子也
已经破碎，凌乱地散落在地上。客栈的窗户已经破旧，在微风的吹拂下
晃动着。一阵冷风吹来，你不禁打了个寒战。几只乌鸦哑哑地叫着从你
头上飞过。
LONG);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  		"north" : __DIR__"xiaolou",
	]));
	
	set("objects",([
		__DIR__"npc/hotel_xiaoer":1,
	]));
	

	set("no_exert",1);
	setup();
	replace_program(ROOM);
}
