/*
 * File    : ÍûÔÂ·å (/u/yanyan/dmjob/dmjob_2_15.c)
 * Author  : [1;37mÕæ±ùºÓ[2;37;0m(yanyan@´óÌÆË«Áú  )
 * Date    : Thu Oct 18 11:38:33 2001
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "ÍûÔÂ·å");
        set("long", @LONG
ÕâÀïÊÇÆÁ·çÉ½µÄÍûÔÂ·åÁË¡£Î÷±ßÊÇÒ»ÌõËéÊ¯Ğ¡Â·¡£¾İËµÕâÀï¿´µ½µÄ
ÔÂÉ«¸ñÍâ·ÖÃ÷£¬Ã¿·êÔÂÔ²Ö®Ò¹¼¸ºõ¿ÉÒÔÉìÊÖÃşµ½ÌìÉÏµÄÔ²ÔÂ¡£
LONG
);
        set("exits",([
	"northeast" : __DIR__"dmjob_0_17",
	"westdown" : __DIR__"dmjob_2_13",
        ]));
set("outdoors","dmjob");
        setup();
//        replace_program(ROOM);
}
