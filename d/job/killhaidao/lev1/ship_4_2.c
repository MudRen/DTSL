/*
 * File    : ���� (/d/job/killhaidao/lev1/ship_4_2.c)
 * Author  : [1;36m�����[2;37;0m(yanyan@����˫��  )
 * Date    : Mon Mar 17 21:14:22 2003
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "����");
        set("long", @LONG
��һ�����������һ�ɷ���ζ������ı��С������������һ��
����ͻȻ��о������ӹ����Ľ���������
LONG
);
        set("exits",([
	"north" : __DIR__"ship_2_2",
        ]));
        setup();
//        replace_program(ROOM);
}
