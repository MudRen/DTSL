
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "С·");
	set("long", @LONG
������һ��С·���ϱ���һ���ۿڡ���������˺��١����߾�����
��ɽ�ˣ��м����οʹ��������˹�����
LONG);
	set("exits", ([
		"south":__DIR__"gangkou2",
		"westup":"/d/wuyishan/doupo3",
		]));
      set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

