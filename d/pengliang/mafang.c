inherit ROOM;


void create()
{
	set("short", "���");
	set("long", @LONG
��������ǣ���˧����Ҫ����һ֧ǿ��������ս������Ҫ�ģ���
�������ս��ĵط���Ȧ���ս����������׳����ˢϴ�ĸɸɾ�����
LONG
	);
        set("outdoors", "pengliang");


	set("exits", ([
		"south" : __DIR__"jiedao4",
	]));
	
	set("objects",([
	 __DIR__"npc/mafu":1,
	 ]));
	 
	setup();
	replace_program(ROOM);
}

