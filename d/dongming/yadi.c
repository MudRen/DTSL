
inherit ROOM;
#include <ansi.h>
int do_pa();
void create()
{
	set("short", HIB"ɽ�µ�"NOR);
	set("long", @LONG
������ɽ�µĵײ������￴������Щ�������Ӳݴ���������ϸһ����
���������кܶ����ʬ�������Ǵ�����ˤ�������ġ�
LONG);
	set("exits", ([
		"up":__DIR__"shanya2",
	
	]));
 if(sizeof(children(__DIR__"obj/zhanlangdao"))<2)
	set("objects",([
		__DIR__"obj/zhanlangdao":1,
		]));
set("no_clean_up",1);
      set("valid_startroom", 1);   
       set("outdoors", "yadi");  
	setup();
       
       
}

int valid_leave(object me,string dir)
{
	if(dir=="up"&&me->query("sen",1)<300)
		return notify_fail("���ɥ�ط���ƾ���ڵľ��������������˸ߵ����¡�\n");
	me->receive_damage("sen",300);
	return ::valid_leave(me,dir);
}

