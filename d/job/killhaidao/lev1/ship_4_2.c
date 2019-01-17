/*
 * File    : ³ø·¿ (/d/job/killhaidao/lev1/ship_4_2.c)
 * Author  : [1;36mÕæ±ùºÓ[2;37;0m(yanyan@´óÌÆË«Áú  )
 * Date    : Mon Mar 17 21:14:22 2003
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "³ø·¿");
        set("long", @LONG
ÄãÒ»µ½ÕâÀï£¬Á¢¼´ÓĞÒ»¹É·¹ÏãÎ¶´«µ½ÄãµÄ±ÇÖĞ¡£ÄãÉîÉîµÄÎüÁËÒ»¿Ú
Æø£¬Í»È»¼ä¸Ğ¾õµ½¶Ç×Ó¹¾¹¾µÄ½ĞÁËÆğÀ´¡£
LONG
);
        set("exits",([
	"north" : __DIR__"ship_2_2",
        ]));
        setup();
//        replace_program(ROOM);
}
