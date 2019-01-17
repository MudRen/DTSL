/*
 * File    : ÁÅÍûËş (/d/job/killhaidao/out/out_0_4.c)
 * Author  : [1;36mÕæ±ùºÓ[2;37;0m(yanyan@´óÌÆË«Áú  )
 * Date    : Mon Mar 17 21:21:40 2003
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "ÁÅÍûËş");
        set("long", @LONG
ÕâÀïÊÇÒ»¸öË®ÊÖÁÅÍûËş£¬ËşÉÏÕıÕ¾×ÅÒ»¸öË®ÊÖÄ¿²»×ª¾¦µÄ¿´×Åº£Ãæ
ÉÏµÄÇé¿öÈ»ºó¼´Ê¹µÄÏò´¬³¤»ã±¨¡£
LONG
);
        set("exits",([
	"down" : __DIR__"out_2_4",
        ]));
set("outdoors","out");
        setup();
//        replace_program(ROOM);
}
