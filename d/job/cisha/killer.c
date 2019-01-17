
inherit NPC;
#include <job_money.h>
#include <ansi.h>
void create()
{
   set_name("������",({ "ren shaoming","ren","shaoming" }) );
        set("gender", "����" );
        set("age",33);
        set("nickname","����");
   set("long", "����ǾŽ�������������������һ��������צԼ�����\n"+
               "�ƴ������������һ�������ܲ��������ӣ�������\n"+
               "��ü��ͻ����üë����ƲŨī��խ�����۾����������\n"+
               "�����ĺ��Ĳп�ͳ�޵�â��\n");
       
   set("combat_exp",200000);
   set("attitude", "peaceful");
   set_skill("parry",80);
   set_skill("dodge",80);
   set_skill("force",80);
   set_skill("sword",80);
   set_skill("tianmo-huanzong",80);
   set_skill("tianmo-jianfa",80);
   set_skill("tianmo-dafa",80);
   set("str",30);
   set("cor",30);
   set("max_gin",1000);
   set("max_kee",4000);
   set("eff_kee",4000);
   set("max_sen",4000);
   set("max_force",1500);
   set("force",1500);
   set_temp("apply/armor",50+random(50));
   set("chat_chance_combat",60);
   set("chat_msg_combat",({
   	(:"apply_action","tianmo-jianfa",2,10:),
   }));
   set("accept_kill",1);
   setup();
   carry_object(__DIR__"sword")->wield();
}

void init()
{
   set("last_time",time());
}

int clean_up()
{
  if(time()-query("last_time")>600)
  return 1;
  return 0;
}
void die()
{
   object killer;
   object *t;
   int i;
   killer=query_temp("last_damage_from");
   if(!killer) return ::die();
   if(!killer->query_temp("dtsl_job_cisha/step3"))
   return ::die();
   t=killer->query_team();
   if(sizeof(t)>0){
     for(i=0;i<sizeof(t);i++)
     if(t[i]&&environment(t[i])==environment(this_object())&&
      t[i]->query_temp("dtsl_job_cisha/step3")&&
      member_array(t[i]->query("id"),query("target_id"))!=-1){
      	
      	t[i]->set_temp("dtsl_job_cisha/step4",1);
      	if(t[i]->query_temp("dtsl_job_cisha/can_flee")){
      	 message_vision("$N˫��һ�����ߣ����һ�������˴���¥��\n",t[i]);
      	 t[i]->move(__DIR__"chunzailou");}
      	else{
      	 message_vision("$N��������һ����$n��ȥ��ֱ���$n��Ѫ���磡$n�͵س�[����¥]��ȥ��\n",this_object(),t[i]);
      	 t[i]->move(__DIR__"chunzailou");
      	 t[i]->unconcious();}
      	
      	}
    CHANNEL_D->do_channel(this_object(), "rumor",
       "��˵��������"+killer->name()+"�����ھŽ�[����¥]��ɱ��\n");
    return ::die();}
    
   if(query("target_id")==killer->query("id")){
   	killer->set_temp("dtsl_job_cisha/step4",1);
   	CHANNEL_D->do_channel(this_object(), "rumor",
       "��˵��������"+killer->name()+"�ھŽ�[����¥]������ɱ��\n");
       if(killer->query_temp("dtsl_job_cisha/can_flee")){
      	 message_vision("$N˫��һ�����ߣ����һ�������˴���¥��\n",killer);
      	 killer->move(__DIR__"chunzailou");}
      	else{
      	 message_vision("$N��������һ����$n��ȥ��ֱ���$n��Ѫ���磡$n�͵س�[����¥]��ȥ��\n",this_object(),killer);
      	 killer->move(__DIR__"chunzailou");
      	 killer->unconcious();}
      return ::die();}
   return ::die();
}

int accept_kill(object killer,object victim)
{
  object guard1,guard2;
  object *t;
  if(query("have_guard"))
  return 1;
  t=killer->query_team();
  if(sizeof(t)>0){
    if(member_array(killer->query("id"),victim->query("target_id"))==-1)
     return notify_fail("����������һЦ����ƾ��Ҳ��ɱ�ң��ߣ�\n");}
  else{
   if(victim->query("target_id")!=killer->query("id"))
  return notify_fail("����������һЦ����ƾ��Ҳ��ɱ�ң��ߣ�\n");}
  guard1=new(__DIR__"changzhen");
  guard2=new(__DIR__"fanan");
  set_all_skill(guard1,victim->query("max_pot")-140);
  set_all_skill(guard2,victim->query("max_pot")-140);
  guard1->move(environment(killer));
  guard2->move(environment(killer));
  message_vision(HIW"$N��$nͻȻ����������"+query("name")+"��\n",
  guard1,guard2);
  guard1->set("target_id",killer->query("id"));
  guard2->set("target_id",killer->query("id"));
  guard1->kill_ob(killer);
  guard2->kill_ob(killer);
  set("have_guard",1);
  return 1;
}

void kill_ob(object killer)
{
  object guard1,guard2;
  if(query("have_guard"))
  return ::kill_ob(killer);
  
  guard1=new(__DIR__"changzhen");
  guard2=new(__DIR__"fanan");
 copy_hp_item(killer,guard1,"kee");
 copy_hp_item(killer,guard2,"kee");
  set_all_skill(guard1,killer->query("max_pot")-120);
  set_all_skill(guard2,killer->query("max_pot")-120);
  guard1->move(environment(killer));
  guard2->move(environment(killer));
  message_vision(HIW"$N��$nͻȻ����������"+query("name")+"��\n",
  guard1,guard2);
  guard1->set("target_id",killer->query("id"));
  guard2->set("target_id",killer->query("id"));
  guard1->set_temp("apply/armor",50+random(50));
  guard2->set_temp("apply/armor",50+random(50));
  guard1->kill_ob(killer);
  guard2->kill_ob(killer);
  set("have_guard",1);
  return ::kill_ob(killer);
}
