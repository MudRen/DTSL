
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "土路");
	set("long", @LONG
这里是一条土路。经常有难民从这里走过。这里风景秀丽，山水如
画，空气清新。地上有很多漂亮的野花、蒲公英等植物。不时有野兔从
你的脚旁跳过。
LONG);
	set("exits", ([
		"southwest":__DIR__"tulu1",
		"north":__DIR__"tulu3",
		]));
      set("valid_startroom", 1);   
       set("outdoors", "青石路");  
	setup();
       
       
}

