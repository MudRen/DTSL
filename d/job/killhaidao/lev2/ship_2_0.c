/*
 * File    : ���� (/d/job/killhaidao/lev2/ship_2_0.c)
 * Author  : [1;36m�����[2;37;0m(yanyan@����˫��  )
 * Date    : Mon Mar 17 21:17:06 2003
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "����");
        set("long", @LONG
��������һ�Ҹս��ɲ��õĴ󴬣����Դ������滹Ʈɢ��һ������
������ζ������ͣ����ˮ���ڴ�����ҴҾ�����
LONG
);
        set("exits",([
	"south" : __DIR__"ship_4_0",
	"north" : __DIR__"ship_0_0",
	"east" : __DIR__"ship_2_2",
        ]));
        setup();
//        replace_program(ROOM);
}
