/*
 * File    : ��ͤ (/u/yanyan/dmjob/dmjob_8_9.c)
 * Author  : [1;37m�����[2;37;0m(yanyan@����˫��  )
 * Date    : Thu Oct 18 11:38:33 2001
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "��ͤ");
        set("long", @LONG
������һ��С��ͤ����ͤ�����ҵĶ����Ѿ����𣬿�����������
�ּ��ˡ���ͤ������˼���ʯ���Ӻ�һ��ʯ���ӣ����������Ǹ�������
����Ϣʱ�õġ�
LONG
);
        set("exits",([
	"west" : __DIR__"dmjob_8_7",
	"north" : __DIR__"dmjob_6_9",
        ]));
set("outdoors","dmjob");
        setup();
//        replace_program(ROOM);
}
