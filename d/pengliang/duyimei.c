#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��һζ");
        set("long", @LONG
���𡰶�һζ����Բ�������˲�֪�������ʽ���Ⱦ���һ��������
����ս�ҵ�ԭ������������û�м����ˡ���С����������˯��
LONG);
        set("exits", ([
            "north"  : __DIR__"dongdajie",
        ]));
        set("objects", ([
            __DIR__"npc/xiaoer2" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
