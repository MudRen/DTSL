// /d/zhuojun/beidajie1.c
// Room in �ÿ�
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "�����");
	set("long", @LONG
��������ʯ�̳ɵ���·����������������ô���������ÿ��ı�
���ţ��������߲�Զ�����ÿ������Ĺ㳡�����洫�����������Ĵ�������
������һ��С�ﲻ֪ͨ��δ���
LONG
	);
set("outdoors", "/d/zhuojun");
set("exits", ([
		"north" :__DIR__"beimen",
                "south"  :__DIR__"beidajie2",
                "west"  :__DIR__"tiejiangpu",
                 "east"  :__DIR__"xiaoxiang",
                "northeast":"/d/clone/room/cityroom/leshou",
	]));
       setup();
	replace_program(ROOM);
}	
