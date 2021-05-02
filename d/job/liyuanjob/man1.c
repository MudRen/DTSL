
inherit NPC;
#include <ansi.h>
void create()
{
   set_name("���н�������",({ "man" }) );
        set("gender", "����" );
        set("age", 32);
   set("long", "����һλ���������˵����ܺá�\n");

   set("combat_exp", 200000);
   set("str", 28);
   set_skill("finger",70);
   set_skill("strike",70);
   set_skill("cuff",70);
   set_skill("parry",70);
   set_skill("dodge",70);
   set_skill("force",70);
   set_skill("tiangang-sanjue",70);
   set_skill("bencao-shuli",70);
   set_skill("huanmo-shenfa",70);
   set_skill("dujie-zhi",70);
  //  set_skill("sanhua-zhi",70);
   set_skill("xiuluo-zhi",70);
  //  set_skill("pojun-quan",70);
   set_skill("linglong-yuquan",70);
  //  set_skill("xukong-zhang",70);
   set("env/wimpy",30);
   set("max_force",200);
   set("force",200);
   setup();

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
  int i;

  if(clear())
   return 1;
  i=random(10);
  if(i==4)
   command("apply dujie-zhi 3 8");
  else
  if(i==5)
   command("apply sanhua-zhi 3 8");
  else
  if(i==6)
   command("apply xiuluo-zhi 3 8");
  else
  if(i==7)
   command("apply pojun-quan 3 8");
  else
  if(i==8)
   command("apply linglong-yuquan 3 8");
  else
   command("apply xukong-zhang 3 8");
  if(random(100)>80)
  command("perform mie");
  return ::chat();
}

void init()
{
    set("last",time());

}


int surrender(object killer,object victim)
{
   if(victim->query("target_id")==killer->query("id"))
      if(killer->query_temp("liyuan_job/surrender")==2){
   	killer->add_temp("liyuan_job/step",1);
   	killer->delete_temp("liyuan_job/surrender");
   	message_vision("$N��$nһ��˫ȭ������ǿ����������������������\n"+
   	               "�Ϳ��Կ������ʵ��������Ͷ���ȥ�����ˣ�\n\n",
   	               victim,killer);
   	call_out("dispear",1);

        return 1;}
      else{
        killer->add_temp("liyuan_job/surrender",1);
        victim->set("force",20000);
        message_vision("$N�߷�˵��������ЪϢһ�ᣬ����������һ�Σ���\n",victim);
        return 1;}
   else return 1;
}


int accept_fight(object ob)
{
  if(query("target_id")!=ob->query("id"))
  return notify_fail("�Է�������������ս������\n");

 // if(!ob->query_temp("liyuan_job/surrender"))
 //  return ::accept_fight(ob);
  if(this_object()->is_busy())
  return notify_fail("�Է���æ���أ�\n");
  if(query("eff_kee")*100/query("max_kee")<60)
  return notify_fail("�Է��������أ���������ս����\n");
  set("kee",query("max_kee"));
  set("eff_kee",query("max_kee"));
  set("gin",query("max_gin"));
  set("eff_gin",query("max_gin"));
  set("sen",query("max_sen"));
  set("eff_sen",query("max_sen"));
  set("force",query("max_force"));
  if(!ob->query_temp("liyuan_job/surrender"))
   message_vision("$N˵�����ðɣ���Ȼ"+RANK_D->query_respect(ob)+"��ָ�̣����¾ͷ����ˣ�\n",
                  this_object(),ob);
  else{
  message_vision("$N����һ������˫Ŀ����һ������ʱ��ľ������棡\n",this_object());
  message_vision("$N�����ðɣ�����������һ�Σ���\n",this_object());}
  return 1;
}
