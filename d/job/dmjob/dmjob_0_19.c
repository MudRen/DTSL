/*
 * File    : ���� (/u/yanyan/dmjob/dmjob_0_19.c)
 * Author  : [1;37m�����[2;37;0m(yanyan@����˫��  )
 * Date    : Thu Oct 18 11:38:33 2001
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "����");
        set("long", @LONG
������һ�����¡�����������ɽ�ķ������ˡ������±�����ף�
���������ƴ���Ľ��»���Ʈ�������±�����һ���������������Ĵ�
���²�ס�ػζ��š�
LONG
);
        set("exits",([
	"west" : __DIR__"dmjob_0_17",
        ]));
set("outdoors","dmjob");
        setup();
//        replace_program(ROOM);
}
