/*
 * File    : ÂäÑãºş (/u/yanyan/dmjob/dmjob_8_7.c)
 * Author  : [1;37mÕæ±ùºÓ[2;37;0m(yanyan@´óÌÆË«Áú  )
 * Date    : Thu Oct 18 11:38:33 2001
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "ÂäÑãºş");
        set("long", @LONG
ÕâÀïÊÇÆÁ·çÉ½µÄÂäÑãºşÁË¡£ÕâÀïÂ«Î­´ÔÉú£¬Æø·ÕÄş¾²¡£¾İËµÃ¿Äê¶¼
ÓĞĞí¶à´óÑãÔÚÕâÀïÆÜÏ¢£¬ËùÒÔÃüÖ®ÎªÂäÑãºş¡£Ò»ÕóÎ¢·ç´µÀ´£¬Â«Î­ÔÚºş
ÃæÉÏÇáÇáµØ°Ú¶¯×Å¡£
LONG
);
        set("exits",([
	"east" : __DIR__"dmjob_8_9",
        ]));
set("outdoors","dmjob");
        setup();
//        replace_program(ROOM);
}
