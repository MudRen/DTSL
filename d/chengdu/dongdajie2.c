
inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
���ǳɶ��Ķ���֡�����ͨ�򶫳��ţ������Եúܷ�æ���ϱ���һ
����լۡ����֪���ĸ����ҹ������ӡ�������һ��С�Ե꣬���洫����
����ķ����㡣
LONG);
        set("outdoors", "�ɶ�");

	set("exits", ([
		"east" : __DIR__"dadongmen",
		"west" : __DIR__"dongdajie1",
		"south" : __DIR__"door",
		"north":__DIR__"xiaochi",
	]));
	
	set("objects",([
	   "/d/job/questjob/npc/baiwenyuan":1,
	   ]));

	setup();
	replace_program(ROOM);
}

