// Room: /d/hengshan/tongyuangu.c
#include <room.h>
inherit "/std/lingwuroom2";

void create()
{
        set("short", "ͨԪ��");
        set("long", @LONG
ͨԪ�ȹ´����Է��£��ഫΪ�Ź��ϳ���ǰ�޵�֮��������������
 "ͨԪ" ������Ҳ�ͳ���ͨԪ�ȡ�
LONG);
        set("exits", ([
           "eastup"  : __DIR__"guolaoling",
        ]));
        set("outdoors", "hengshan");
        setup();
}
