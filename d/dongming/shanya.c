
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"ɽ��"NOR);
	set("long", @LONG
������һ��ɽ�¡�����������׵���Ԩ�������¿��˿���������
�ֽŷ���
LONG);
	set("exits", ([
		"north":__DIR__"shulin2",
		]));
      set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

