
inherit ROOM;
void create()	
{
	set("short","����С·");
	set("long", @LONG
������������Ҵ�Ĵ���С·������Ŀǰ������˿ڷǳ��٣�
��������Ҳֻ���޽���һ��С·�����ﻨ��ïʢ���羰����������
˵��������ʿ���ӵľ���ȥ��������ĵ��Ʋ��Ǻܸߣ����ܵ�Ⱥɽ
��ס����������磬���������ļ��紺��
LONG);
    set("exits", ([
	        "south" : __DIR__"nandajie2",
	        "east":__DIR__"wlq_sap",
	        "west":__DIR__"strong_cougar",
	        "north":__DIR__"nandajie4",
	       
 	]));
 	
      setup();
      replace_program(ROOM);
	
}
