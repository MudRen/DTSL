/*
 * File    : ��ͷ (/d/job/killhaidao/out/out_6_10.c)
 * Author  : [1;36m�����[2;37;0m(yanyan@����˫��  )
 * Date    : Mon Mar 17 21:21:40 2003
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "��ͷ");
        set("long", @LONG
���ߵ��˴�ͷ����ǰ��һ���޼ʵĴ󺣣�����ĺ���ӭ�洵������
ֻ��Ÿ�ں����ϵ͵͵ķɹ�������һ�����Ľ�����
LONG
);
        set("exits",([
	"west" : __DIR__"out_6_8",
        ]));
set("outdoors","out");
        setup();
//        replace_program(ROOM);
}
