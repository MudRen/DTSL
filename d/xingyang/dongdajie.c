inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�����������ڶ����ĵ������ߡ�����ɫɫ�Ľ������ڶ��ߴ���˷���
���಻����·�ϳ�ˮ��������ɫ����Ħ����࣬���ַǷ���
LONG );

	set("exits", ([
                         "west"      : __DIR__"center",
                         "east"      : __DIR__"dongmen",
		
	]));
        set("objects",([
           __DIR__"npc/xiaojie":1,
           
           ]));

 	set("outdoors", "xingyang");
	setup();
	replace_program(ROOM);
}



