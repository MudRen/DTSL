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
          "southwest" : __DIR__"road3",
          "southeast" : __DIR__"road1",
        ]));

        set("outdoors", "tuyuhun");

        setup();
        replace_program(ROOM);
}
