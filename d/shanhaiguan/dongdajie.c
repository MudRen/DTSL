// /d/gaoli/dongdajie1
// Room in ɽ����
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "�����");
	set("long", @LONG
�����·�൱�Ŀ����ݺü�ƥ�����У����涼������ʯ�̳ɣ�
����������Į����ÿڣ�������ɽ���ص��ξ֣����洫����С��ߺ������
LONG
	);
set("outdoors", "/d/shanhaiguan");
set("exits", ([
		"north" : __DIR__"yanju",
		"south" : __DIR__"duchang",
                "east" : __DIR__"saimobang",  
                "west" : __DIR__"guangchang",        
	]));
     set("objects",([
        __DIR__"npc/man":1,
        ]));
       setup();
	replace_program(ROOM);
}	
