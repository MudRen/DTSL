// /d/gaoli/chengqiangshang2
// Room in ɽ����
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "��ǽ��");
	set("long", @LONG
��վ��ɽ���صĳ�ǽ�ϣ���Ϊ���µ�ԭ��ɽ���صĳ�ǽ�޵�
�ر��̣������ǳ��ǵķ��̨��������ɽ���ص��ϳ�¥��
LONG
	);
set("outdoors", "/d/shanhaiguan");
set("exits", ([
		"north" : __DIR__"fenghuotai",
	        "east" : __DIR__"nanchenglou",
            	"eastdown" : __DIR__"nanchengmen",
	]));
       setup();
	replace_program(ROOM);
}	
