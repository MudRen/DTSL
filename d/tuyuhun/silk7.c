// /d/xingxiu/silk7.c
inherit ROOM;

void create()
{
        set("short", "�ػ�");
        set("long", @LONG
�����Ƕػͳ����ڵأ���˿��֮·�ϵ��ʺ����������ǽ���ʣ�
���и߳���ǽһ���ĳǶա����ڻ������Χ�Ķ�����壬���ڴ���Ͽ�
�����������޲�͸�����档
LONG);
        set("outdoors", "tuyuhun");

        set("exits", ([
                "southeast" : __DIR__"silk6",
                "west" : __DIR__"silk8",
                "southdown" : __DIR__"silk7a",
        ]));

        setup();
}

