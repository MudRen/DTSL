// /d/gaoli/beibabang.c
// Room in ɽ����
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "���԰�");
        set("long", @LONG
������ɽ���ص�һ��ﱱ�԰�����ÿڣ���ڵĴ��Ž����ţ�����
������������Ľ���"���԰�"��������һ��ʯʨ�ӡ�
LONG
	);
set("outdoors", "/d/shanhaiguan");
set("exits", ([
            	"south" : __DIR__"shibanlu",
	]));
       setup();
	replace_program(ROOM);
}
