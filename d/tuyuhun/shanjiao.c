#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��ɽ����");
        set("long", @LONG
��������ɽ���£��������Ǹ������Ƶ���ɽ��̧ͷ�������Կ�����
ɽ���ϵ������ѩ��һ����ɽ�������Ϊ���룬�������������ľ۾�
�����Ͻ��ǹ����ޱߵĴ��ԭ�����������¹Ȼ�ǡ�
LONG);
        set("exits", ([
            //"north" : __DIR__"xxh",
            "southeast" : __DIR__"silk9",
         ]));

        set("outdoors", "tuyuhun" );

        setup();
}

