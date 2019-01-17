/*
 * File    : Çå·ç¹È (/u/yanyan/dmjob/dmjob_4_5.c)
 * Author  : [1;37mÕæ±ùºÓ[2;37;0m(yanyan@´óÌÆË«Áú  )
 * Date    : Thu Oct 18 11:38:33 2001
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "Çå·ç¹È");
        set("long", @LONG
ÕâÀïÊÇÆÁ·çÉ½µÄÇå·ç¹ÈÁË¡£¾İËµÓĞµÀÈËÔø¾­ÔÚÕâÀïĞŞµÀ£¬¶øÊ¹ÕâÀï
ÆøºòÎÂÅ¯£¬ËÄ¼¾Èç´º¡£Ò»ÕóÇå·ç´µÀ´£¬´øÀ´ÁËÕóÕóµÄ»¨²İÏãÆø¡£
LONG
);
        set("exits",([
	"westup" : __DIR__"dmjob_4_3",
	"southwest" : __DIR__"dmjob_6_3",
	"eastup" : __DIR__"dmjob_4_7",
        ]));
set("outdoors","dmjob");
        setup();
//        replace_program(ROOM);
}
