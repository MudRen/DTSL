/*
 * File    : ���� (/d/job/killhaidao/lev1/ship_0_6.c)
 * Author  : [1;36m�����[2;37;0m(yanyan@����˫��  )
 * Date    : Mon Mar 17 21:14:22 2003
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "ˮ����Ϣ��");
        set("long", @LONG
�����ǹ�����ˮ����Ϣ�ĳ���������ɸɾ�����������һ���ŵİ�
������̸ǡ������ﾲ���ĵģ����м���ˮ�������̸�����ͷ��˯��
LONG
);
        set("exits",([
	"south" : __DIR__"ship_2_6",
        ]));
        setup();
//        replace_program(ROOM);
}
