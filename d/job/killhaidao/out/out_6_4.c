/*
 * File    : ������� (/d/job/killhaidao/out/out_6_4.c)
 * Author  : [1;36m�����[2;37;0m(yanyan@����˫��  )
 * Date    : Mon Mar 17 21:21:40 2003
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
	"west" : __DIR__"out_6_2",
	"up" : __DIR__"out_4_4",
	"east" : __DIR__"out_6_6",
	"down":"/d/job/killhaidao/lev1/ship_2_4",
        ]));
set("outdoors","out");
        setup();
//        replace_program(ROOM);
}
