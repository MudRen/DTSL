inherit ROOM;

void create()
{
	set("short", "�ڳǳ���");
	set("long", @LONG
�˼����������ڳǵĳ��ţ�����Ϊ���������ڳǳ�ǽ��ʯ�����
�ݳɣ������壬������ࡣ�������������������ľ�ʿ�����Ͼ�������
���ڳ��ˡ�
LONG );

	set("exits", ([
                          "north"      : __DIR__"center",
                         "south"      : __DIR__"ncenter",
                         "east":"/d/clone/room/cityroom/xingyang",
		
	]));
    set("objects",([
     __DIR__"npc/bing":2,
     "/d/job/questjob/npc/zhairang":1,
     
     ]));

 	set("outdoors", "xingyang");
	setup();
	replace_program(ROOM);
}



