/*
 * File    : ������� (/d/job/killhaidao/lev2/ship_2_4.c)
 * Author  : [1;36m�����[2;37;0m(yanyan@����˫��  )
 * Date    : Mon Mar 17 21:17:06 2003
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "�������");
        set("long", @LONG
����߽������ڣ�һ�����µ�����ζ���˱Ƕ�������Ȼ���Ҵ��ս�
�ɲ��á���ͣ����ˮ�ִ����ﾭ���������ǵľ�ֹ���������в�������
���֡�
LONG
);
        set("exits",([
	"west" : __DIR__"ship_2_2",
	"north" : __DIR__"ship_0_4",
	"east" : __DIR__"ship_2_6",
	"up":"/d/job/killhaidao/lev1/ship_2_4",
	"down":"/d/job/killhaidao/lev3/ship_2_4",
        ]));
        setup();
//        replace_program(ROOM);
}
