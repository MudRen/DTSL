/*
 * File    : ÎäÆ÷¿â (/d/job/killhaidao/lev3/ship_0_6.c)
 * Author  : [1;36mÕæ±ùºÓ[2;37;0m(yanyan@´óÌÆË«Áú  )
 * Date    : Mon Mar 17 21:18:20 2003
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "ÎäÆ÷¿â");
        set("long", @LONG
ÕâÀïÊÇÎäÆ÷¿â£¬´¬ÉÏµÄ±¸ÓÃÎäÆ÷´ó¶à¶¼´æ·ÅÔÚÕâÀï¡£¿¿Ç½µÄËÄÖÜ°Ú
ÂúÁË±øÆ÷¼Ü¡£Ò»¼ş¼şÎäÆ÷ÕûÆëµÄ°Ú·ÅÔÚÉÏÃæ¡£
LONG
);
        set("exits",([
	"south" : __DIR__"ship_2_6",
        ]));
        setup();
//        replace_program(ROOM);
}
