// Room: /d/hengshan/jinlongxia.c


inherit ROOM;

void create()
{
	set("short", "����Ͽ");
	set("long", @LONG
����Ͽ�ֳ��������ǽ����ɽ����ڡ���ɽһ��̫��ɽ�����������
�������еı�����������֮Ϊ "����С����" ������ب���������һ��
�н��еĶ��У�������Ϊ "��ɽ����" ����� "̩ɽ����" ��"��ɽ����"��
"��ɽ����"��"��ɽ���"��
LONG
	);
	set("exits", ([
		"southeast"  : __DIR__"cuipinggu1",
"northeast"  : "/d/taiyuan/road7-2",
	]));
 set("objects",([ "/d/clone/npc/beast/shizi":1,]));
	/*set("objects", ([
		__DIR__"npc/jing" : 1,
	]));*/
	set("outdoors", "hengshan");
	setup();
        replace_program(ROOM);
}

