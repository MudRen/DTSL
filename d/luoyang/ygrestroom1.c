//Edit By Subzero
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{

        set("short", YEL "方厅" NOR);
        set("long", @LONG
这里就是阴癸弟子来到洛阳以后的秘密联络地点。屋子中央放着一
张茶几，和几把椅子，椅子上坐着一个看起来很年轻的女子。
LONG);

        set("valid_startroom", 1);
        set("exits", ([
        "east" : "/d/luoyang/nanjie4",
        "west" : "/d/luoyang/ygrestroom2",
        ]));
  		set("objects",([
     		"/d/clone/npc/chuzi":1,
    		 ]));
		set("resource/water",1);
        setup();
}
