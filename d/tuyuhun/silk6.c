// /d/xingxiu/silk6.c

inherit ROOM;

void create()
{
        set("short", "˿��֮·");
        set("long", @LONG
�������������˿���̵�����ɳ������һƬ�����������������
����ɽ��������������º�����һ�������ֻ���м��˺ϱ�֮�ֵĹ���
�����Ȼͦ���ڻ�ԭ�ϣ�Цӭ��ɳ��ƵƵ�к����ˡ�������һƬ��ɳ��
����ɳĮ�Ϳ��Ե�������ɽ����
LONG);
        set("outdoors", "tuyuhun");

        set("exits", ([
              "southeast" : __DIR__"silk3a",
              "northwest" : __DIR__"silk7",
        ]));

        set("objects", ([
                __DIR__"npc/shangren" : 1,
        ]));

        setup();
}

