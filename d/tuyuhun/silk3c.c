// Room: /d/xingxiu/silk3c.c
// Jay 3.17/96
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", WHT"����Ȫ"NOR);
        set("long", @LONG
�����������֮�⣬��ɳĮ�о�Ȼ��һ�������ε�Ȫˮ�������ӻأ�
ˮ�ݴ������峺���ס�������������㡢���ǲݣ�������������Ȫ������
ɳɽȺ�У�����ɳ�ɣ�����Ȫ�������Ӳ�����Ȫ�ڡ�������һƬ�ͱڣ���
�ߴ������˵����졣
LONG
        );
        set("resource/water", 1);

        set("exits", ([
                "west" : __DIR__"silk7a",
                "east" : __DIR__"silk3b",
        ]));

        setup();
}
