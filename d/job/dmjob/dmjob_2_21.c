/*
 * File    : ´óÏ¿¹È (/u/yanyan/dmjob/dmjob_2_21.c)
 * Author  : [1;37mÕæ±ùºÓ[2;37;0m(yanyan@´óÌÆË«Áú  )
 * Date    : Thu Oct 18 11:38:33 2001
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "´óÏ¿¹È");
        set("long", @LONG
ÕâÀïÊÇÒ»¸ö´óÏ¿¹È¡£ËÄÖÜ¸ß·åËÊÁ¢£¬µ²×¡ÁËÍâÃæµÄÀäÆø£¬Ëù
ÒÔÕâÀïÒ»ÄêËÄ¼¾¶¼ÊÇÎÂÅ¯Èç´º¡£ÕâÀï·ç¾°ĞãÀö£¬¿ÕÆøÇåĞÂ¡£µØÉÏ
ÓĞºÜ¶àÆ¯ÁÁµÄÒ°»¨¡¢ÆÑ¹«Ó¢µÈÖ²Îï¡£²»Ê±ÓĞÒ°ÍÃ´ÓÄãµÄ½ÅÅÔÌø¹ı¡£
LONG
);
        set("exits",([
	"west" : __DIR__"dmjob_2_19",
        ]));
set("outdoors","dmjob");
        setup();
//        replace_program(ROOM);
}
