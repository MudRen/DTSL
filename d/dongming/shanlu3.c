
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "山路");
	set("long", @LONG
这里是条山路。这里是江西的境地了。这里的行人渐渐多了起来。
四周杂草丛生，只有几只野兔不时从你的脚前跑过。
LONG);
	set("exits", ([
		"south":__DIR__"shanlu2",
		"northwest":__DIR__"shanlu4",
		]));
      set("valid_startroom", 1);   
       set("outdoors", "青石路");  
	setup();
       
       
}

