/*
 * File    : ¸óÂ¥ (/d/clone/room/riowang/riowang_0_2.c)
 * Author  : [1;37mÕæ±ùºÓ[2;37;0m(yanyan@´óÌÆË«Áú  )
 * Date    : Thu Oct 18 15:55:09 2001
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "¸óÂ¥");
        set("long", @LONG
Ò»½øÃÅ£¬Ò»ÕóÇå·çÏ®À´£¡Å¶£¬ÕâÀïÊÇÒ»¼äĞ¡¸óÂ¥£¬ÁÚ×ÅÍæ¼Ò
´åµÄĞ¡½Ö£¬ÏÔµÃÊ®·ÖÓĞÇéÈ¤¡£ÌıËµÄĞÅ®Ö÷ÈË³£³£ÔÚÕâÀï¹²ÉÍÈÕÂä¡£
LONG
);
        set("exits",([
	"south" : __DIR__"riowang_2_2",
	"east":"/d/clone/room/yzplayerhome/nandajie5",
        ]));
        setup();
//        replace_program(ROOM);
}
