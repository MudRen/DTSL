
inherit NPC;
#include <ansi.h>
#include <jobsys.h>
string do_zhaoxiang();
void create()
{
   set_name("ǿ��",({ "qiang dao","qiang","dao"}) );
        set("gender", "����" );
        set("age",30);
		
   set("long", "���Ǹ�ר�����ٹٸ��γ���ǿ����\n");
       
   set("combat_exp", 200000);
   set("str", 10+random(20));
   set("cor", 10+random(20));
   set_skill("force",20);
   set("force",800);
   set("max_force",800);
   set_skill("unarmed",150);
   set_skill("dodge",150);
   set_skill("parry",150);
   set_skill("cuff",100);
   set_skill("strike",100);
   set_skill("tianmo-dai",100);
   set_skill("linglong-yuquan",100);
   set_skill("tianmo-huanzong",100);
   set_skill("tianmo-dafa",100);
   set_skill("force",100);
    set("inquiry",([
       "�н�":(:do_zhaoxiang:),
       ]));
   setup();
   add_money("silver",1);
}

int chat()
{
   object ob;
   
   ob=query_temp("last_damage_from");
   if(!ob) return ::chat();
   if(!ob->query_temp("guanchai_yunyan")||
     query_leader()!=ob)
   return ::chat();
   if(ob->query_temp("guanchai_yunyan_zx"))
   return ::chat();
   if(query("zx_flag"))
   return ::chat();
   if(query("eff_kee")*100/query("max_kee")<JOBSYS_D->get_up_lev())
     if(random(100)<JOBSYS_D->get_random_lev())
       return ::chat();
     else{
      if(!query("no_msg"))
      tell_object(ob,HIC+query("name")+"׼��Ͷ���ˣ�������н�"+query("name")+"����ʹ��\n"+
                     "ask xxx about �н� ���\n"NOR);
      set("no_msg",1);
      ob->set_temp("guanchai_yunyan_zx",this_object());
      set("busy_time",time());
      return ::chat();}
   else return ::chat();
   return ::chat();
}

string do_zhaoxiang()
{
   object ob;
   object thing;
   
   ob=this_player();
   if(!ob->query_temp("guanchai_yunyan_zx"))
   return "��˵ʲô�أ�����һ��Ҳ��������\n";
   if(ob->query_temp("guanchai_yunyan_zx")!=this_object())
   return "��˵ʲô�أ�����һ��Ҳ��������\n";
   set("zx_flag",1);
   ob->remove_all_enemy();
   this_object()->remove_all_enemy();
   if(!query("no_fight"))
   message_vision("\n$N��$n�������һԾ������սȦ��\n",ob,this_object());
   set("no_fight",1);
   ob->delete_temp("guanchai_yunyan");
   ob->delete_temp("dtsl_job");
   ob->delete_temp("guanchai_yunyan_zx");
   ob->delete_temp("track");
   if(time()-query("busy_time")<30)
   return "����������һ�룡\n";
   
    ob->set("busy_time",time());
    thing=new("/d/job/funjob/thing");
    thing->move(ob);
    tell_object(ob,query("name")+"������һ��"+thing->query("name")+"��\n");
    message_vision("$Nһ�������ˣ�\n",this_object());
    destruct(this_object());
   
   return "";
  
}

void init()
{
  call_out("dispear",300);
}

void dispear()
{
  message_vision("$N�Ҵ���ȥ�ˣ�\n",this_object());
  destruct(this_object());
  return;
}

