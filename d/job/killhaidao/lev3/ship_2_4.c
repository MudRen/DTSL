/*
 * File    : ������� (/d/job/killhaidao/lev3/ship_2_4.c)
 * Author  : [1;36m�����[2;37;0m(yanyan@����˫��  )
 * Date    : Mon Mar 17 21:18:20 2003
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
	"south" : __DIR__"ship_4_4",
	"west" : __DIR__"ship_2_2",
	"north" : __DIR__"ship_0_4",
	"east" : __DIR__"ship_2_6",
	"up":"/d/job/killhaidao/lev2/ship_2_4",
        ]));
        setup();
//        replace_program(ROOM);
}
