/*
 * File    : ���� (/d/job/killhaidao/lev1/ship_0_4.c)
 * Author  : [1;36m�����[2;37;0m(yanyan@����˫��  )
 * Date    : Mon Mar 17 21:14:22 2003
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "����");
        set("long", @LONG
���߽���һ���������Ĳֿ⣬�������Ĳֿ⴬�ϻ�����࣬��
�����ָ����Ļ�������������м����������ʱ�������˶Ի��
LONG
);
        set("exits",([
	"south" : __DIR__"ship_2_4",
        ]));
        setup();
//        replace_program(ROOM);
}
