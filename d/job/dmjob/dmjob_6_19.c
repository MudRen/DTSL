/*
 * File    : Ê¯ÁÖ (/u/yanyan/dmjob/dmjob_6_19.c)
 * Author  : [1;37mÕæ±ùºÓ[2;37;0m(yanyan@´óÌÆË«Áú  )
 * Date    : Thu Oct 18 11:38:33 2001
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "Ê¯ÁÖ");
        set("long", @LONG
ÕâÀïÊÇÒ»×ùÊ¯ÁÖ£¬¶«±ßÊÇÒ»×ùĞ¡»ğÉ½¡£ÕâÀïµÄÊ¯ÁÖ¾ùÊÇ»ğÉ½µÄÈÛÑÒ
Äı¹ÌĞÎ³É£¬ËùÒÔĞÎ×´¹ÖÒì£¬ÓĞÈç¹í¸«Éñ¹¤Ò»°ã¡£ÕâÀïÃÆÈÈÒì³££¬Äã²»¾õ
¿ªÊ¼ÓĞĞ©¿Ú¿ÊÁË¡£
LONG
);
        set("exits",([
	"westup" : __DIR__"dmjob_6_17",
        ]));
set("outdoors","dmjob");
        setup();
//        replace_program(ROOM);
}
