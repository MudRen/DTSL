/*
 * File    : ���·� (/u/yanyan/dmjob/dmjob_2_15.c)
 * Author  : [1;37m�����[2;37;0m(yanyan@����˫��  )
 * Date    : Thu Oct 18 11:38:33 2001
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "���·�");
        set("long", @LONG
����������ɽ�����·��ˡ�������һ����ʯС·����˵���￴����
��ɫ���������ÿ����Բ֮ҹ�������������������ϵ�Բ�¡�
LONG
);
        set("exits",([
	"northeast" : __DIR__"dmjob_0_17",
	"westdown" : __DIR__"dmjob_2_13",
        ]));
set("outdoors","dmjob");
        setup();
//        replace_program(ROOM);
}
