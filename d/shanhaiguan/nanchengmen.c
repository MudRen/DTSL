// /d/gaoli/nanmennei
// Room in ɽ����
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "�ϳ���");
	set("long", @LONG
������ɽ���ص��ϳ��ţ���̧ͷ��ȥֻ����[33m�� �� �� һ ��[0m��
��������֣�ɽ�����ǳ���ص��ʺ���ǰ���ر����أ���������
����������������ܵؽ磬����͵��˳��У���������صĴ����
ͨ��ӱ���ɽ����
LONG
	);
set("outdoors", "/d/shanhaiguan");
set("exits", ([
		"north" : __DIR__"nandajie",
		"south" : __DIR__"dadao2",
	        "eastup" : __DIR__"chengqiangshang1",
            	"westup" : __DIR__"chengqiangshang2",
                "southeast":"/d/yangzhoubei/haibin1"
	]));
 set("objects", ([
		__DIR__"npc/bing" : 2,
		__DIR__"npc/wujiang":1,
	]));
       setup();
	replace_program(ROOM);
}
