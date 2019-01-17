/*
 * File    : ÇğÁê (/u/yanyan/dmjob/dmjob_4_7.c)
 * Author  : [1;37mÕæ±ùºÓ[2;37;0m(yanyan@´óÌÆË«Áú  )
 * Date    : Thu Oct 18 11:38:33 2001
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "ÇğÁê");
        set("long", @LONG
ÄãÕı×ßÔÚÒ»ÌõÆéá«²»Æ½µÄÇğÁêÉÏ£¬Å¼¶ûÌıµ½Ò»ÕóÕóµÄÒ°ÊŞ½ĞÉù£¬Í·
¶¥ÓĞÒ»Ğ©²»ÖªÃûµÄĞ¡ÄñÔÚÌøÀ´ÌøÈ¥£¬ËÄÖÜ´ÔÁÖÃÜ²¼£¬ÏÊ»¨ÂÌ²İÈôÒşÈôÏÖ£¬
ËÄÖÜ²»Ê±´«À´»©»©µÄËÉÌÎÉùºÍÒ»Ğ©µ­µ­µÄ»¨Ïã¡£
LONG
);
        set("exits",([
	"northeast" : __DIR__"dmjob_2_9",
	"westdown" : __DIR__"dmjob_4_5",
	"southeast" : __DIR__"dmjob_6_9",
        ]));
set("outdoors","dmjob");
        setup();
//        replace_program(ROOM);
}
