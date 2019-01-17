/*
 * File    : ´óÌü (/d/clone/room/riowang/riowang_2_2.c)
 * Author  : [1;37mÕæ±ùºÓ[2;37;0m(yanyan@´óÌÆË«Áú  )
 * Date    : Thu Oct 18 15:55:09 2001
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "´óÌü");
        set("long", @LONG
ÕâÊÇÒ»¼ä¿í³¨µÄ´óÎİ×Ó£¬ÌÃÉÏ¸ß¹Ò×ÅÒ»¸ö¡°Îä¡±×Ö£¬ÏÔµÃÊ®
·ÖÓĞÆøÅÉ¡£ÕâÀïµÄÄĞÅ®Ö÷ÈËÊÇ²ÔÔÂÒûËª£¨Riowang£©ºÍÇÇÇÇ£¨Kuk
u£©¡£ËäÈ»ÔÚ½­ºşÉÏ¶¼Ëã²»ÉÏ¶¥¼â¸ßÊÖ £¬µ«ÓÉÓÚÎªÈËÕıÖ±¹Â¸ß¾ø
ÊÀ¶øÉÙÓĞ³ğ¼Ò¡£ÌıËµËûÃÇ¹²½áÁ¬Àïºó±ãÒş¾ÓÓÚ´Ë£¬µ«ÖªÇéµÄÈËÈÔ
È»ÖªµÀËûÃÇ»¹ÔÚÎªÎäÁÖµÄ¸»ìí¶ø±¼²¨¡£   
LONG
);
        set("exits",([
	"west" : __DIR__"riowang_2_0",
    "east":"/d/clone/room/yzplayerhome/nandajie5",
	"southwest" : __DIR__"riowang_4_0",
	"north" : __DIR__"riowang_0_2",
        ]));
        setup();
//        replace_program(ROOM);
}
