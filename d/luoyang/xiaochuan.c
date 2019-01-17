
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","С��");
  set ("long", @LONG
������һ��С�������沼�õķǳ����������滹��һ���׼䣬�Ž�
���ţ���֪�������������ʲô���������һ�Ŵ����ӣ�����ڷ���һ
Щ�Ʋˡ�
LONG);

  set("exits", ([ 
  
  "up":__DIR__"baihuqiao",
  
         ]));
   
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
   add_action("do_touting","touting");
   add_action("do_steal","search");

}

int do_touting()
{
   object ob;
   string msg;
   
   ob=this_player();
   
   if(ob->query("family/family_name")!="������")
   return 0;
   if(ob->query("execute_quest/busiyin"))
   return 0;
   if(!ob->query_temp("steal_busiyin/action0"))
   return 0;
   if(ob->query_temp("steal_busiyin/action2"))
   return 0;
   if(present("steal_busiyin_obj",ob))
   return 0;
   
   msg="$N͵��������ķ�����ȥ��ֻ��һ��һŮ������˵����̬�ȷǳ�������\n";
   message_vision(msg,ob);
   ob->set_temp("steal_busiyin/action1",1);
   ob->delete_temp("steal_busiyin/action0");
   return 1;
}

int do_steal()
{
   object ob,book;
   string msg;
   
   ob=this_player();
   
   if(ob->query("family/family_name")!="������")
   return 0;
   if(ob->query("execute_quest/busiyin"))
   return 0;
   if(!ob->query_temp("steal_busiyin/action1"))
   return 0;
   
   ob->delete_temp("steal_busiyin/action1");
   ob->set_temp("steal_busiyin/action2",1);
   
   msg="$N������ŷ��˷����ϵ��·�����Ȼ����һ���飡\n";
   message_vision(msg,ob);
   book=new(__DIR__"obj/book");
   book->move(ob);
   call_out("do_hit",5,ob);
   return 1;
}

void do_hit(object ob)
{
  if(!ob) return;
  if(environment(ob)!=this_object())
  return;
  
  message_vision("\nͻȻ������������������$N�ȵ������������Ƥ��͵������\n"+
                 "������ֽ����֣�$Nһ��������������ü�ģ�\n\n",
                 ob);
  ob->unconcious();
  return;
}