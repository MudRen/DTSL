//job.
// �������:-P

inherit NPC;

#include <ansi.h>
#include <job_money.h>

#define TOTAL_TASK 25

int do_list();
int do_ok(string arg);
int do_task();

void create()
{
   set_name("������",({ "feiyun zi","feiyun","zi" }) );
        set("gender", "����" );
        set("age", 42);
        set("nickname",HIW"�ȱ�����"NOR);
   set("long", "������ϲ���Ѽ�����ķ����ӣ�û����֪����������������\n");
   set("combat_exp", 600000);
   set("str", 30);
   set_temp("apply/armor",30000);
   set_temp("apply/damage",30000);
   set_temp("apply/dodge",300000);
   set("max_gin",2000);
   set("max_sen",2000);
   set("max_kee",2000);
   set("max_force",2000);
   set("force",2000);
   set("target_id","###");
   set("save_id","random_job_npc");
   set("inquiry",([
     "yanyan":"��������������ʲô�������ֱ�Ӹ�����e-mail��\n",
     "�����":"��������������ʲô�������ֱ�Ӹ�����e-mail��\n",
     "job":(:do_task:),
     "����":(:do_task:),
     ]));
 setup();
  
}
void init()
{
  add_action("do_list","list");
  add_action("do_ok","lingshang");
 
}

int do_list()
{
    object jobctrl,ob,msg;
    
    ob=this_player();
    
    jobctrl=load_object(__DIR__"jobctrl.c");
    
    msg=jobctrl->do_list();
    
    ob->start_more(msg);
    
    return 1;
}
int do_task()
{
  object ob,tool,jobctrl;
  
  ob=this_player();
  jobctrl=load_object(__DIR__"jobctrl.c");
  
  jobctrl->start_job();
  
  if(ob->query_temp("random_job")){
  command("push "+ob->query("id"));
  return 1;
  }
 
 if(this_object()->query("tasks")>=TOTAL_TASK){
      tell_object(ob,"Ŀǰ�����Ѿ�Ѱ����ϣ��ȵȰɣ�\n");
      return 1;
      }
   
  if(ob->query_temp("dtsl_job")){
  command("kok "+ob->query("id"));
  tell_object(ob,"���������������أ���æ�����İɣ�\n");
  return 1;
  }
 // if(!valid_do_job(ob,"randomjob"))
 // return notify_fail("����书�ܸ��ˣ���������С�����Ǵ��С���ˣ�\n");
  ob->set_temp("dtsl_job","�������");
  tool=new(__DIR__"tool");
  tool->move(ob);
 tool->set("owner",ob);
  tell_object(ob,"������͵͵������:��������ѳ�ͷ��ȥ������Ҫ�ı����ڻ������;Ϳ����ˣ�\n");
  ob->set_temp("random_job",1);
  return 1;
}


string *dirs1=({
"/d/xiangyang","/d/jiujiang",
"/d/chengdu",
});

string *dirs2=({
"/d/taishan","/d/huashan",
"/d/hengshan","/d/wuyishan"
});

string *dirs3=({
"/d/changan","/d/taiyuan","/d/suiye"
});

string *dirs4=({
"/d/dongming","/d/baling","/d/dingxiang",
"/d/saiwai"
});

int do_ok(string arg)
{
  object ob,thing,killer;
  string *dirs;
  
  
  ob=this_player();
  
  if(!arg)
  return notify_fail("������һ���ۣ�����ʲô�����Ͱ���\n");
  if(!objectp(thing=present(arg,ob)))
  return notify_fail("��������Ц��:�����û���������������ƭ����\n");
  if(!thing->query("baowu"))
  return notify_fail("���������һ��������һ�ţ���������Ҳ��ƭ�ң���\n");
  
  if(thing->query("owner")!=ob)
  return notify_fail("�������ڵ��ı����𣿣�\n");
  
  if(ob->query("combat_exp")>=1000000&&
     !ob->query_temp("killed_fyz_killer")){
  
  if(ob->query("combat_exp")<400000)
   dirs=dirs1;
  else
  if(ob->query("combat_exp")<600000)
   dirs=dirs1+dirs2;
  else
  if(ob->query("combat_exp")<800000)
   dirs=dirs1+dirs2+dirs3;
  else
  dirs=dirs1+dirs2+dirs3+dirs4;
  
  killer=new(__DIR__"killer");
  killer->set_status(ob);
  
  
  if(!random_place(killer,dirs))
   return notify_fail("�����������Լ��ɱ�����֣����ɵ�ͣ���֣�\n");
  
  if(!environment(killer))
   return notify_fail("�����������Լ��ɱ�����֣����ɵ�ͣ���֣�\n");
  
  message_vision("\nֻ��һ����Ӱ��$N�������������"+thing->query("name")+
  "ת�����ˣ���\n\n",ob);
  thing->move(killer);
  
  tell_object(ob,"��һ�������������������������������ܣ���\n");
  ob->move(environment(killer));
  tell_room(environment(),ob->name()+"����һ�Σ�������׷ȥ����\n");
  message_vision(HIW"$N"+HIW+"�첽����$n"+HIW+"��ǰ�������������ﻹ���ң���\n"NOR,ob,killer);
  killer->kill_ob(ob);
  ob->add_temp_array("job_temp_killer",killer);
  return 1;
  }
  
  message_vision("�����ӿ���$N���е�"+thing->name()+",˫�۷�ֱ���ԣ����������Ҫ�ı��\n",ob);
  destruct(thing);
  if(present("chu tou",ob))
  destruct(present("chu tou",ob));
  
  ob->set("busy_time",time());
  ob->delete_temp("random_job");
  ob->delete_temp("dtsl_job");
  ob->delete_temp("killed_fyz_killer");
  
  JOBSYS_D->give_reward_feiyunzi(ob);
  
  return 1;
}

int accept_fight(object who)
{
   return notify_fail("����������ˣ�\n");
}

void kill_ob(object ob)
{
   tell_object(ob,"����������ˣ�\n");
   ob->remove_killer(this_object());
   return;
}
