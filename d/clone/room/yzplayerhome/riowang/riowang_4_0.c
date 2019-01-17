/*
 * File    : ³ø·¿ (/d/clone/room/riowang/riowang_4_0.c)
 * Author  : [1;37mÕæ±ùºÓ[2;37;0m(yanyan@´óÌÆË«Áú  )
 * Date    : Thu Oct 18 15:55:09 2001
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "³ø·¿");
        set("long", @LONG
ÕâÀïÊÇ³ø·¿£¬¹øÍëÆ°ÅèÑùÑùÆëÈ«£¬»¹Ê±Ê±ÓĞĞÂÏÊµÄ×÷ÁÏ¹©Ó¦£¬
ÌıËµ²ÔÔÂÕâ¼Ò»ï²»µ«Ë£µ¶×Ó²»Àµ£¬×ö²ËÒ²ÓĞÒ»ÊÖÅ¶£¬ËùÒÔÅóÓÑÃÇ
³£ËÍĞ©É½Õäº£Î¶À´£¬Ë³±ãÒ»±¥¿Ú¸££¡
LONG
);
        set("exits",([
	"northeast" : __DIR__"riowang_2_2",
        ]));
        setup();
//        replace_program(ROOM);
}
