
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"����"NOR);
	set("long", @LONG
�����Ƕ�����˵����ҡ����ϱ�������������롣��߷���һ����
ױ̨���Աߵ�ǽ�Ϲ���һ�����������������ţ�������һƬ���֣�һƬ
���̣�������������Ŀ������ܸɾ����������ոմ�ɨ����
LONG);
	set("exits", ([
		"out":__DIR__"qingzhugong",
	]));
  set("objects",([
	  __DIR__"npc/shanmeixian":1,
	  ]));
        
       set("valid_startroom", 1);   
	setup();
       
       
}

     
