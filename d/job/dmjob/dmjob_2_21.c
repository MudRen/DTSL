/*
 * File    : ��Ͽ�� (/u/yanyan/dmjob/dmjob_2_21.c)
 * Author  : [1;37m�����[2;37;0m(yanyan@����˫��  )
 * Date    : Thu Oct 18 11:38:33 2001
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "��Ͽ��");
        set("long", @LONG
������һ����Ͽ�ȡ����ܸ߷���������ס���������������
������һ���ļ�������ů�紺������羰�������������¡�����
�кܶ�Ư����Ұ�����ѹ�Ӣ��ֲ���ʱ��Ұ�ô���Ľ���������
LONG
);
        set("exits",([
	"west" : __DIR__"dmjob_2_19",
        ]));
set("outdoors","dmjob");
        setup();
//        replace_program(ROOM);
}
