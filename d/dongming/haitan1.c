
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"��̲"NOR);
	set("long", @LONG
�����Ǻ�̲����ʱ�о��˳��ϰ�����������һ����ͷ�����紵����
�������ҡ�
LONG);
	set("exits", ([
		"southwest":__DIR__"xiaojing1",
		"north":__DIR__"gangkou",
		"east":__DIR__"haitan2",
		"west":__DIR__"haitan3",
		
	]));
      set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

