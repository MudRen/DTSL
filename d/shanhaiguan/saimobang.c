// /d/gaoli/saimobang
// Room in ɽ����
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "��Į�����");
        set("long", @LONG
����ɽ���ص���Į��Ĵ��ţ���������վ�ڴ���ǰע�����������ˣ�
���ŵ��Ϸ���һ���ң��������߿������ױ����顣�ɼ���������Į��Ĺ�
ϵ�ε����С�
LONG
	);
set("outdoors", "/d/shanhaiguan");
set("exits", ([
            	"west" : __DIR__"dongdajie",
                "east" : __DIR__"siheyuan",
	]));
set("objects", ([
		__DIR__"npc/zhong" : 2,
	]));
       setup();
	replace_program(ROOM);
}
