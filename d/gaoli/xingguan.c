// /d/gaoli/xingguan
// Room in ����
inherit ROOM;
void create()	
{
	set("short", "��ʿ�й�");
	set("long", @LONG
�������йݵĴ��������а���һ��ɼľԲ���ͼ������ӣ�������һ
�׾��µ����˴�������������һ����ʯ���磬��˵�Ǹ����ʵ����͡�
LONG
	);
set("exits", ([
                "east":__DIR__"yudao5",
                "enter":__DIR__"neitang",
	]));
set("objects", ([
		"/d/gaoli/npc/shi1" : 4,
		"/d/yjp/npc/tuoba-miefu":1,
	]));
       setup();
     "/obj/board/party_yj_b.c"->foo();
}	
