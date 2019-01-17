
inherit NPC;

#include <ansi.h>

string do_quest1();
int do_quest2();

void create()
{
   set_name("ϼ����",({ "xia zhanglao","xia","zhanglao" }) );
        set("gender", "Ů��" );
		
        set("age", 38);
   set("long", "�����������ɵĳ���֮һ��\n");
   set("per",20);
   set("combat_exp",600000);
  
   set_skill("dodge",180);
   set_skill("parry",180);
   set_skill("force",180);
   set_skill("strike",180);
   set_skill("cuff",180);
   set_skill("sword",180);
   
   set_skill("jiutian-huanzhang",180);
   set_skill("literate",180);
   set_skill("tianmo-dafa",180);
   set_skill("tianmo-huanzong",180);
   set_skill("linglong-yuquan",180);
  
   set("max_gin",1500);
   set("max_kee",1500);
   set("max_sen",1500);
   set("force",2000);
   set("max_force",2000);
   create_family("������",5,"����");
   set("inquiry",([
   "��ħ��":(:do_quest1:),
   "����":(:do_quest2:),
   ]));
   setup();
   
}

string do_quest1()
{
  object ob;
  
  ob=this_player();
  
  if(ob->query("dtsl_quest_yinguifinal"))
  return "ƾ��Ĺ���ѧϰ��ħ��̫��ϧ�ˣ�\n";
  
  if(ob->query_temp("tmz_quest/pass_xia"))
  return "��Ĺ������Ѿ�������ˣ���ȥ���������ϰɣ�\n";
  
  ob->set_temp("tmz_quest/xia_step1",1);
  
  return "��ѧ��ħ���ȴ������˵�ɣ�\n";
}

int surrender(object killer,object victim)
{
   if(!killer->query_temp("tmz_quest/xia_step1"))
   return 1;
   killer->delete_temp("tmz_quest/xia_step1");
   killer->set_temp("tmz_quest/xia_step2",1);
   
   message_vision(CYN"\n$N"+CYN+"��ɫһ�䣬��$n"+CYN+"����"+RANK_D->query_respect(killer)+"��Ȼ���ֲ�����\n"+
   "�����һ���Ҫ������һ�£�\n"NOR,victim,killer);
   return 1;
}

int do_quest2()
{
   object ob;
   
   ob=this_player();
   if(!ob->query_temp("tmz_quest/xia_step2")){
     command("say ��սʤ�Ҿ�����ܿ�����\n");
     return 1;
   }
   
   message_vision("\n$N��$nЦ������ѧ��������Ϊ����֮���������Ҿ͸���ʾ��һ�£�\n"+
   "�����ܲ����������еİ��أ�\n",this_object(),ob);
   tell_object(ob,"\n"+query("name")+"ͻȻ���㷢����������\n");
   add_temp("apply/damage",300);
   
   COMBAT_D->do_attack(this_object(),ob,query_temp("weapon"),0,2);
   add_temp("apply/damage",-300);
   call_out("do_quest3",1,ob);
   return 1;
}

void do_quest3(object ob)
{
  string msg;
  
  if(!ob)
  return;
  if(ob->is_ghost()){
   tell_object(ob,"��û�о���ס"+query("name")+"�Ŀ��飬�´ΰɣ���\n");
   return;
  }
  if(!living(ob))
   return;
  
  msg="\n$N��$n�ٺ�һЦ���ã����������ˣ�\n";
  message_vision(msg,this_object(),ob);
  
  ob->delete_temp("tmz_quest/xia_step2");
  ob->set_temp("tmz_quest/pass_xia",1);
  
  return;
}