// /d/xingxiu/silk3.c
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", YEL"��ɳɽ"NOR);
        set("long", @LONG
��ɽ����ʮ�ף�ɽ�嶸�ͣ����絶�С���´������Ȫ����ɽ���
ɳ����������Ȫ��������ɽ���»�ɳ����������׹�����������ڶ�����
ζ��Ȼ���ʳơ�ɳ����������
LONG);
        set("outdoors", "tuyuhun");

        set("exits", ([
                "south" : __DIR__"silk3",
                "westdown" : __DIR__"silk3b",
                "northwest" : __DIR__"silk6",
        ]));

        setup();
}

