/*
 * File    : ��ʯ· (/u/yanyan/dmjob/dmjob_2_13.c)
 * Author  : [1;37m�����[2;37;0m(yanyan@����˫��  )
 * Date    : Thu Oct 18 11:38:33 2001
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "��ʯ·");
        set("long", @LONG
������һ����ʯ·������������ɽ��ɽ�ڡ�����羰������ɽˮ��
�����������¡������кܶ�Ư����Ұ�����ѹ�Ӣ��ֲ�������Լ����
����һ��ɽ�塣
LONG
);
        set("exits",([
	"westup" : __DIR__"dmjob_2_11",
	"north" : __DIR__"dmjob_0_13",
	"eastup" : __DIR__"dmjob_2_15",
        ]));
set("outdoors","dmjob");
        setup();
//        replace_program(ROOM);
}
