
inherit NPC;
#include <ansi.h>
#include <job_money.h>
string do_zhaoxiang();
void create()
{
   set_name("�ɷ����",({ "ke feng","ke","feng" }) );
        set("gender", "����" );
        set("age", 32);
   set("long", "������[�Ͼ���]�ĵ��˿ɷ����,��Ҳ������������¡�\n");

   set("combat_exp", 400000);
   set("str", 26);
  //  set_skill("fuchen-skill",100);
  //  set_skill("tianmo-huanzong",100);
   set_skill("parry",100);
   set_skill("force",100);
   set_skill("whip",100);
   set_skill("dodge",100);
   set("inquiry",([
       "�н�":(:do_zhaoxiang:),
       ]));
   setup();
   carry_object(__DIR__"daopao")->wear();
   carry_object(__DIR__"fuchen")->wield();

}

int kill_object(object killer,object victim)
{
  if(query("target_id")==victim->query("target_id")){
   message_vision(HIR"$N������Ц����ƾ��Ҳ�뼩ɱ����ү��\n"NOR,killer);
   destruct(killer);
   return 1;}
  return 1;
}

void init()
{
  set("last",time());
}

int clear()
{
  if(time()-query("last")<300)
  return 0;
  if(!query("no_msg")){
  message_vision("$N�Ҵҵ����ˡ�\n",this_object());
  set("no_msg",1);
  call_out("dispear",1);}
  return 1;
}

void dispear()
{
   destruct(this_object());
   return;
}

int chat()
{
   object ob;

   if(clear())
   return 1;
   ob=query_temp("last_damage_from");
   if(!ob) return ::chat();
   if(!ob->query_temp("yang_kill_pantu")||
     query("target_id")!=ob->query("id"))
   return ::chat();
   if(query("zx_flag"))
   return ::chat();
   if(query("eff_kee")*100/query("max_kee")<JOBSYS_D->get_up_lev())
     if(random(100)<JOBSYS_D->get_random_lev())
       return ::chat();
     else{
      if(!query("no_msg"))
      tell_object(ob,HIC"�ɷ����׼��Ͷ���ˣ�������н��ɷ���ˣ���ʹ��\n"+
                     "ask xxx about �н� ���\n"NOR);
      set("no_msg",1);
      ob->set_temp("yang_kill_pantu_zx",this_object());
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
   if(!ob->query_temp("yang_kill_pantu_zx"))
   return "��˵ʲô�أ�ƶ��һ��Ҳ��������\n";
   if(ob->query_temp("yang_kill_pantu_zx")!=this_object())
   return "��˵ʲô�أ�ƶ��һ��Ҳ��������\n";
   set("zx_flag",1);
   ob->remove_all_enemy();
   this_object()->remove_all_enemy();
   if(!query("no_fight"))
   message_vision("\n$N��$n�������һԾ������սȦ��\n",ob,this_object());
   set("no_fight",1);
   if(time()-query("busy_time")<30)
   return "����������һ�룡\n";

   ob->delete_temp("yang_kill_pantu_zx");
   ob->set_temp("zhaoxiang_killer",1);
   if(random(2)==1){
     kill_ob(ob);
     return "ƶ���ı������ˣ�ҪɱҪ������ı��ˣ�\n";}
    thing=new("/d/job/funjob/thing");
    thing->move(ob);
    tell_object(ob,"�ɷ������һ��"+thing->query("name")+"��\n");

   return "���ڱ���ķ��ϣ��ܲ��ܷŹ������أ�";

}
