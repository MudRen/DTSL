/*
 * File    : ��ɽ· (/u/yanyan/dmjob/dmjob_2_11.c)
 * Author  : [1;37m�����[2;37;0m(yanyan@����˫��  )
 * Date    : Thu Oct 18 11:38:33 2001
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "��ɽ·");
        set("long", @LONG
����������ɽ��һ����ɽ·��������һƬ�ݵء�������Ƹ��ӣ���
·���ۣ����ܱ��߷�����Χ����˵����������������·���㲻��С����
����
LONG
);
        set("exits",([
	"southdown" : __DIR__"dmjob_4_11",
	"west" : __DIR__"dmjob_2_9",
	"eastdown" : __DIR__"dmjob_2_13",
        ]));
set("outdoors","dmjob");
        setup();
//        replace_program(ROOM);
}
