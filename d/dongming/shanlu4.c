
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "ɽ·");
	set("long", @LONG
��������ɽ·����������˽��������������кܶ�������ʿ������
���߹���
LONG);
	set("exits", ([
		"southeast":__DIR__"shanlu3",
		"northwest":"/d/jiujiang/tulu2",
		]));
      set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

