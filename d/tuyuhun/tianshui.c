
inherit ROOM;

void create()
{
        set("short", "��ˮ");
        set("long", @LONG
��������ˮ�����ڵأ��������򱱣���Ҫ����˿��֮·�ˣ����Գ�
����ȻС������ȴ�ǳ����֣����������Ŀ��̷׷��ڴ���׼������������
���ڴ���Ͽ���������Ŀ��Ͼ�ӡ�
LONG);
        set("outdoors", "tuyuhun");

        set("exits", ([
                "north" : __DIR__"silk12",
                "west" : __DIR__"shatulu2",
                "east" : "/d/changan/guandao5",
        ]));
  
        set("valid_startroom", 1);

        setup();
}

