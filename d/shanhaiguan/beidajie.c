// /d/gaoli/beidajie
// Room in 山海关
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "北大街");
	set("long", @LONG
这里的路相当的宽，能容好几匹马车并行，长长的道路贯穿南北，
这里是山海关的北大街，因为山海关是塞外和中原必经之路，所以来往
的客商特别多，东边是山海关的驿站，西边是一家商行，南边是山海关
的中央广场。 
LONG
	);
set("outdoors", "/d/shanhaiguan");
set("exits", ([
		"south" : __DIR__"guangchang",
		"north" : __DIR__"beichengmen",
                "east" : __DIR__"yizhan",   
                "west" : __DIR__"xingyilong",      
	]));
set("objects",([
  __DIR__"npc/shangren":1,
 ]));
 
       setup();
	replace_program(ROOM);
}	
