/*
 * File    : ¼àÀÎ (/d/job/killhaidao/lev3/ship_4_2.c)
 * Author  : [1;36mÕæ±ùºÓ[2;37;0m(yanyan@´óÌÆË«Áú  )
 * Date    : Mon Mar 17 21:18:20 2003
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "¼àÀÎ");
        set("long", @LONG
ÕâÀï¹ØÑº×Å¼¸¸öÈË£¬´ó¸ÅÊÇ´¬³¤°Ñ¶Ô±¾´¬²»ÀûµÄÈË¶¼¹ØÑºÔÚÕâÀï£¬
ËùÒÔ¼à¹ÜµÄÌØ±ğµÄÑÏ¸ñ¡£
LONG
);
        set("exits",([
	"north" : __DIR__"ship_2_2",
        ]));
        setup();
//        replace_program(ROOM);
}
