#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "天山脚下");
        set("long", @LONG
这里是天山脚下，西北面是高耸入云的天山，抬头仰望可以看到天
山顶上的万年积雪。一道天山将西域分为两半，北疆是西域各族的聚居
区，南疆是广阔无边的大草原。往西便是吐谷浑城。
LONG);
        set("exits", ([
            //"north" : __DIR__"xxh",
            "southeast" : __DIR__"silk9",
         ]));

        set("outdoors", "tuyuhun" );

        setup();
}

