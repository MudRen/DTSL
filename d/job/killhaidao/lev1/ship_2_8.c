/*
 * File    : ָ���� (/d/job/killhaidao/lev1/ship_2_8.c)
 * Author  : [1;36m�����[2;37;0m(yanyan@����˫��  )
 * Date    : Mon Mar 17 21:14:22 2003
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "ָ����");
        set("long", @LONG
������ָ���ң����ϵ�������඼�Ǵ����ﴫ��ģ�Ȼ������ˮ��
��ִ�С�ָ�ӹ��������Աߵ�ˮ�ֵ������ˮ�ֲ�ס�ĵ�ͷ��ת���
ȥ�ˡ�
LONG
);
        set("exits",([
	"south" : __DIR__"ship_4_8",
	"west" : __DIR__"ship_2_6",
	"north" : __DIR__"ship_0_8",
        ]));
        setup();
//        replace_program(ROOM);
}
