/*
 * File    : ¹ÛÈÕÌ¨ (/u/yanyan/dmjob/dmjob_2_3.c)
 * Author  : [1;37mÕæ±ùºÓ[2;37;0m(yanyan@´óÌÆË«Áú  )
 * Date    : Thu Oct 18 11:38:33 2001
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "¹ÛÈÕÌ¨");
        set("long", @LONG
ÕâÀïÊÇÆÁ·çÉ½µÄ¹ÛÈÕÌ¨ÁË¡£ÕâÀïµØÊÆ·Ç³£¸ß£¬ËùÒÔÊÇÔç³¿¹ÛÉÍµÄÈÕ
³öµÄ¼«¼ÑÖ®µØ¡£ÕâÀïºÍÆÁ·çÉ½·ÉÌìÁëÒ£Ò£ÏàÍû¡£°×ÔÆÁıÕÖ×ÅÕâÀï£¬ĞÎ³É
ÁËÒ»ÖÖÆæÒìµÄÆø·Õ¡£
LONG
);
        set("exits",([
	"southdown" : __DIR__"dmjob_4_3",
        ]));
set("outdoors","dmjob");
        setup();
//        replace_program(ROOM);
}
