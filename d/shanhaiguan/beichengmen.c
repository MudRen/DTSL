// /d/gaoli/beimennei
// Room in ɽ����
// rich 99/04/05
// modify by yang

inherit ROOM;
void create()	
{
	set("short", "������");
	set("long", @LONG
������ɽ���صı����ţ���̧ͷ��ȥֻ�������� �� �� һ �ء���
��������֣�ɽ�����ǳ���ص��ʺ���ǰ���ر����أ��������´���
������������ܵؽ磬����͵��˳��У������ǳ��صĴ����ͨ�����
�Ͷ�ͻ�ʡ�
LONG
	);
set("outdoors", "/d/shanhaiguan");
set("exits", ([
		"north" : "/d/saiwai/road1",
		"south" : __DIR__"beidajie",
	        "eastup" : __DIR__"chengqiangshang3",
            	"westup" : __DIR__"chengqiangshang4",
	]));
 set("objects", ([
		__DIR__"npc/bing" : 2,
		__DIR__"npc/wujiang":1,
	]));
       setup();
	replace_program(ROOM);
}
