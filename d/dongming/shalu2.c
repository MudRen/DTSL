
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "ɳ·");
	set("long", @LONG
������һ��ɳ·�����������ս�ң����Ｘ��û��ʲô���ˣ�һƬ
������ɪ�����ա������Ӳݴ�����ֻ�м�ֻҰ�ò�ʱ����Ľ�ǰ�ܹ���
LONG);
	set("exits", ([
		"south":__DIR__"shalu1",
		"northwest":__DIR__"chaguan",
		]));
      set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

