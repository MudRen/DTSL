/*
 * File    : ���� (/u/yanyan/dmjob/dmjob_4_7.c)
 * Author  : [1;37m�����[2;37;0m(yanyan@����˫��  )
 * Date    : Thu Oct 18 11:38:33 2001
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "����");
        set("long", @LONG
��������һ����᫲�ƽ�������ϣ�ż������һ�����Ұ�޽�����ͷ
����һЩ��֪����С����������ȥ�����ܴ����ܲ����ʻ��̲��������֣�
���ܲ�ʱ������������������һЩ�����Ļ��㡣
LONG
);
        set("exits",([
	"northeast" : __DIR__"dmjob_2_9",
	"westdown" : __DIR__"dmjob_4_5",
	"southeast" : __DIR__"dmjob_6_9",
        ]));
set("outdoors","dmjob");
        setup();
//        replace_program(ROOM);
}
