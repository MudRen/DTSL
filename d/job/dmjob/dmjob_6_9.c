/*
 * File    : СϪ (/u/yanyan/dmjob/dmjob_6_9.c)
 * Author  : [1;37m�����[2;37;0m(yanyan@����˫��  )
 * Date    : Thu Oct 18 11:38:33 2001
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "СϪ");
        set("long", @LONG
������һ��СϪ��������һ�����ꡣϪˮ�峺���ף���ʱ���Կ���
Ұ�á������С������Ϫ�ߺ�ˮ�����ܴ����ܲ����ʻ��̲��������֡�
LONG
);
        set("exits",([
	"northwest" : __DIR__"dmjob_4_7",
	"south" : __DIR__"dmjob_8_9",
        ]));
set("outdoors","dmjob");
        setup();
//        replace_program(ROOM);
}
