// /d/xingxiu/silk.c

inherit ROOM;

void create()
{
        set("short", "˿��֮·");
        set("long", @LONG
�������������˿���̵���ӭ���������һ����ɳ���������岼�
��ԭ֮�ϡ�һ���ɳ�������󵶸�һ��˺�����������
LONG);
        set("outdoors", "tuyuhun");

        set("exits", ([
                "northwest" : __DIR__"silk",
                "south" : __DIR__"silk5",
        ]));

        set("objects", ([
                __DIR__"npc/shangren" : 1,
        ]));

        setup();
}

