// /d/gaoli/chengqiangshang1
// Room in 山海关
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "城墙上");
	set("long", @LONG
你站在山海关的城墙上，因为军事的原因山海关的城墙修的特别坚
固，北面是长城的一座隘口，西边是山海关的南城楼。
LONG
	);
set("outdoors", "/d/shanhaiguan");
set("exits", ([
		"north" : __DIR__"aikou",
	        "west" : __DIR__"nanchenglou",
            	"westdown" : __DIR__"nanchengmen",
	]));
       setup();
	replace_program(ROOM);
}	
