/*
 * File    : »ğÉ½¿Ú (/u/yanyan/dmjob/dmjob_8_13.c)
 * Author  : [1;37mÕæ±ùºÓ[2;37;0m(yanyan@´óÌÆË«Áú  )
 * Date    : Thu Oct 18 11:38:33 2001
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "»ğÉ½¿Ú");
        set("long", @LONG
ÕâÀïÊÇÒ»¸ö»ğÉ½¿Ú¡£Ö»¼ûµØÉÏÃ°×ÅÕóÕó°×Æø£¬ĞÎ³ÉÕóÕó°×ÎíÆ®ÏòÁË
¿ÕÖĞ¡£ÓĞĞ©µØ·½²»Ê±Ó¿´¦ÕóÕóºìÉ«ÑÒ½¬£¬ÏòÉ½ÏÂÁ÷ÌÊ¶øÈ¥¡£ÕâÀï·Ç³£Ñ×
ÈÈ£¬Äã¾õµÃÓĞĞ©ÃÔºıÁË¡£
LONG
);
        set("exits",([
	"northwest" : __DIR__"dmjob_6_11",
        ]));
set("outdoors","dmjob");
        setup();
//        replace_program(ROOM);
}
