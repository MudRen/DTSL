/*
 * File    : �ݵ� (/u/yanyan/dmjob/dmjob_2_9.c)
 * Author  : [1;37m�����[2;37;0m(yanyan@����˫��  )
 * Date    : Thu Oct 18 11:38:33 2001
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "�ݵ�");
        set("long", @LONG
������һƬ�ݵء�������һ����Ȫ��������һ����ɽ·���ϱ���һ
�����ꡣ����羰������ɽˮ�续���������¡������кܶ�Ư����Ұ����
�ѹ�Ӣ��ֲ���ʱ��Ұ�ô���Ľ���������
LONG
);
        set("exits",([
	"southwest" : __DIR__"dmjob_4_7",
	"north" : __DIR__"dmjob_0_9",
	"east" : __DIR__"dmjob_2_11",
        ]));
set("outdoors","dmjob");
        setup();
//        replace_program(ROOM);
}
