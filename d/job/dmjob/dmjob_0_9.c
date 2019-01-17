/*
 * File    : ÎÂÈª (/u/yanyan/dmjob/dmjob_0_9.c)
 * Author  : [1;37mÕæ±ùºÓ[2;37;0m(yanyan@´óÌÆË«Áú  )
 * Date    : Thu Oct 18 11:38:33 2001
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "ÎÂÈª");
        set("long", @LONG
ÕâÀïÊÇÒ»¸öÎÂÈª£¬ÕóÕóµÄ°×ÎíÁıÕÖ×ÅÕâÀï¡£ÕâÀïÆø·ÕÄş¾²£¬Ö»ÓĞ¼¸
ÉùÄñÃù½ĞµÄÉùÒô²»Ê±´«Èë¶úÖĞ¡£¾İËµÕâ¸öÎÂÈªÊÇ»ğÉ½Åç·¢ĞÎ³É£¬µ½ÎÂÈª
ÀïÏ´Ôè¿ÉÒÔÖÎÓúĞí¶à¼²²¡¡£
LONG
);
        set("exits",([
	"south" : __DIR__"dmjob_2_9",
        ]));
set("outdoors","dmjob");
        setup();
//        replace_program(ROOM);
}
