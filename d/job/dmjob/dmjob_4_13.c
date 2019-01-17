/*
 * File    : ¹í¼û³î (/u/yanyan/dmjob/dmjob_4_13.c)
 * Author  : [1;37mÕæ±ùºÓ[2;37;0m(yanyan@´óÌÆË«Áú  )
 * Date    : Thu Oct 18 11:38:33 2001
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "¹í¼û³î");
        set("long", @LONG
ÕâÀïÊÇÒ»¸öĞüÑÂ£¬ÒòÎªµØÊÆÏÕÒª£¬¾İËµÃ»ÓĞÈËÄÜ´ÓÕâÀïÅÊÔµ¶øÏÂ£¬
ËùÒÔÃüÃûÎª¡°¹í¼û³î¡±¡£Ö»¼ûĞüÑÂÏÂ±ßÉî²»¼ûµ×£¬ÒşÔ¼¿ÉÒÔÌıµ½¼¸ÉùÒ°
ÊŞµÄ½ĞÉù¡£
LONG
);
        set("exits",([
	"west" : __DIR__"dmjob_4_11",
        ]));
set("outdoors","dmjob");
        setup();
//        replace_program(ROOM);
}
