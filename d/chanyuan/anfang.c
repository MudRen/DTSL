
#include <ansi.h>
inherit ROOM;

int do_flee();

void create ()
{
  set ("short",HIB"����"NOR);
  set ("long", @LONG
���Ǿ�����Ժ��һ�����������ֲ�����ָ����˵��������ྻ����
Ժ�ı��Ҳ��֪�����Ǽ١���˵�кܶ����ָ��������������������
�����ټ����ޡ�
LONG);

  set("exits", ([ 
	  "out":__DIR__"caodi2",	
         ]));
 
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
   object ob;
   
   add_action("do_flee","flee");
   
   ob=previous_object();
   
   if(!ob) return;
   if(!ob->query_temp("try_bai_buju_actoin1"))
   return;
   if(ob->query_temp("link_killer"))
   return;
   call_out("do_kill",1,ob);
}

void do_kill(object ob)
{
  object killer;
  
  if(!ob)
  return;
  
  killer=new(__DIR__"npc/killer");
  killer->move(environment(ob));
  ob->add_temp_array("job_temp_killer",killer);
  ob->set_temp("link_killer",killer);
  killer->set("target_id",ob->query("id"));
  
  tell_object(ob,HIB"��ͻȻ����һ����Ӱ�������˹�������\n\n"NOR+
                 "����������ܣ�����ʹ�� flee��\n\n");
  killer->kill_ob(ob);
  return;
}

int do_flee()
{
   object ob,killer;
   string msg;
   
   ob=this_player();
   
   if(!ob->is_fighting())
   return notify_fail("��û��ս�����������ܣ�");
   
   killer=ob->query_temp("link_killer");
   if(!objectp(killer))
   return 0;
   if(!ob->is_fighting(killer))
   return 0;
   
   msg="$N�����е���������������\n\n";
   message_vision(msg,ob);
   "/cmds/std/go.c"->do_flee(ob);
   destruct(killer);
   ob->delete_temp("try_bai_buju_actoin1");
   ob->set_temp("try_bai_buju_fail",1);
   ob->set("mud_flags/try_bai_buju_time",time());
   return 1;
}
   