/*
 * File    : ����̨ (/u/yanyan/dmjob/dmjob_2_3.c)
 * Author  : [1;37m�����[2;37;0m(yanyan@����˫��  )
 * Date    : Thu Oct 18 11:38:33 2001
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "����̨");
        set("long", @LONG
����������ɽ�Ĺ���̨�ˡ�������Ʒǳ��ߣ��������糿���͵���
���ļ���֮�ء����������ɽ������ңң��������������������γ�
��һ����������ա�
LONG
);
        set("exits",([
	"southdown" : __DIR__"dmjob_4_3",
        ]));
set("outdoors","dmjob");
        setup();
//        replace_program(ROOM);
}
