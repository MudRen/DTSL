/*
 * File    : ´¬²ÕÈë¿Ú (/d/job/killhaidao/lev3/ship_2_4.c)
 * Author  : [1;36mÕæ±ùºÓ[2;37;0m(yanyan@´óÌÆË«Áú  )
 * Date    : Mon Mar 17 21:18:20 2003
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "´¬²ÕÈë¿Ú");
        set("long", @LONG
Äã¸Õ×ß½ø´¬²ÕÄÚ£¬Ò»¹ÉÇåĞÂµÄÓÍÆáÎ¶µÀÆË±Ç¶øÀ´¡£ÏÔÈ»ÕâËÒ´¬¸Õ½¨
³É²»¾Ã¡£²»Í£µÄÓĞË®ÊÖ´ÓÕâÀï¾­¹ı£¬´ÓËûÃÇµÄ¾ÙÖ¹¿´À´£¬ÆäÖĞ²»·¦ÎäÁÖ
¸ßÊÖ¡£
LONG
);
        set("exits",([
	"south" : __DIR__"ship_4_4",
	"west" : __DIR__"ship_2_2",
	"north" : __DIR__"ship_0_4",
	"east" : __DIR__"ship_2_6",
	"up":"/d/job/killhaidao/lev2/ship_2_4",
        ]));
        setup();
//        replace_program(ROOM);
}
