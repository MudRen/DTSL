// /d/zhuojun/jinlou.c
// Room in �ÿ�
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "��¥");
	set("long", @LONG
����һ�����ٳ�������һָ�����ξ�Ʒ�����У��������Ľ�����
�ο���һ����������ϸ����˵�ܾ���ǰ������Ƶ����λ��ǹ�Ʒ�ء�
LONG
	);
set("exits", ([
                "north"  :__DIR__"dongdajie2",
	]));
set("objects",([
 __DIR__"npc/zhubao-boss":1,
 ]));
       setup();
	replace_program(ROOM);
}	
