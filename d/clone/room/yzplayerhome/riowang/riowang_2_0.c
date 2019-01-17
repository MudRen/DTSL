/*
 * File    : ÎÔÊÒ (/d/clone/room/riowang/riowang_2_0.c)
 * Author  : [1;37mÕæ±ùºÓ[2;37;0m(yanyan@´óÌÆË«Áú  )
 * Date    : Thu Oct 18 15:55:09 2001
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "ÎÔÊÒ");
        set("long", @LONG
ÕâÊÇÒ»¼äÎÔÊÒ£¬¹âÏßÊ®·ÖÈáºÍ¡£ÎÔÊÒÖĞ¼äÓĞÒ»ÕÅ´ó´²£¬Á½±ß
¹ÅÉ«¹ÅÏãµÄ¼Ò¾ßºÍÊÎÆ·ÈÃÈËÓĞÒ»ÖÖ±§µ½¡°·ÉÔÆ×Ó¡±ÄÇÀïÂôµôµÄ³å
¶¯£¡
LONG
);
        set("exits",([
	"east" : __DIR__"riowang_2_2",
        ]));
        setup();
//        replace_program(ROOM);
}
