/*
 * File    : Φ�� (/d/job/killhaidao/out/out_4_4.c)
 * Author  : [1;36m�����[2;37;0m(yanyan@����˫��  )
 * Date    : Mon Mar 17 21:21:40 2003
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "Φ��");
        set("long", @LONG
�����Ǵ󴬵�Φ�ˣ�����ˮ�ָ��ݴ��ĺ����Լ�����ͣ�ĵ�����
��������ʹ���ܹ����������ķ���ȫ��ʻ��
LONG
);
        set("exits",([
	"down" : __DIR__"out_6_4",
	"up" : __DIR__"out_2_4",
        ]));
set("outdoors","out");
        setup();
//        replace_program(ROOM);
}
