
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
	
		"east":__DIR__"shandong1",
		
        ]));
  	set("no_quit",1);
  	setup();
 
}
