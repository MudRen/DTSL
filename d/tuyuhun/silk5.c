// /d/xingxiu/silk5.c
inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
����������ţ������ţ������������л�����û���׳��Ի�̨��
ɽ�ڸ���ǧ�𣬲Դ����Ρ������ͱ��޾����м�һ��С·������һ����
�ա�
LONG);
        set("outdoors", "tuyuhun");

        set("exits", ([
                "southeast" : __DIR__"silk12",
                "north" : __DIR__"silk11",
                "south" : __DIR__"silk5b",
        ]));

        setup();
}

