
#include <ansi.h>
inherit ROOM;


void create ()
{
    set ("short","ˮ����");
  set ("long", @LONG
������������ˮ�����ˡ�����ķ羰����������������������ν[
�׻�������ңң��������Ӱ��³�]��
LONG);

  set("exits", ([ 
  

  "northdown":__DIR__"baihujie3",
  "southdown":__DIR__"baihujie4",

	  ]));
set("outdoors","luoyang");
  
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
   add_action("do_jump","jump");

}

int do_jump(string arg)
{
   object ob;
   string msg;
   
   ob=this_player();
   
   if(!arg||arg!="down")
   return 0;
   
/*
   if(ob->query("family/family_name")!="������")
   return 0;
   if(ob->query("execute_quest/busiyin"))
   return 0;
*/
   msg="$N�����������ˣ�����һԾ�������µĴ�����ȥ��\n";
   message_vision(msg,ob);
   ob->move(__DIR__"xiaochuan");
   return 1;
}
