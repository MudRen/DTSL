/*
 * File    : Ğ¡Ìü (/d/job/killhaidao/lev1/ship_4_8.c)
 * Author  : [1;36mÕæ±ùºÓ[2;37;0m(yanyan@´óÌÆË«Áú  )
 * Date    : Mon Mar 17 21:14:22 2003
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "Ğ¡Ìü");
        set("long", @LONG
Äã×ß½øÒ»¼äĞ¡Ìü£¬ÀïÃæ²¼ÖÃµÄºÜºÀ»ª£¬ÖĞ¼äÇ½ÉÏ¹Ò×ÅÒ»ÕÅÊé»­£¬²»
ÖªÊÇ³ö×ÔË­µÄÊÖ±Ê¡£Äã¿´ÁË°ëÌì£¬²¢²»¾õµÃÊé»­ÓĞ¸ßÃ÷µÄµØ·½¡£
LONG
);
        set("exits",([
	"north" : __DIR__"ship_2_8",
        ]));
        setup();
//        replace_program(ROOM);
}
