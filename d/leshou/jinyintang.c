// /d/zhuojun/jinyintang.c
// Room in �ÿ�
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "������");
	set("long", @LONG
���������ٳ������һ�Ҷĳ�������ĶĿͶ����Ż��󣬳��ִ󷽣�
�������ʩ��������������ܵ��������ݺ�������������֮�������
��, һ�˸߹�һ�ˡ�
LONG
	);
	set("exits", ([
                "west"  :__DIR__"beidajie2",
		]));
	set("objects",([
		"/obj/dutu":1,
		]));
	setup();
	replace_program(ROOM);
}	
