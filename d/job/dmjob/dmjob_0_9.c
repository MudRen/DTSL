/*
 * File    : ��Ȫ (/u/yanyan/dmjob/dmjob_0_9.c)
 * Author  : [1;37m�����[2;37;0m(yanyan@����˫��  )
 * Date    : Thu Oct 18 11:38:33 2001
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "��Ȫ");
        set("long", @LONG
������һ����Ȫ������İ��������������������������ֻ�м�
�������е�������ʱ������С���˵�����Ȫ�ǻ�ɽ�緢�γɣ�����Ȫ
��ϴ�����������༲����
LONG
);
        set("exits",([
	"south" : __DIR__"dmjob_2_9",
        ]));
set("outdoors","dmjob");
        setup();
//        replace_program(ROOM);
}
