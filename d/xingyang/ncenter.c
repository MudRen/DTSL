inherit ROOM;

void create()
{
	set("short", "�ڳ�");
	set("long", @LONG
�����������ڳǵ�ʮ�ֽ�ͷ���ڶ�����һ��С�ϳ����㻹������ʿ
��������������������һ����ۡ��������һ��������ľ�����
LONG );

	set("exits", ([
                          "north"      : __DIR__"chengmen",		
	]));

        set("objects",([
            "/d/job/questjob/npc/shenluoyan":1,
            ]));
 	set("outdoors", "xingyang");
	setup();
	replace_program(ROOM);
}



