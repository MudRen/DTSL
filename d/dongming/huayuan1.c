
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"��԰"NOR);
	set("long", @LONG
����������԰������ܶ��滨��ݣ�Ʒ�ַ��࣬����������ʤ�ա�
�ϱ���һƬ���֡�������һ��С����
LONG);
	set("exits", ([
		"south":__DIR__"shulin1",
		"north":__DIR__"xiaojing2",
		
	]));
   set("objects",([
	   __DIR__"npc/shanxiu":1,
	   ]));
        
       set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

