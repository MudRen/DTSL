
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"青竹亭"NOR);
	set("long", @LONG
这里是青竹亭。这里种了很多的青竹。平时很少有人到这里来。这
里有一幅对联：「碧竹节节  相思段段」。
LONG);
	set("exits", ([
	     
		
		"north":__DIR__"echanglang2",
		"south":__DIR__"baiyuanshi",						
	]));
       set("objects",([
          __DIR__"npc/shanqing":1,
          ]));
        
       set("valid_startroom", 1);   
       set("outdoors", "青石路");  
	setup();
       
       
}

