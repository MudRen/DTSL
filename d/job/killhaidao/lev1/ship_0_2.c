/*
 * File    : ���� (/d/job/killhaidao/lev1/ship_0_2.c)
 * Author  : [1;36m�����[2;37;0m(yanyan@����˫��  )
 * Date    : Mon Mar 17 21:14:21 2003
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "����");
        set("long", @LONG
���ǹ�����������ң����ϰ���ģ�ǽ�ϹҵĶ��Ǵ����������ص�
ʱ�����ղص���Ʒ����˵���ϼ�ֵ���ǣ�������Ҳ����С��
LONG
);
        set("exits",([
	"south" : __DIR__"ship_2_2",
        ]));
        setup();
//        replace_program(ROOM);
}
