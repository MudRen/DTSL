/*
 * File    : ����̨ (/u/yanyan/dmjob/dmjob_4_3.c)
 * Author  : [1;37m�����[2;37;0m(yanyan@����˫��  )
 * Date    : Thu Oct 18 11:38:33 2001
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "����̨");
        set("long", @LONG
����������ɽ�İ���̨�ˡ�����������ɽ�����ȡ���˵��������
�������ｲ�����Ӷ�ʹ����ɽ����һ�����ѡ�����������������Զ����
���Կ�������ɽ�����ľ�ɫ��
LONG
);
        set("exits",([
	"northup" : __DIR__"dmjob_2_3",
	"eastdown" : __DIR__"dmjob_4_5",
        ]));
set("outdoors","dmjob");
        setup();
//        replace_program(ROOM);
}
