
#include <ansi.h>
inherit ROOM;

int do_siguo();
void create ()
{
  set ("short",HIW"˼����"NOR);
  set ("long", @LONG
�����ǴȺ���ի��˼���á��Ⱥ���ի�ĵ��ӷ��˴��󣬾͵�������
���˼����
LONG);

  set("exits", ([ 

  "north":__DIR__"dawutang",
  "south":__DIR__"pushantang",
   ]));
  /*set("objects",([
	  __DIR__"npc/bing":2,
	  ]));*/

  
  set("valid_startroom", 1);
  setup();
 
}

/*
void init()
{
   add_action("do_siguo","siguo");
}

int do_siguo()
{
   object me;string str;
   me=this_player();
   str="$N��ϥ���£���ʼ���˼����\n";
   message_vision(str,me);
   str=replace_string(str,"$N",me->name());
   str=replace_string(str,"\n","");
   me->set_temp("apply/short",({str}));
   me->set_temp("think_times",60);
   me->start_busy((:call_other,this_object(),"think",me:));
   return 1;
}

int think(object me)
{
    me->add_temp("think_times",-1);
   if(me->query_temp("think_times")<=0)
   {
     message_vision("$N��̾��һ��������վ��������\n",me);
     me->delete_temp("apply/short");
     return 0;
    }
   if(me->query("bellicosity")>0)
     me->add("bellicosity",-1);
    return 1;
}
  
*/ 