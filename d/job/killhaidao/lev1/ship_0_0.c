/*
 * File    : ������ (/d/job/killhaidao/lev1/ship_0_0.c)
 * Author  : [1;36m�����[2;37;0m(yanyan@����˫��  )
 * Date    : Mon Mar 17 21:14:21 2003
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "������");
        set("long", @LONG
�����������⣬���ϵı���������඼����������ǽ�����ܰ�
���˱����ܡ�һ������������İڷ������档
LONG
);
        set("exits",([
	"south" : __DIR__"ship_2_0",
        ]));
        
        
        setup();
//        replace_program(ROOM);
}

