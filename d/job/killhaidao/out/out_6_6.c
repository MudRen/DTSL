/*
 * File    : �װ� (/d/job/killhaidao/out/out_6_6.c)
 * Author  : [1;36m�����[2;37;0m(yanyan@����˫��  )
 * Date    : Mon Mar 17 21:21:40 2003
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "�װ�");
        set("long", @LONG
�����Ǵ󴬵ļװ壬����ˮ��������æ��æȥ����ͣ�����˴Ӵ�
���б�����ˮ���Ǵ������µ����
LONG
);
        set("exits",([
	"west" : __DIR__"out_6_4",
	"east" : __DIR__"out_6_8",
        ]));
set("outdoors","out");
        setup();
//        replace_program(ROOM);
}
