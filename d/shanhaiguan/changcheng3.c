// /d/gaoli/aikou
// Room in ɽ����
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "����");
	set("long", @LONG
�����ǳ��ǵ�һ�����ڣ��س����ӳ��ǣ�ÿ����ʮ�ｨ��һ������
����פ�����ӣ����ǳ�����İ��ڣ���������Կ���һ���뺣����
���������ڡ�
LONG
	);
set("outdoors", "/d/shanhaiguan");
set("valid_startroom", 1);
set("exits", ([
	        "northeast" : __DIR__"changcheng2",
	        "west" : __DIR__"changcheng4",
            	"southdown" : "/d/yuyang/shandao4",
	]));
       setup();
	replace_program(ROOM);
}	
