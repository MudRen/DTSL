/*
 * File    : »õ²Õ (/d/job/killhaidao/lev1/ship_0_4.c)
 * Author  : [1;36mÕæ±ùºÓ[2;37;0m(yanyan@´óÌÆË«Áú  )
 * Date    : Mon Mar 17 21:14:22 2003
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "»õ²Õ");
        set("long", @LONG
Äã×ß½øÁËÒ»¼ä´æÂú»õÎïµÄ²Ö¿â£¬ÏóÕâÑùµÄ²Ö¿â´¬ÉÏ»¹ÓĞĞí¶à£¬´ó¶¼
±»¸÷ÖÖ¸÷ÑùµÄ»õÎï¶ÑÂú¡£ÕıÔÚÓĞ¼¸¸öÈËÄÃ×ÅÕÊ±¾ÔÚÕâÀïºË¶Ô»õÎï¡£
LONG
);
        set("exits",([
	"south" : __DIR__"ship_2_4",
        ]));
        setup();
//        replace_program(ROOM);
}
