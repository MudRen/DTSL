// /d/suiye/nandajie1
// Room in ��Ҷ
// laowuwu 99/03/28
inherit ROOM;
void create()	
{
	set("short", "�ϴ��");
	set("long", @LONG
·������ôխ����Ҳ�����ˣ�ֻ�м����������ʿ��·�ϻ��š���
���ǹٸ��������Ǳ����̡�
LONG
	);
set("outdoors", "/d/suiye");
set("exits", ([
		"south" : __DIR__"nandajie2",
		"north" :  __DIR__"zhongxinguanchang",
                "east"  : __DIR__"guanfu",
                "west"  :__DIR__"yanju",
	]));
	set("objects",([
	 "/d/clone/npc/bafenghan":1,
	 ]));
       setup();
	replace_program(ROOM);
}	
