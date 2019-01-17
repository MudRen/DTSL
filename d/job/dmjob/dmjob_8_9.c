/*
 * File    : Á¹Í¤ (/u/yanyan/dmjob/dmjob_8_9.c)
 * Author  : [1;37mÕæ±ùºÓ[2;37;0m(yanyan@´óÌÆË«Áú  )
 * Date    : Thu Oct 18 11:38:33 2001
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "Á¹Í¤");
        set("long", @LONG
ÕâÀïÊÇÒ»¸öĞ¡Á¹Í¤¡£Á¹Í¤ÉÏĞü¹ÒµÄ¶ÔÁªÒÑ¾­ÆÆËğ£¬¿´²»Çå³şÉÏÃæµÄ
×Ö¼£ÁË¡£Á¹Í¤ÀïÃæ°ÚÁË¼¸¸öÊ¯µÊ×ÓºÍÒ»ÕÅÊ¯×À×Ó£¬¿´À´ÕâÀïÊÇ¸øÀ´ÍùĞĞ
ÈËĞİÏ¢Ê±ÓÃµÄ¡£
LONG
);
        set("exits",([
	"west" : __DIR__"dmjob_8_7",
	"north" : __DIR__"dmjob_6_9",
        ]));
set("outdoors","dmjob");
        setup();
//        replace_program(ROOM);
}
