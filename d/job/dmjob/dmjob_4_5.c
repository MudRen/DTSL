/*
 * File    : ���� (/u/yanyan/dmjob/dmjob_4_5.c)
 * Author  : [1;37m�����[2;37;0m(yanyan@����˫��  )
 * Date    : Thu Oct 18 11:38:33 2001
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "����");
        set("long", @LONG
����������ɽ�������ˡ���˵�е��������������޵�����ʹ����
������ů���ļ��紺��һ����紵��������������Ļ���������
LONG
);
        set("exits",([
	"westup" : __DIR__"dmjob_4_3",
	"southwest" : __DIR__"dmjob_6_3",
	"eastup" : __DIR__"dmjob_4_7",
        ]));
set("outdoors","dmjob");
        setup();
//        replace_program(ROOM);
}
