// /d/gaoli/guangchang
// Room in ɽ����
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "����㳡");
	set("long", @LONG
������ɽ���ص������ģ�һ���ܿ����Ĺ㳡��������ʯ���档һ��
�ϱ�����ѹ㳡һ��Ϊ����������������������������ˣ�����������
�У�һ�ɷ�����������һ��ʯ��·��֪ͨ��δ���
LONG
	);
set("outdoors", "/d/shanhaiguan");
set("exits", ([
	        "north" : __DIR__"beidajie",
            	"south" : __DIR__"nandajie",
                "east" : __DIR__"dongdajie",
                "west" : __DIR__"yamendamen",
                "northwest" : __DIR__"shibanlu",
	]));
 set("objects", ([
		"/d/shanhaiguan/npc/boy" : 1,
		//"/d/job/songwupin/rong" : 1,
	]));
 
       setup();
	replace_program(ROOM);
}
