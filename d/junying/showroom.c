//У��,showroom.c
inherit ROOM;
void create()
{
set("short","У��");
set("long",@LONG
�����ǻ�ͤ��פ����У������ͤ���Թ����ܺ�����Ϯ����֮��������
��͢���軪ͤפ���������������Χ�˷��ڣ�Э���ΰ���У����ɳ��������
������գ��ٱ������������ա����й���̨�ϣ�����һԱ�󽫣�˫Ŀ������
�ۿ�ʿ�����������Ϸ��Ǳ�Ӫ���ڡ������ǹ�Ѻ����֮���������Ǳ����⡣
LONG);
set("exits",([
"up":__DIR__"watchroom",
"west":__DIR__"laogate",
"east":__DIR__"wqgate",
"southeast":__DIR__"bingying",
]));
set("objects",([
__DIR__"npc/bing":4,
]));
setup();
}
