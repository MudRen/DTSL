
inherit ROOM;

void create()
{
        set("short", "�¹Ȼ��ٹ��");
        set("long", @LONG
�������¹Ȼ붼�ǡ��¹Ȼ�ԭΪ�ʱ���һ֧�������ڱ�����������
���¹Ȼ���������Ǩ�ڴˡ����¹Ȼ�Ϊ��������ɺ��������ڷ�ٹ���ڡ�
���ڻ������Χ�Ķ�����壬���ڴ���Ͽ������������޲�͸�����档
LONG);
        set("outdoors", "tuyuhun");

        set("exits", ([
                "east" : __DIR__"silk7",
                "northwest" : __DIR__"silk9",
               // "south" : __DIR__"nanjiang",
                "north" : "/d/clone/room/cityroom/tuyuhun",
        ]));

        set("objects", ([
                __DIR__"npc/shangren" : 1,
               
        ]));

        setup();
}

