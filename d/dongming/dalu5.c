
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "��·");
	set("long", @LONG
������һ����·�����߿���ңң�����Ž��ĳ����ˡ�������Ȼ�ش�
ƫƧ��������������������Ȼ�ܶࡣ
LONG);
	set("exits", ([
		"south":__DIR__"shanlu6",
		"north":__DIR__"dalu6",
		]));
      set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

