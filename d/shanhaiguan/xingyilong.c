// /d/gaoli/xingyilong
// Room in 山海关
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "兴义隆");
	set("long", @LONG
这是一家专买卖皮货的店铺，兴义隆但是招牌却倒挂着，关关着门，
傍边的墙上用红油漆写着"关门闭店"。
LONG
	);
set("exits", ([
                "east" : __DIR__"beidajie",       
	]));
       setup();
	replace_program(ROOM);
}	
