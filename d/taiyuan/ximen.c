// /d/taiyuan/ximen.c
// Room in ̫ԭ
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "̫ԭ����");
	set("long", @LONG
̫ԭ�����������������Ǳ��ұ���֮�أ��峯�������ռ��
���У�̫ԭ������ĸ����صأ�����̫ԭ�ķ���ʮ���ϸ����ŵĹ�
����ϸ���̲������Ŀ��̣�һ˿���Ҵ��⡣
LONG
	);
set("outdoors", "/d/taiyuan");
set("exits", ([
                "west" : __DIR__"road1",   
                "east" : __DIR__"xidajie1",       
	]));
       set("objects", ([
		__DIR__"npc/bing": 2,
		__DIR__"npc/wujiang":1,
	]));
       setup();
	replace_program(ROOM);
}	