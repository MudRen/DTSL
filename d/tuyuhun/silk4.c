// /d/xingxiu/silk4.c

inherit ROOM;

void create()
{
        set("short", "˿��֮·");
        set("long", @LONG
�������������˿���̵���ӭ���������һ����ɳ���������岼�
��ԭ֮�ϡ�һ���ɳ�������󵶸�һ��˺�������������������Ħ�£�
���������߱��ǡ�
LONG);
        set("outdoors", "tuyuhun");

        set("exits", ([
                "eastup" : __DIR__"silk3",
                "westup" : __DIR__"silk5a",
                
        ]));

        set("objects", ([
                __DIR__"npc/shangren" : 1,
        ]));

        setup();
}

