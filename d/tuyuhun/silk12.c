// /d/xingxiu/silk.c

inherit ROOM;

void create()
{
        set("short", "˿��֮·");
        set("long", @LONG
�������������˿���̵�������ķ�ɳ����������Զ������������
��ԭ֮�ϣ���ʱ�ܿ���һƬƬ���̲�������ܼ����������ޣ��ϱ�����
ˮ�ǣ������������ʯ�ŵ�����
LONG);
        set("outdoors", "tuyuhun");

        set("exits", ([
                "northwest" : __DIR__"silk5",
                "south" : __DIR__"tianshui",
        ]));
        set("valid_startroom", 1);
        setup();
}

