// /d/xingxiu/silk5.c
inherit ROOM;

void create()
{
        set("short", "石门");
        set("long", @LONG
这里两峰对峙，形如门，故名。又因常有虎豹出没，俗称卧虎台。
山壁高立千仞，苍翠欲滴。四周峭壁无径，中间一条小路。真是一座天
险。
LONG);
        set("outdoors", "tuyuhun");

        set("exits", ([
                "southeast" : __DIR__"silk12",
                "north" : __DIR__"silk11",
                "south" : __DIR__"silk5b",
        ]));

        setup();
}

