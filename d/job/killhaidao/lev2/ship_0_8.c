/*
 * File    : ������ (/d/job/killhaidao/lev2/ship_0_8.c)
 * Author  : [1;36m�����[2;37;0m(yanyan@����˫��  )
 * Date    : Mon Mar 17 21:17:06 2003
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "������");
        set("long", @LONG
����һ��ǳ����Ĵ��գ������õ��������룬�Թ������ʱ��ʹ
�á��м���һ�Ŵ����ӣ������ʱ����ݽϸߵ��˶��������ӵ��Աߡ�
���ܻ��кܶ�Ϊˮ��׼����С��ʡ�
LONG
);
        set("exits",([
	"south" : __DIR__"ship_2_8",
        ]));
        setup();
//        replace_program(ROOM);
}
