// /d/gaoli/fenghuotai
// Room in ɽ����
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "���̨");
	set("long", @LONG
�����ǳ��ǵķ��̨���Ŵ��Է���ţ�ÿ���ео����ַ���ʱ��
�͵�ȼ�����򸽽��ľ��ӱ��ţ�������̨��Ϊս���Ծ��ķ��ˡ�
LONG
	);
set("outdoors", "/d/shanhaiguan");
set("valid_startroom", 1);
set("exits", ([
	        "south" : __DIR__"chengqiangshang2",
            	"north" : __DIR__"chengqiangshang4",
            	"westup" : __DIR__"changcheng1",
	]));
       setup();
	replace_program(ROOM);
}	
