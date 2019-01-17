/*
 * File    : Á¹Í¤ (/u/yanyan/dmjob/dmjob_8_1.c)
 * Author  : [1;37mÕæ±ùºÓ[2;37;0m(yanyan@´óÌÆË«Áú  )
 * Date    : Thu Oct 18 11:38:33 2001
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "Á¹Í¤");
        set("long", @LONG
ÕâÀïÒ»¸öĞ¡Ä¾Á¹Í¤¡£ÕâÀïµÄ°ÚÉè¼òµ¥£¬Ö»ÓĞ¼¸¸öÄ¾µÊ×ÓºÍÒ»¸öÄ¾×À
×Ó¡£¿´À´ÊÇ¶«äéÅÉÎª¿ª²É¿ó¹¤¶ø×¼±¸µÄĞİÏ¢Ö®µØ¡£µØÉÏ»¹·Å×Å¼¸¸ö¸äÍ·¡£
LONG
);
        set("exits",([
	"northeast" : __DIR__"dmjob_6_3",
        ]));
set("outdoors","dmjob");
        setup();
//        replace_program(ROOM);
}
