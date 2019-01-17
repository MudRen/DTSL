/*
 * File    : ÎÔÊÒ (/d/job/killhaidao/lev1/ship_0_2.c)
 * Author  : [1;36mÕæ±ùºÓ[2;37;0m(yanyan@´óÌÆË«Áú  )
 * Date    : Mon Mar 17 21:14:21 2003
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "ÎÔÊÒ");
        set("long", @LONG
ÕâÊÇ¹©´¬³¤µÄÆğ¾ÓÊÒ£¬µØÉÏ°ÚÉèµÄ£¬Ç½ÉÏ¹ÒµÄ¶¼ÊÇ´¬³¤ÓÎÀú¸÷µØµÄ
Ê±ºòËùÊÕ²ØµÄÎïÆ·¡£ËäËµ²»ÉÏ¼ÛÖµÁ¬³Ç£¬µ«À´ÀúÒ²¶¼²»Ğ¡¡£
LONG
);
        set("exits",([
	"south" : __DIR__"ship_2_2",
        ]));
        setup();
//        replace_program(ROOM);
}
