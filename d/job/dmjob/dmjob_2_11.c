/*
 * File    : ÅÌÉ½Â· (/u/yanyan/dmjob/dmjob_2_11.c)
 * Author  : [1;37mÕæ±ùºÓ[2;37;0m(yanyan@´óÌÆË«Áú  )
 * Date    : Thu Oct 18 11:38:33 2001
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "ÅÌÉ½Â·");
        set("long", @LONG
ÕâÀïÊÇÆÁ·çÉ½µÄÒ»ÌõÅÌÉ½Â·¡£Î÷±ßÊÇÒ»Æ¬²İµØ¡£ÕâÀïµØÊÆ¸´ÔÓ£¬µÀ
Â·ÇúÕÛ£¬ËÄÖÜ±»¸ß·åËù°üÎ§¡£¾İËµ¾­³£ÓĞÈËÔÚÕâÀïÃÔÂ·£¬Äã²»¾õĞ¡ĞÄÆğ
À´¡£
LONG
);
        set("exits",([
	"southdown" : __DIR__"dmjob_4_11",
	"west" : __DIR__"dmjob_2_9",
	"eastdown" : __DIR__"dmjob_2_13",
        ]));
set("outdoors","dmjob");
        setup();
//        replace_program(ROOM);
}
