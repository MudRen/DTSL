/*
 * File    : ����� (/u/yanyan/dmjob/dmjob_4_13.c)
 * Author  : [1;37m�����[2;37;0m(yanyan@����˫��  )
 * Date    : Thu Oct 18 11:38:33 2001
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "�����");
        set("long", @LONG
������һ�����£���Ϊ������Ҫ����˵û�����ܴ�������Ե���£�
��������Ϊ��������ֻ�������±�����ף���Լ������������Ұ
�޵Ľ�����
LONG
);
        set("exits",([
	"west" : __DIR__"dmjob_4_11",
        ]));
set("outdoors","dmjob");
        setup();
//        replace_program(ROOM);
}
