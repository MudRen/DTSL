
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", HIW"�ٲ�"NOR);
	set("long", @LONG
������һ���ٲ�������ֻ���ú�¡¡���������ٲ���ֱ���£���ɫ
��Ϊ׳�ۡ�
LONG);
	set("exits", ([
		"west":__DIR__"shulin2",
		]));
      set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

