// /d/zhuojun/yanfulou.c
// Room in �ÿ�
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "�޸�¥");
	set("long", @LONG
�޸�¥�����ٳ�����һ�Ҽ�Ժ���ϱ����ؼ���Ӧ�о��У���ʩ��
����һ���������ܹ�˵ġ��޸�¥�ﲻʱ��������Ц����
LONG
	);
set("exits", ([
		"east" :__DIR__"yanzixiang",
	]));
       setup();
	replace_program(ROOM);
}	
