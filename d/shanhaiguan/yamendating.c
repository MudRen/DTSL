// /d/gaoli/yamendating
// Room in ɽ����
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "���Ŵ���");
        set("long", @LONG
���϶����������ס������һ������������������ϸ������ǽ����
��һ�����ң����顰����������ĸ���������Ĵ��֡�֪���������İ�
���������飬ʦү�����ں�
LONG
	);
set("exits", ([
            	"east" : __DIR__"yamendamen",
                "enter":"/d/clone/room/cityroom/shanhaiguan",
	]));
       setup();
	replace_program(ROOM);
}
