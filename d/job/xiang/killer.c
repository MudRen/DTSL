
inherit JOBNPC;

#include <job_money.h>

void create()
{
   set_name("�˷���",({ "ren fanzi","ren" }) );
   set("gender", "����" );
   
    
   set("long", "����һ���˷��ӡ�\n");       
   
   set("dex",20+random(10));
   set("str",20+random(10));
  
   set_temp("apply/dodge",50+random(50));
   set_temp("apply/armor",50+random(50));
  
   setup();
  
}



//�����ά��  ��
int clear()
{
  if(time()-query("last")<4000)
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
   
   if(clear())
   return 1;
   
   return ::chat();
}

int set_status(object ob)
{
  object guard;
  
  guard=this_object();
  
  guard->set("last",time());
  guard->set("target_id",ob->query("id"));
  
  guard->set("combat_exp",ob->query("combat_exp")+200000);
  if(ob->query("combat_exp")<150000)
    set_this_skills("low");
   else
   if(ob->query("combat_exp")<800000)
    set_this_skills("middle");
   else
    set_this_skills("high");
  set_all_skill(guard,ob->query("max_pot")-100);
  copy_hp_item(ob,guard,"gin");
  copy_hp_item(ob,guard,"kee");
  copy_hp_item(ob,guard,"sen");
  
  guard->set("max_force",ob->query("max_force"));
  guard->set("force",ob->query("max_force"));
  
  return 1;
}

void die()
{
   object ob;
   
   ob=query_temp("last_damage_from");
   if(!ob)
   return ::die();
   
   ob->set_temp("kill_lianrou_killer",1);
   
   return ::die();
}