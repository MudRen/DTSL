
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "ɽ·");
	set("long", @LONG
������һ��ɽ·�����������ߣ����ǽ����ľ����ˡ������̺���ϣ�
��ɽ��Ұ�����ʻ������������Ѽ���
LONG);
	set("exits", ([
		"southeast":__DIR__"tulu1",
		"northwest":__DIR__"shanlu6",
		]));
      set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

