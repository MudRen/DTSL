/*
 * File    : Ğ¡»ğÉ½ (/u/yanyan/dmjob/dmjob_6_17.c)
 * Author  : [1;37mÕæ±ùºÓ[2;37;0m(yanyan@´óÌÆË«Áú  )
 * Date    : Thu Oct 18 11:38:33 2001
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "Ğ¡»ğÉ½");
        set("long", @LONG
ÕâÀïÊÇµºÉÏÒ»×ùĞ¡»ğÉ½¡£ÕâÀïÓĞĞ©Ñ×ÈÈ£¬»ğÉ½¿ÚµÄËÄÖÜÊÇ´ç²İ²»Éú£¬
Ò²¿´²»µ½Ò°ÊŞµÄ×ã¼£¡£ÕâÀïµÄÑÒÊ¯ĞÎ×´¹ÖÒì£¬Õæ¿ÉÒÔËµÊÇ¹í¸«Éñ¹¤¡£
LONG
);
        set("exits",([
	"northdown" : __DIR__"dmjob_4_19",
	"eastdown" : __DIR__"dmjob_6_19",
        ]));
set("outdoors","dmjob");
        setup();
//        replace_program(ROOM);
}
