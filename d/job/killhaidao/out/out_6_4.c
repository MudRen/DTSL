/*
 * File    : ´¬²ÕÈë¿Ú (/d/job/killhaidao/out/out_6_4.c)
 * Author  : [1;36mÕæ±ùºÓ[2;37;0m(yanyan@´óÌÆË«Áú  )
 * Date    : Mon Mar 17 21:21:40 2003
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
	"west" : __DIR__"out_6_2",
	"up" : __DIR__"out_4_4",
	"east" : __DIR__"out_6_6",
	"down":"/d/job/killhaidao/lev1/ship_2_4",
        ]));
set("outdoors","out");
        setup();
//        replace_program(ROOM);
}
