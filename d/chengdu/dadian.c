
inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
��������Ĵ�������������ģ�ûʲô�������㡣����Ҳ��Щ
�ƾ��ˣ��㰸�ϳ��˼�ס�����û�����������ˡ����Ϸ���һ���ƾɵ�
���ź�һ��ľ�㣬�Ա���һ��ɮ������������������
LONG);
	set("exits", ([
		"out":__DIR__"simiao",
		"enter":"/d/quest/jzzy/baodian",
		"west":"/d/quest/jzzy/jingfang",
	]));
  set("objects",([
          "/d/quest/bawangdao/npc/heshang":1,
	  ]));

	setup();
	replace_program(ROOM);
}

