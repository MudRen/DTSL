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
set("exits", ([
	        "south" : __DIR__"chengqiangshang1",
            	"north" : __DIR__"chengqiangshang3",
	]));
       setup();
	replace_program(ROOM);
}	
