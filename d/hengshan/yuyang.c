// Room: /d/hengshan/yuyang.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��������");
        set("long", @LONG
�����ͱ��¶��ϣ���ʯ���ۣ�ɢ�����£�����������£����ж��У�
�����ڳԲݵ���ֻ������Ǻ͡��𼦱����������ĺ�ɽʤ�����������ơ���
LONG);
        set("exits", ([ 
           "westdown"    : __DIR__"beiyuedian",
"enter":"/d/quest/csj/shandong",
        ]));
        set("outdoors","hengshan");
 set("objects",([ "/d/clone/npc/beast/songshu":1,]));
        setup();
        replace_program(ROOM);
}

