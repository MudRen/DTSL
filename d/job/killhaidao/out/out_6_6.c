/*
 * File    : ¼×°å (/d/job/killhaidao/out/out_6_6.c)
 * Author  : [1;36mÕæ±ùºÓ[2;37;0m(yanyan@´óÌÆË«Áú  )
 * Date    : Mon Mar 17 21:21:40 2003
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "¼×°å");
        set("long", @LONG
ÕâÀïÊÇ´ó´¬µÄ¼×°å£¬Ğí¶àµÄË®ÊÖÔÚÕâÀïÃ¦À´Ã¦È¥£¬²»Í£µÄÓĞÈË´Ó´¬
²ÕÖĞ±¼³öÏòË®ÊÖÃÇ´«´ï×îĞÂµÄÃüÁî¡£
LONG
);
        set("exits",([
	"west" : __DIR__"out_6_4",
	"east" : __DIR__"out_6_8",
        ]));
set("outdoors","out");
        setup();
//        replace_program(ROOM);
}
