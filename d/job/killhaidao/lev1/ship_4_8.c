/*
 * File    : С�� (/d/job/killhaidao/lev1/ship_4_8.c)
 * Author  : [1;36m�����[2;37;0m(yanyan@����˫��  )
 * Date    : Mon Mar 17 21:14:22 2003
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "С��");
        set("long", @LONG
���߽�һ��С�������沼�õĺܺ������м�ǽ�Ϲ���һ���黭����
֪�ǳ���˭���ֱʡ��㿴�˰��죬���������黭�и����ĵط���
LONG
);
        set("exits",([
	"north" : __DIR__"ship_2_8",
        ]));
        setup();
//        replace_program(ROOM);
}
