// /d/gaoli/xuanwumen
// Room in ����
inherit ROOM;

void create()

{
set("short", "����");

	set("long", @LONG
��������һï�ܵĴ���֮�С����ܶ��ǲ���Ĺ�������ס��ͷ�ϵ�
���⡣��ʱ�м�ֻҰ�ô���������ܹ�������֮�У������˺ܶ����޶�
�ߣ��㲻��С��������
LONG
	);
	

set("outdoors", "/d/gaoli");
set("exits", ([
		"southeast" : __DIR__"shanlu2",
		"north" : __DIR__"jiangnan",
               
	]));
       setup();
	replace_program(ROOM);
}
