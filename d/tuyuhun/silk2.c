inherit ROOM;

void create()
{
        set("short", "˿��֮·");
        set("long", @LONG
�������������˿���̵���ӭ���������һ����ɳ���������岼�
��ԭ֮�ϡ�һ���ɳ�������󵶸�һ��˺�������������������
ɽͨ�������أ�����������Ħ�¡�
LONG);
        set("outdoors", "tuyuhun");

        set("exits", ([
                "westup" : __DIR__"silk3",
                "south" : __DIR__"silk1",
        ]));

     /*   set("objects", ([
                __DIR__"npc/shangren" : 1,
        ]));*/

        setup();
}

