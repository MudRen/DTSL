// /d/gaoli/ zhuangmen
// Room in  ׯ��
// laowuwu 99/06/27
inherit ROOM;
void create()	
{
	set("short", "�Ľ�С��");
	set("long", @LONG
���������Ľ��ɵ�����,������ڵĴ��ų�����,����������
������Ĵ���"�Ľ�С��"��������Ǹ��������ӵ��Ľ�С���ˡ�
LONG);
set("outdoors", "/d/yijiange");
set("exits", ([
		"north" : __DIR__"yijiange",
                "southeast" :__DIR__"xiaojing",
                
              
	]));
        set("objects", 
        ([
                __DIR__"npc/qiang" : 1,
        ]));
       setup();
	replace_program(ROOM);
}	
