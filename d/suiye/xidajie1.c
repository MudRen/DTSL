// /d/suiye/xidajie1
// Room in ��Ҷ
// laowuwu 99/03/28
inherit ROOM;
void create()	
{
	set("short", "�����");
	set("long", @LONG
������Ҷ����֣���������ƺ��˸����ˣ���������ļ����˽���
����Ļ��꣬���������Ĳ����һ���������Ƶ�С�к�����������
��ʲô��
LONG
	);
set("outdoors", "/d/suiye");
set("exits", ([
		"south" : __DIR__"zhubaodian",
		"north" :  __DIR__"huadian",
                "east"  : __DIR__"zhongxinguanchang",
                "west"  :__DIR__"xidajie2",
	]));
	set("objects",([
	  "/d/quest/yunshuai-dodge/yunshuai":1,
	  "/d/quest/yunshuai-dodge/lianrou":1,
	]));
       setup();
	replace_program(ROOM);
}	
