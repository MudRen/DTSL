// /d/zhuojun/ximen.c
// Room in �ÿ�
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "����");
	set("long", @LONG
���������ٵ������ţ������ߣ��ͽ������ÿ��ǣ������߾ͽ���
ɽ��������Ϊ�������´������԰��ŵ�ʿ����������·�����̲�÷ǳ�
�ϸ�
LONG
);

set("outdoors", "/d/zhuojun");
set("exits", ([
		"east" :__DIR__"xidajie1",
                "west"  :__DIR__"road1",
	]));
       set("objects",([
                __DIR__"npc/guanbing" : 2,
                __DIR__"npc/wujiang" : 1,
        ]));
       setup();
	replace_program(ROOM);
}	
