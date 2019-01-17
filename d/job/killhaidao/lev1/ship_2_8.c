/*
 * File    : Ö¸»ÓÊÒ (/d/job/killhaidao/lev1/ship_2_8.c)
 * Author  : [1;36mÕæ±ùºÓ[2;37;0m(yanyan@´óÌÆË«Áú  )
 * Date    : Mon Mar 17 21:14:22 2003
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "Ö¸»ÓÊÒ");
        set("long", @LONG
ÕâÀïÊÇÖ¸»ÓÊÒ£¬´¬ÉÏµÄÃüÁîĞí¶à¶¼ÊÇ´ÓÕâÀï´«´ïµÄ£¬È»ºóÔÙÓÉË®ÊÖ
ÃÇÖ´ĞĞ¡£Ö¸»Ó¹ÙÕıÔÚÏòÅÔ±ßµÄË®ÊÖµÍÉù¶úÓï£¬Ë®ÊÖ²»×¡µÄµãÍ·£¬×ªÉí³ö
È¥ÁË¡£
LONG
);
        set("exits",([
	"south" : __DIR__"ship_4_8",
	"west" : __DIR__"ship_2_6",
	"north" : __DIR__"ship_0_8",
        ]));
        setup();
//        replace_program(ROOM);
}
