
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short","����");
  set ("long", @LONG
������һ������С�������ߣ����������߾���С����ڲ��ˡ���
˵���С����ǽ��Ϻ�ɳ���פ�ء����վ�ż����󺺣���ò�׶񣬴�
�������������ˡ�
LONG);

  set("exits", ([ 

  "west":"/d/dongming/chaguan",
  "east":__DIR__"xiaolu1",
       ]));
  set("objects",([
	  __DIR__"npc/dahan":2,
	  ]));
set("outdoors","haisha");
  
  set("valid_startroom", 1);
  setup();
"/obj/board/haisha_b.c"->foo();
 
}

void init()
{
  object ob;
  
  ob=previous_object();
  if(!ob||!living(ob)) return;
  
  if(!ob->query_temp("bai_dongming/action2"))
  return;
  
  call_out("show_msg",5,ob);
}

void show_msg(object ob)
{
  if(!ob||
  environment(ob)!=this_object())
  return;
  
  ob->delete_temp("bai_dongming/action2");
  ob->set_temp("bai_dongming/action3",1);
  tell_object(ob,"\n\n����Լ�������������ź�ɳ��Ҫ͵Ϯ�����ɵĴ��ӣ�\n\n");
  return;
}