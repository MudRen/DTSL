
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"ľ��"NOR);
	set("long", @LONG
�����Ǽ�ľ�ݡ�����ɽ����ס�޵ĵط������ϵı��������������
��ǽ�Ϲ��ż��ѳ���������������ע���ų�������ˡ�
LONG);
	set("exits", ([
		"east":__DIR__"shilu1",
		
	]));
   set("objects",([
	   __DIR__"npc/dizi":2,
	   ]));
        
       set("valid_startroom", 1);   
	setup();
       
       
}

