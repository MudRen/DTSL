/*
 * File    : Î¦¸Ë (/d/job/killhaidao/out/out_4_4.c)
 * Author  : [1;36mÕæ±ùºÓ[2;37;0m(yanyan@´óÌÆË«Áú  )
 * Date    : Mon Mar 17 21:21:40 2003
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "Î¦¸Ë");
        set("long", @LONG
ÕâÀïÊÇ´ó´¬µÄÎ¦¸Ë£¬¼¸¸öË®ÊÖ¸ù¾İ´¬µÄº½ÏòÒÔ¼°·çÏò²»Í£µÄµ÷Õû×Å
´¬·«£¬ÒÔÊ¹´¬ÄÜ¹»°´ÕÕÕı³£µÄ·½Ïò°²È«ĞĞÊ»¡£
LONG
);
        set("exits",([
	"down" : __DIR__"out_6_4",
	"up" : __DIR__"out_2_4",
        ]));
set("outdoors","out");
        setup();
//        replace_program(ROOM);
}
