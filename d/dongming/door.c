
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"������"NOR);
	set("long", @LONG
�����Ǳ��������ſڡ�������ǽ��������ɵĳ��ڡ��������ں���
���кܸߵ����������������ǵĴ�������ļ��������������ܱȡ�
LONG);
	set("exits", ([
	     
		"southup" :__DIR__"shijie1",
		"north":__DIR__"shulin1",
		
	]));
	set("objects",([
		__DIR__"npc/dizi":2,
		]));
    set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
        "/obj/board/party_dm_b.c"->foo();
       
}
int valid_leave(object me,string dir)
{
	object ob;
	if(dir=="southup"&&
		me->query("family/family_name")=="������"
		&&objectp(ob=present("nv dizi",environment(me))))
	{ message_vision("$N����$n�е�����������������\n",ob,me);
	  ob->kill_ob(me);
	  return notify_fail("�㱻��ס�ˣ�\n");
	}
	return ::valid_leave(me,dir);
}

