// /d/gaoli/nanchenglou
// Room in ɽ����
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "�ϳ�¥");
	set("long", @LONG
�Ժϱ��ֵ�ľ��Ϊ�������ܶ��ǣ�ϧ��Ҳ������������ϧ����˪��
ʴ����Ŀȫ�ǣ���������Ҳ¶����ʯ�ĺۼ���������ȥ��һƥƥ�Ŀ�
����Զ������
LONG
	);
set("outdoors", "/d/shanhaiguan");
set("exits", ([
	        "east" : __DIR__"chengqiangshang1",
            	"west" : __DIR__"chengqiangshang2",
	]));
       setup();
	replace_program(ROOM);
}	
