// /d/zhuojun/road1.c
// Room in �ÿ�
// modify by yang

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ���Ȼ�ֽ����´��ң��������ܻ�
�����������������ӵġ����̵ġ����Ŵ󳵵���������������ǳ���
�֡���ʱ����������������߷ɳ۶���������һ·��������·������
��������������֡�
LONG);

	set("exits", ([
		"north": __DIR__"nanmen",
		"south": __DIR__"road6",
		
	]));

       set("objects",([
                __DIR__"npc/shang" : 2,
        ]));
 	set("outdoors", "zhuojun");
	setup();
	replace_program(ROOM);
}



