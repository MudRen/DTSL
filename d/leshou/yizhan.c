// /d/zhuojun/yizhan.c
// Room in �ÿ�
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "��վ");
	set("long", @LONG
����һ�����峯����վ��������Ϊս�ң����Դ���վ�Ѿ����ķѣ�
ֻҪ���ڴ˾������ƵĻҳ���Ǻ����ֱ���ԣ����Լ���û�˾����˴���
LONG
	);
set("outdoors", "/d/zhuojun");
set("exits", ([
                "south"  :__DIR__"xidajie1",
	]));
       setup();
	replace_program(ROOM);
}	
