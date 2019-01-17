/*
 * File    : ÎÔÊÒ (/d/job/killhaidao/lev1/ship_0_6.c)
 * Author  : [1;36mÕæ±ùºÓ[2;37;0m(yanyan@´óÌÆË«Áú  )
 * Date    : Mon Mar 17 21:14:22 2003
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "Ë®ÊÖĞİÏ¢ÊÒ");
        set("long", @LONG
ÕâÀïÊÇ¹©´¬ÉÏË®ÊÖĞİÏ¢µÄ³¡Ëù£¬ÀïÃæ¸É¸É¾»¾»¡£µØÃæÉÏÒ»ÅÅÅÅµÄ°Ú
ÁËĞí¶àÆÌ¸Ç¡£ÎÔÊÒÀï¾²ÇÄÇÄµÄ£¬ÕıÓĞ¼¸¸öË®ÊÖÌÉÔÚÆÌ¸ÇÉÏÃÉÍ·´óË¯¡£
LONG
);
        set("exits",([
	"south" : __DIR__"ship_2_6",
        ]));
        setup();
//        replace_program(ROOM);
}
