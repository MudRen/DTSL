// /d/gaoli/aikou
// Room in ɽ����
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "���Ŵ���");
        set("long", @LONG
���������Ŵ��ţ�������ľ���Ž����ر��š����ྲ�����ء�����
�ӷַ���ͷʯʨ�ӵ��Աߡ�ǰ����һ����ģ���Ȼ�ǹ�С����ԩ�õġ�
������������ǰѲ�ߡ�
LONG
	);
set("outdoors", "/d/shanhaiguan");
set("exits", ([
	        "east" : __DIR__"guangchang",
            	"west" : __DIR__"yamendating",
	]));
       setup();
	replace_program(ROOM);
}
