// Room: /d/hengshan/xuangengsong.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
���ڻ�����������յأ�ȴ��һ����ɣ��䱻��紵��������¶��
ǧ��������ӭ��ͦ��������Ǻ�ɽ������ "������" ��
LONG);
        set("exits", ([ 
           "east"      : __DIR__"hufengkou",
        ]));
        set("outdoors", "hengshan");
        setup();
        replace_program(ROOM);
}

