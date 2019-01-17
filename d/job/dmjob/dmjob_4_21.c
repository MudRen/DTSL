/*
 * File    : ÃÜÁÖ (/u/yanyan/dmjob/dmjob_4_21.c)
 * Author  : [1;37mÕæ±ùºÓ[2;37;0m(yanyan@´óÌÆË«Áú  )
 * Date    : Thu Oct 18 11:38:33 2001
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "ÃÜÁÖ");
        set("long", @LONG
ÕâÀïÊÇÒ»Æ¬Ò»ÍûÎŞÛóÁÖº££¬Ã¿¿ÃÊ÷Ä¾¶¼ÓĞÊ®À´ÕÉ¸ß£¬ÖÜÎ§ÚäÄ°½»´í£¬
¼¸Ê®ÕÉ¸ßµÄ´óÊ÷´ØÔÚÒ»¿é£¬ÃÜÊµµÄÖ¦Ò¶ÏóÒ»ÅîÅî¾ŞÉ¡°ãÉìÏòÌì¿Õ£¬°ÑÑô¹â
ÕÚµÃË¿ºÁÒ²ÎŞ¡£
LONG
);
        set("exits",([
	"west" : __DIR__"dmjob_4_19",
        ]));
set("outdoors","dmjob");
        setup();
//        replace_program(ROOM);
}
