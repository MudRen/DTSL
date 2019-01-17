/*
 * File    : Ğ¡Ïª (/u/yanyan/dmjob/dmjob_6_9.c)
 * Author  : [1;37mÕæ±ùºÓ[2;37;0m(yanyan@´óÌÆË«Áú  )
 * Date    : Thu Oct 18 11:38:33 2001
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "Ğ¡Ïª");
        set("long", @LONG
ÕâÀïÊÇÒ»ÌõĞ¡Ïª¡£±±±ßÊÇÒ»ÌõÇğÁê¡£ÏªË®Çå³º¼ûµ×£¬²»Ê±¿ÉÒÔ¿´µ½
Ò°ÍÃ¡¢ËÉÊóµÈĞ¡¶¯ÎïÔÚÏª±ßºÈË®¡£ËÄÖÜ´ÔÁÖÃÜ²¼£¬ÏÊ»¨ÂÌ²İÈôÒşÈôÏÖ¡£
LONG
);
        set("exits",([
	"northwest" : __DIR__"dmjob_4_7",
	"south" : __DIR__"dmjob_8_9",
        ]));
set("outdoors","dmjob");
        setup();
//        replace_program(ROOM);
}
