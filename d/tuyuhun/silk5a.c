// /d/xingxiu/silk5a.c
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", BRED"��֬ɽ"NOR);
        set("long", @LONG
��֬ɽ��ɽʯ��������֬������������ˮ�ݷ�����������������ѩ
�ڻ��������������£��㼯������ɽ���̲��������Ӫ�ݳ�̲���Ǿø�
ʢ����������
LONG);
        set("outdoors", "yili");

        set("exits", ([
                "eastdown" : __DIR__"silk4",
                "northwest" : __DIR__"silk7a",
        ]));

        setup();
        set("yushi_count", 1);
}
