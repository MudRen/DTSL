// /d/xingxiu/silk.c

inherit ROOM;

void create()
{
        set("short", "˿��֮·");
        set("long", @LONG
�������������˿���̵���ӭ���������һ����ɳ���������岼�
��ԭ֮�ϡ�һ���ɳ�������󵶸�һ��˺�����������������һ����ΰ
�Ĺذ���������ͨ������
LONG);
        set("outdoors", "tuyuhun");

        set("exits", ([
                "east" : "/d/taiyuan/jiayuguan",
                "northwest" : __DIR__"silk1",
                "southwest" : __DIR__"silk1b",
                "southeast" : __DIR__"silk11",
        ]));

        set("objects", ([
                __DIR__"npc/shangren" : 1,
        ]));

        setup();
}

