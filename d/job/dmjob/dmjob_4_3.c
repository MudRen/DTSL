/*
 * File    : °İÏÉÌ¨ (/u/yanyan/dmjob/dmjob_4_3.c)
 * Author  : [1;37mÕæ±ùºÓ[2;37;0m(yanyan@´óÌÆË«Áú  )
 * Date    : Thu Oct 18 11:38:33 2001
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "°İÏÉÌ¨");
        set("long", @LONG
ÕâÀïÊÇÆÁ·çÉ½µÄ°İÏÉÌ¨ÁË¡£¶«±ßÊÇÆÁ·çÉ½µÄÇå·ç¹È¡£¾İËµÓĞÏÉÈËÔø
¾­ÔÚÕâÀï½²·¨£¬´Ó¶øÊ¹ÆÁ·çÉ½ÃâÔâÒ»³¡´óÄÑ¡£ÕâÀïÆø·ÕÄş¾²£¬ÏòÔ¶´¦Íû
¿ÉÒÔ¿´µ½ÆÁ·çÉ½ĞãÀöµÄ¾°É«¡£
LONG
);
        set("exits",([
	"northup" : __DIR__"dmjob_2_3",
	"eastdown" : __DIR__"dmjob_4_5",
        ]));
set("outdoors","dmjob");
        setup();
//        replace_program(ROOM);
}
