
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "大船");
	set("long", @LONG
这里是一艘大船。船的桅杆上飘扬着一面大旗，上面画着东溟派的
标志，船身巨大，看起来足可以容纳一、二百人。这是东溟派的船，每
年东溟派都到中原来卖兵器。只见几名武林人士正在朝船上走去。
LONG);
	set("exits", ([
		"east":__DIR__"gangkou2",
		"enter":__DIR__"chuancang",
		]));
      set("valid_startroom", 1);   
       set("outdoors", "青石路");  
	setup();
       
       
}

