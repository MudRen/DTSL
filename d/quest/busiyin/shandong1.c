
inherit __DIR__"hole";

#include <ansi.h>

void create ()
{
	set ("short",BLU"ɽ��"NOR);
	set ("long", @LONG
������һ��ɽ�������������һƬ��һ�ɳ�ʪ����Ϣ�˱Ƕ�������
���쳣��������������ԼԼ���Ըо���һ��ɱ����������һ��С������
�ƺ������ʲô������
LONG);

	set("exits", ([ 
		"north":__DIR__"shandong2",
		"south":__DIR__"shandong3",
		"west":__DIR__"shandong4",
		"east":__DIR__"shandong5",
		 
        ]));
  	set("no_quit",1);
  	setup();
 
}
