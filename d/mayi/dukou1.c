// rich 99/04/05
inherit ROOM;
void create()
{
	set("short", "�ƺӶɿ�");
	set("long", @LONG
�����ǻƺӵ�һ���ɿڣ����¾��ǹ��������Ļƺ�ˮ��������Ҫ��
���ٸ�ʹ�á�
LONG
	);
set("outdoors", "/d/mayi");
set("valid_startroom", 1);
set("exits", ([
                "northeast" : __DIR__"huangtu2",
	]));
       setup();
	replace_program(ROOM);
}
