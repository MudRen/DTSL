// /d/gaoli/shibanlu
// Room in ɽ����
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "ʯ��·");
        set("long", @LONG
���涼������ʯ�̳ɣ����Ͼ����ĵģ�������ɽ���ص����Ĺ㳡��
������ɽ���ص�һ���"���԰�"���ܶ�ڡ�
LONG
	);
set("outdoors", "/d/shanhaiguan");
set("exits", ([
            	"southeast" : __DIR__"guangchang",
                "north" : __DIR__"beibabang",
	]));
       setup();
	replace_program(ROOM);
}
