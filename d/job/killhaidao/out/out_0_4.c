/*
 * File    : ������ (/d/job/killhaidao/out/out_0_4.c)
 * Author  : [1;36m�����[2;37;0m(yanyan@����˫��  )
 * Date    : Mon Mar 17 21:21:40 2003
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "������");
        set("long", @LONG
������һ��ˮ����������������վ��һ��ˮ��Ŀ��ת���Ŀ��ź���
�ϵ����Ȼ��ʹ���򴬳��㱨��
LONG
);
        set("exits",([
	"down" : __DIR__"out_2_4",
        ]));
set("outdoors","out");
        setup();
//        replace_program(ROOM);
}
