/*
 * File    : ´¬²Õ (/d/job/killhaidao/lev2/ship_2_0.c)
 * Author  : [1;36mÕæ±ùºÓ[2;37;0m(yanyan@´óÌÆË«Áú  )
 * Date    : Mon Mar 17 21:17:06 2003
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "´¬²Õ");
        set("long", @LONG
ÓÉÓÚÕâÊÇÒ»ËÒ¸Õ½¨³É²»¾ÃµÄ´ó´¬£¬ËùÒÔ´¬²ÕÀïÃæ»¹Æ®É¢×ÅÒ»¹ÉÇåĞÂ
µÄÓÍÆáÎ¶µÀ¡£²»Í£µÄÓĞË®ÊÖÔÚ´ÓÕâÀï´Ò´Ò¾­¹ı¡£
LONG
);
        set("exits",([
	"south" : __DIR__"ship_4_0",
	"north" : __DIR__"ship_0_0",
	"east" : __DIR__"ship_2_2",
        ]));
        setup();
//        replace_program(ROOM);
}
