/*
 * File    : ĞüÑÂ (/u/yanyan/dmjob/dmjob_0_19.c)
 * Author  : [1;37mÕæ±ùºÓ[2;37;0m(yanyan@´óÌÆË«Áú  )
 * Date    : Thu Oct 18 11:38:33 2001
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "ĞüÑÂ");
        set("long", @LONG
ÕâÀïÊÇÒ»¸öĞüÑÂ¡£Î÷±ßÊÇÆÁ·çÉ½µÄ·ÉÌìÁëÁË¡£ĞüÑÂÏÂ±ßÉî²»¼ûµ×£¬
ÉõÖÁÓĞÇåÔÆ´ÓÄãµÄ½ÅÏÂ»º»ºÆ®¹ı¡£ĞüÑÂ±ßÁ¢×ÅÒ»¿ÃÀÏËÉÊ÷£¬ÔÚÇå·çµÄ´µ
·÷ÏÂ²»×¡µØ»Î¶¯×Å¡£
LONG
);
        set("exits",([
	"west" : __DIR__"dmjob_0_17",
        ]));
set("outdoors","dmjob");
        setup();
//        replace_program(ROOM);
}
