/*
 * File    : ´¬²Õ (/d/job/killhaidao/lev3/ship_2_6.c)
 * Author  : [1;36mÕæ±ùºÓ[2;37;0m(yanyan@´óÌÆË«Áú  )
 * Date    : Mon Mar 17 21:18:20 2003
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "´¬²Õ");
        set("long", @LONG
Äã¸Õ×ß½ø´¬²ÕÄÚ£¬Ò»¹ÉÇåĞÂµÄÓÍÆáÎ¶µÀÆË±Ç¶øÀ´¡£ÏÔÈ»ÕâËÒ´¬¸Õ½¨
³É²»¾Ã¡£²»Í£µÄÓĞË®ÊÖ´ÓÕâÀï¾­¹ı£¬´ÓËûÃÇµÄ¾ÙÖ¹¿´À´£¬ÆäÖĞ²»·¦ÎäÁÖ
¸ßÊÖ¡£
LONG
);
        set("exits",([
	"west" : __DIR__"ship_2_4",
	"north" : __DIR__"ship_0_6",
	"east" : __DIR__"ship_2_8",
        ]));
        setup();
//        replace_program(ROOM);
}
