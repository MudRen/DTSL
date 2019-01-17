/*
 * File    : ËéÊ¯Â· (/u/yanyan/dmjob/dmjob_2_13.c)
 * Author  : [1;37mÕæ±ùºÓ[2;37;0m(yanyan@´óÌÆË«Áú  )
 * Date    : Thu Oct 18 11:38:33 2001
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "ËéÊ¯Â·");
        set("long", @LONG
ÕâÀïÊÇÒ»ÌõËéÊ¯Â·¡£±±±ßÊÇÆÁ·çÉ½µÄÉ½¿Ú¡£ÕâÀï·ç¾°ĞãÀö£¬É½Ë®Èç
»­£¬¿ÕÆøÇåĞÂ¡£µØÉÏÓĞºÜ¶àÆ¯ÁÁµÄÒ°»¨¡¢ÆÑ¹«Ó¢µÈÖ²Îï¡£¶«±ßÒşÔ¼¿ÉÒÔ
¿´µ½Ò»×ùÉ½·å¡£
LONG
);
        set("exits",([
	"westup" : __DIR__"dmjob_2_11",
	"north" : __DIR__"dmjob_0_13",
	"eastup" : __DIR__"dmjob_2_15",
        ]));
set("outdoors","dmjob");
        setup();
//        replace_program(ROOM);
}
