// /d/gaoli/nandajie1
// Room in ɽ����
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "�ϴ��");
	set("long", @LONG
�����·�൱�Ŀ����ݺü�ƥ�����У������ĵ�·�ᴩ�ϱ���
����ɽ���ص��ϴ�֣���Ϊɽ�������������ԭ�ؾ�֮·������������
�����ر�࣬������һ��С�ƹݣ��ϱ���ɽ���ص����š�
LONG
	);
set("outdoors", "/d/shanhaiguan");
set("exits", ([
		"north" : __DIR__"guangchang",
		"south" : __DIR__"nanchengmen",
                "east" : __DIR__"xiaojiuguan",       
	]));
    set("objects",([
        __DIR__"npc/xunbu":1,
        ]));
       setup();
	replace_program(ROOM);
}	
