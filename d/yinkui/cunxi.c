
#include <ansi.h>
inherit ROOM;

int do_zuan(string arg);
void create ()
{
  set ("short","����");
  set ("long", @LONG
������С���ӵ����档������һ���޼ʵĲ�ԭ�����Ｘ��û��ʲô
�ˣ��Ա��м��ô�������֦�Ѿ����㣬������ɢ�����ż�ֻ��ѻ������
������Ƶؽ��š�
LONG);

  set("exits",([
	  "east":__DIR__"cunzhong",
	  ]));
  set("outdoors","yinkui");
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
	add_action("do_zuan","zuan");
}

int do_zuan(string arg)
{
	object me;
	me=this_player();
	if(!arg||(arg!="hole"&&arg!="��"))
		return notify_fail("��Ҫ�������ꣿ\n");
	if(!me->query("yingui_pass_ok")&&me->query("combat_exp")<1000000)
	return notify_fail("���겻��ȥ��\n");
	message_vision("$N���ݴ��е�һ�������ȥ��\n",me);
	me->move(__DIR__"caocong2");
	return 1;
}