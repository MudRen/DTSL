inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
������ͨ�������˿���·�������ĳ���������������ţ�ӭ���
������������ˡ���ʱ��һ�Ӷ����˴�����߲��������
LONG
        );
        set("exits", ([
          "northwest" : __DIR__"road2",
        ]));

        set("outdoors", "tuyuhun");

        setup();
        replace_program(ROOM);
}
