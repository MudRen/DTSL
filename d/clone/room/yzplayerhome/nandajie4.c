
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
	        "south" : __DIR__"nandajie3",
	        "west":__DIR__"tianyia/door",
	        "north":__DIR__"nandajie5",
	        "east":__DIR__"huayuan",
 	]));
 	
      setup();
      replace_program(ROOM);
	
}