/*
 * File    : ˮ����Ϣ�� (/d/job/killhaidao/lev3/ship_4_8.c)
 * Author  : [1;36m�����[2;37;0m(yanyan@����˫��  )
 * Date    : Mon Mar 17 21:18:20 2003
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
	"north" : __DIR__"ship_2_8",
        ]));
        setup();
//        replace_program(ROOM);
}
