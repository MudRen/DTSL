
inherit ROOM;
#include <ansi.h>
int do_tiao();
void create()
{
	set("short", GRN"ɽ��"NOR);
	set("long", @LONG
������ɽ�¡������￴ȥ��Զ������һɫ��ãã�ޱߡ���ɽ���¿�
ȥ������ף�������Щ�ֽŷ����ˡ�
LONG);
	set("exits", ([
		"northeast":__DIR__"haitan3",
	        "southdown":"/d/job/dmjob/dmjob_0_13",
	]));
      set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

void init()
{
	add_action("do_tiao","tiao");
}

int do_tiao()
{
	object ob;
	ob=this_player();
	message_vision("$N������������������ȥ��\n",ob);
	ob->receive_damage("sen",200);
	ob->move(__DIR__"yadi");
	return 1;
}
