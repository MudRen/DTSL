
inherit ROOM;
#include <ansi.h>
void create()	
{
	set("short",YEL"¥��"NOR);
	set("long", @LONG
������һ��¥�����������������ķ����ˡ����������
����Զ�����ݵķ羰���ǳ����֡�¥���Ա߻����ż����ʻ���Ʒ
�ַ��ࡣ
LONG);
    set("exits", ([
	        "down":__DIR__"wlq_sap",
 	]));
      set("no_fight",1);
      setup();
      replace_program(ROOM);
	
}
