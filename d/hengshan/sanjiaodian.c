// Room: /d/hengshan/sanjiaodian.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "���̵�");
        set("long", @LONG
������ȫ����ߴ������̵Ҳ�����������ĵ������ż���
ȫ����ÿ��������ʯ��ľ�����ܣ����� "��������"�� �Ž��漣��
LONG);
        set("exits", ([ 
           "down"   : __DIR__"xuankong1",
        ]));
        setup();
        replace_program(ROOM);
}
