// Room: /d/hengshan/huixiantai.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "����̨");
        set("long", @LONG
�߳���������ܿ���һ��ʯ�ߣ������ھ����������һ��С�ң�
���ǻ���̨��̨������Ⱥ�ɵ����������飬����ʤ����
LONG);
        set("exits", ([
           "eastdown"  : __DIR__"beiyuedian",
        ]));
        setup();
        replace_program(ROOM);
}

