
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "��·");
	set("long", @LONG
������һ�����Ĵ�·�����߾��Ǻ��ݵ������ˡ�����ĵ�·�ǳ�
�������ܾ�ɫ��������ʱ�д�ӵĹٱ�����������߹�����ͷ�Ľ���
��ʱ��ͷ�������㡣
LONG);
	set("exits", ([
		"south":__DIR__"dalu3",
		"north":"/d/hangzhou/nanmen",
		]));
      set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

