/*
 * File    : »áÒéÊÒ (/d/job/killhaidao/lev2/ship_0_8.c)
 * Author  : [1;36mÕæ±ùºÓ[2;37;0m(yanyan@´óÌÆË«Áú  )
 * Date    : Mon Mar 17 21:17:06 2003
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "»áÒéÊÒ");
        set("long", @LONG
ÕâÊÇÒ»¼ä·Ç³£¿í³¨µÄ´¬²Õ£¬±»²¼ÖÃµÄÕûÕûÆëÆë£¬ÒÔ¹©¿ª»áµÄÊ±ºòÊ¹
ÓÃ¡£ÖĞ¼äÊÇÒ»ÕÅ´ó×À×Ó£¬¿ª»áµÄÊ±ºòÉí·İ½Ï¸ßµÄÈË¶¼×øÔÚ×À×ÓµÄÅÔ±ß¡£
ËÄÖÜ»¹ÓĞºÜ¶àÎªË®ÊÖ×¼±¸µÄĞ¡°åµÊ¡£
LONG
);
        set("exits",([
	"south" : __DIR__"ship_2_8",
        ]));
        setup();
//        replace_program(ROOM);
}
