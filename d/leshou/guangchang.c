// /d/zhuojun/guangchang.c
// Room in �ÿ�
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "���Ĺ㳡");
        set("long", @LONG
������λ�����ٳǵ����ĵ����Ĺ㳡��һ����¥���������Ĺ㳡��
���룬����������ٳǺ�ɫ��������������֬��ϣ��������������
��ͨ�����ٵĸ������š�
LONG
	);
set("outdoors", "/d/zhuojun");
set("exits", ([
		"north" :__DIR__"beidajie2",
                "south"  :__DIR__"nandajie2",
                "west"  :__DIR__"yanzixiang",
                 "east"  :__DIR__"dongdajie2",
	]));
	set("objects",([
	  __DIR__"npc/bing":1,
	  ]));
       setup();
	replace_program(ROOM);
}	
