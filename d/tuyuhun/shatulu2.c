inherit ROOM;

void create()
{
        set("short", "ɳ��·");
        set("long", @LONG
����һ������̫���ߵ�ɳ��·��������Ҫ����ɳĮ�����ˣ����˺�
�٣�ֻ��ż���ῴ��һЩ���ú����նӡ��������򶫣��͵�����ˮ�ǡ�
LONG
        );
        set("exits", ([
          "west" : __DIR__"shatulu1",
          "east" : __DIR__"tianshui",
        ]));

        set("outdoors", "tuyuhun");
        set("valid_startroom", 1);
        setup();
        replace_program(ROOM);
}
