// Room: /d/junying/bingying.c

inherit ROOM;

void create()
{
	set("short", "��Ӫ");
	set("long", @LONG
�����Ǳ�Ӫ����Ӫ�ﾲ�żŵģ�����Ѳ�߱��⡣ûʲô���ˡ�Ӫ���ﵶ
ǹ�ڷ����롣һ�˶�ߵ�դ����Ӫ�̰��ڵ��С����߽����У��ƺ���Щ��·
���������е�һ��������һ��ɱ���������С���ͻȻ����һ��Ѳ�߱�������
���㣬�㲻���������㣬���ǸϿ��뿪Ϊ�
LONG
	);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xunluo" : 1,
]));
	set("exits", ([ /* sizeof() == 3 */
  "northwest" : __DIR__"showroom",
  "south" : "/d/huating/junying",
  "north" : __DIR__"wqgate",
]));

	setup();
	replace_program(ROOM);
}
