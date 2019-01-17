/*
 * File    : »ğÉ½¿ÚÍâ (/u/yanyan/dmjob/dmjob_6_11.c)
 * Author  : [1;37mÕæ±ùºÓ[2;37;0m(yanyan@´óÌÆË«Áú  )
 * Date    : Thu Oct 18 11:38:33 2001
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "»ğÉ½¿ÚÍâ");
        set("long", @LONG
ÕâÀïÊÇÆÁ·çÉ½µÄÒ»¸ö´ó»ğÉ½¿ÚµÄÍâ±ß¡£¾İËµÕâ×ù»ğÉ½¾­³£Åç·¢£¬Ëù
ÒÔÕâÀï·Ç³£Ñ×ÈÈ£¬ËÄÖÜµÄÊ÷Ä¾¶¼ÒÑ¾­¿İÎ®¡£ÕóÕóÈÈÀËÒÑ¾­ÈÃÄã¾õµÃÓĞĞ©
¿Ú¸ÉÉàÔïÁË¡£
LONG
);
        set("exits",([
	"southeast" : __DIR__"dmjob_8_13",
	"northdown" : __DIR__"dmjob_4_11",
        ]));
set("outdoors","dmjob");
        setup();
//        replace_program(ROOM);
}
