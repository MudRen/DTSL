// /d/gaoli/beichenglou
// Room in ɽ����
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "����¥");
	set("long", @LONG
�Ժϱ��ֵ�ľ��Ϊ�������ܶ��ǣ�ϧ��Ҳ������������ϧ����˪��
ʴ����Ŀȫ�ǣ���������Ҳ¶����ʯ�ĺۼ���������ȥ��ããԭҰ��
һ���ޱߣ��������Կ��������Ⱥɽ��
LONG
	);
set("outdoors", "/d/shanhaiguan");
set("exits", ([
	        "east" : __DIR__"chengqiangshang3",
            	"west" : __DIR__"chengqiangshang4",
	]));
       setup();
	replace_program(ROOM);
}
