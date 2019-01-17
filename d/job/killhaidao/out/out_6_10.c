/*
 * File    : ´¬Í· (/d/job/killhaidao/out/out_6_10.c)
 * Author  : [1;36mÕæ±ùºÓ[2;37;0m(yanyan@´óÌÆË«Áú  )
 * Date    : Mon Mar 17 21:21:40 2003
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "´¬Í·");
        set("long", @LONG
Äã×ßµ½ÁË´¬Í·£¬ÃæÇ°ÊÇÒ»ÍûÎŞ¼ÊµÄ´óº££¬ĞìĞìµÄº£·çÓ­Ãæ´µÀ´¡£¼¸
Ö»º£Å¸ÔÚº£ÃæÉÏµÍµÍµÄ·É¹ı£¬·¢³öÒ»ÕóÇå´àµÄ½ĞÉù¡£
LONG
);
        set("exits",([
	"west" : __DIR__"out_6_8",
        ]));
set("outdoors","out");
        setup();
//        replace_program(ROOM);
}
