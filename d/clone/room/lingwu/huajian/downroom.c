
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short",HIB"������"NOR);
  set ("long", @LONG
������һ�������ң����ܺ�����ģ����������������Եĳ�
�ڡ�
LONG);
 set("no_fight",1);
 set("valid_startroom", 1);
  setup();
 
}
void init()
{
	object ob;
	ob=previous_object();
	if(userp(ob))
	call_out("add_exit",300,ob);
	return;
   
}
void add_exit(object ob)
{
  tell_object(ob,YEL"��ͻȻ�������������һ�����ڣ�\n"NOR);
  tell_object(ob,"������һԾ������������\n");
  ob->move(__DIR__"mishi");
  return;
}
