inherit ROOM;

void create()
{
        set("short", "ɳ��·");
        set("long", @LONG
����һ������̫���ߵ�ɳ��·��������Ҫ����ɳĮ�����ˣ����˺�
�٣�ֻ��ż���ῴ��һЩ���ú����նӡ�
LONG
        );
        set("exits", ([
          "northwest" : __DIR__"qinghaihu",
          "east" : __DIR__"shatulu2",
        ]));

        set("outdoors", "tuyuhun");
        set("valid_startroom", 1);
        setup();
        replace_program(ROOM);
}
