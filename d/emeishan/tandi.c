
#include <ansi.h>
inherit ROOM;

int do_jump(string arg);
void create ()
{
  set ("short","ˮ̶��");
  set ("long", @LONG
������ˮ̶�ĵײ����������۾��Ĵ��ؿ�ȥ�����������кܶ����
�㣬�����м�������ݣ��������ǳ�Σ�ա����ֵط����Ǿ����뿪�ĺá�
LONG);
 if(sizeof(children(__DIR__"obj/bawangdao"))<2)
  set("objects",([
	  __DIR__"obj/bawangdao":1,
	  "/d/clone/npc/beast/shirenyu":1,
	  ]));

set("no_clean_up",1);
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
	add_action("do_jump",({"jump","tiao"}));
}

int do_jump(string arg)
{
	object me;
	me=this_player();
	if(!arg||(arg!="��"&&arg!="up"))
		return notify_fail("��Ҫ����������\n");
	message_vision("$Nˢ��һ����ˮ��һԾ������\n",me);
	me->move(__DIR__"shuitan");
	return 1;
}
