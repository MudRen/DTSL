// /d/gaoli/chengqiangshang3
// Room in ɽ����
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "��ǽ��");
	set("long", @LONG
��վ��ɽ���صĳ�ǽ�ϣ���Ϊ���µ�ԭ��ɽ���صĳ�ǽ�޵��ر��
�̣������ǳ��ǵ�һ�����ڣ�������ɽ���صı���¥��
LONG
	);
set("outdoors", "/d/shanhaiguan");
set("exits", ([
		"south" : __DIR__"aikou",
	        "west" : __DIR__"beichenglou",
            	"westdown" : __DIR__"beichengmen",
	]));
       setup();
	replace_program(ROOM);
}	
