// /d/gaoli/yijiange.c
// Room in �Ľ�С��
// laowuwu 99/06/27
inherit ROOM;
void create()	
{
	set("short", "�Ľ���");
	set("long", @LONG
����һ�����������ֵľ���,Ҳ���Ľ��ɵĺ���,������Ա�ǽ�����
�ġ����ﲼ�õĺܼ򵥣�һ�Ŵ󴲣��������ӣ���ǰ���佣÷��ǽ�Ϲ�
��һ�ѱ����� �������鷿��
LONG
	);
set("exits", ([
		"south" : __DIR__"zhuangmen",
              
	]));
        set("objects", 
        ([ 
                __DIR__"npc/fucailin" : 1,
        ]));
       setup();
	replace_program(ROOM);
}	
