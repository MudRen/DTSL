// /d/zhuojun/dongmen.c
// Room in �ÿ�
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "����");
	set("long", @LONG
�������ٵĶ����ţ��������߾ͽ��������ٳǣ���Ϊ�������´��ң�
���԰��ŵ�ʿ����������·�����̲�÷ǳ��ϸ�
LONG
	);
set("outdoors", "/d/zhuojune");
set("exits", ([
		"east" :__DIR__"eroad1",
                "west"  :__DIR__"dongdajie1",
	]));
       set("objects",([
                __DIR__"npc/guanbing" : 2,
                __DIR__"npc/wujiang" : 1,
        ]));
       setup();
	replace_program(ROOM);
}	
