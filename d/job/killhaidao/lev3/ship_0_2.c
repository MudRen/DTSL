/*
 * File    : ³ø·¿ (/d/job/killhaidao/lev3/ship_0_2.c)
 * Author  : [1;36mÕæ±ùºÓ[2;37;0m(yanyan@´óÌÆË«Áú  )
 * Date    : Mon Mar 17 21:18:20 2003
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
	"south" : __DIR__"ship_2_2",
        ]));
        setup();
//        replace_program(ROOM);
}
