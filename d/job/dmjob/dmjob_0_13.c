/*
 * File    : ÆÁ·çÉ½¿Ú (/u/yanyan/dmjob/dmjob_0_13.c)
 * Author  : [1;37mÕæ±ùºÓ[2;37;0m(yanyan@´óÌÆË«Áú  )
 * Date    : Thu Oct 18 11:38:33 2001
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "ÆÁ·çÉ½¿Ú");
        set("long", @LONG
ÕâÀïÊÇÆÁ·çÉ½¿ÚµÄÈë¿Ú´¦ÁË¡£Ö»¼ûÁ½ÅÔÉ½ÁÖËÊÁ¢£¬ÉîÈëÔÆ¶Ë£¬µØÊÆ
·Ç³£ÏÕÒª¡£Ç°·½ÊÇÒ»ÌõËéÊ¯Â·£¬ËÄÖÜ²»Ê±´«À´ÄñÃù½ĞµÄÉùÒô¡£ÕâÀï¾°É«
ĞãÀö£¬¿ÕÆøÇåĞÂ¡£
LONG
);
        set("exits",([
        "northup":"/d/dongming/shanya2",
	"south" : __DIR__"dmjob_2_13",
        ]));
set("outdoors","dmjob");
        setup();
        replace_program(ROOM);
}
