/*
 * File    : ²İµØ (/u/yanyan/dmjob/dmjob_2_9.c)
 * Author  : [1;37mÕæ±ùºÓ[2;37;0m(yanyan@´óÌÆË«Áú  )
 * Date    : Thu Oct 18 11:38:33 2001
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "²İµØ");
        set("long", @LONG
ÕâÀïÊÇÒ»Æ¬²İµØ¡£±±±ßÓĞÒ»¸öÎÂÈª£¬¶«±ßÊÇÒ»ÌõÅÌÉ½Â·¡£ÄÏ±ßÊÇÒ»
ÌõÇğÁê¡£ÕâÀï·ç¾°ĞãÀö£¬É½Ë®Èç»­£¬¿ÕÆøÇåĞÂ¡£µØÉÏÓĞºÜ¶àÆ¯ÁÁµÄÒ°»¨¡¢
ÆÑ¹«Ó¢µÈÖ²Îï¡£²»Ê±ÓĞÒ°ÍÃ´ÓÄãµÄ½ÅÅÔÌø¹ı¡£
LONG
);
        set("exits",([
	"southwest" : __DIR__"dmjob_4_7",
	"north" : __DIR__"dmjob_0_9",
	"east" : __DIR__"dmjob_2_11",
        ]));
set("outdoors","dmjob");
        setup();
//        replace_program(ROOM);
}
