// /d/gaoli/fenghuotai
// Room in ɽ����
// rich 99/04/05
inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
����������ڵ�����������ĳ����ˣ�ս��ʱ�ࡢ�ԡ��طֱ��޳�
ǽ������ū������ʼ�ʽ����еĳ�ǽ���������������ǣ���ϧ��������
���ң��������𣬶�ͻ������ǿ�󣬳���ʧȥ���������á�
LONG
	);
set("outdoors", "/d/shanhaiguan");
set("valid_startroom", 1);
set("exits", ([
	        "east" : __DIR__"changcheng3",
            	"southwest" : "/d/mayi/changcheng23",
	]));
       setup();
	replace_program(ROOM);
}
