/*
 * File    : ��ͤ (/u/yanyan/dmjob/dmjob_8_1.c)
 * Author  : [1;37m�����[2;37;0m(yanyan@����˫��  )
 * Date    : Thu Oct 18 11:38:33 2001
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "��ͤ");
        set("long", @LONG
����һ��Сľ��ͤ������İ���򵥣�ֻ�м���ľ���Ӻ�һ��ľ��
�ӡ������Ƕ�����Ϊ���ɿ󹤶�׼������Ϣ֮�ء����ϻ����ż�����ͷ��
LONG
);
        set("exits",([
	"northeast" : __DIR__"dmjob_6_3",
        ]));
set("outdoors","dmjob");
        setup();
//        replace_program(ROOM);
}
