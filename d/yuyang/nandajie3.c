// /d/qiuci/nandajie3
// Room in ���� 
// laowuwu 99/04/11
inherit ROOM;

void create()
{
	set("short", "�ϴ��");
	set("long", @LONG
�����·�൱�Ŀ����ݺü�ƥ�����У������ĵ�·�ᴩ�ϱ���
�����������ϲ���������һ�������̣���ʱ�ش�������ײײ�������ϱ�
�����š�
LONG
	);
        set("outdoors", "/d/qiuci");

	set("exits", ([
                "southwest" : __DIR__"nanmen",
                "north" : __DIR__"bingqipu",
                "east" : __DIR__"nandajie2",
	]));

      

	setup();
}


