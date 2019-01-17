
inherit NPC;
#include <ansi.h>
#include <job_money.h>

string *dirs=({
"/d/huashan"
});

string give_job();
int do_ok(string arg);
int cancel_job();

void create()
{
   set_name("����",({ "mu ren","mu","ren"}) );
        set("gender", "����" );
		
        set("age",30+random(10));
   set("long", "����һλͻ�ʵķ����ˡ�\n");
       
   set("combat_exp", 500000);
   set("str",30);
   
   set_skill("parry",120);
   set_skill("dodge",120);
   set_skill("force",120);
   set("force",1000);
   set("max_force",1000);
   
   set("target_id","####");
 
   set("inquiry",([
      "job":(:give_job:),
      "����":(:cancel_job:),
      ]));
   setup();
  
}

int accept_fight(object who)
{
  return 0;
}

void init()
{
   add_action("do_ok","task");
}

string give_job()
{
  object ob,sheep,room;
  string where;
  int i;
  
  ob=this_player();
  
   if(ob->query("family/family_name")!="ͻ��")
   return "ֻ��ͻ�ʵĵ��Ӳſ������������\n";
   
   if(ob->query("combat_exp")>=100000)
   return "ƾ����������������������ǿ�ϧ�ˣ�\n";
   
   if(ob->query_temp("tujue_fangmu"))
   return "�����¿�Ҫ��ͷ��β����Ҫ���������\n";
   
   if(time()-ob->query("busy_time")<40+random(20))
   return "���������ºαؼ���һʱ�أ�������Ъ��ɣ�\n";
   
   if(ob->query_temp("dtsl_job"))
   return "������������������æ�����İɣ�\n";
   
   ob->set_temp("dtsl_job","ͻ�ʷ�������");
   ob->set_temp("tujue_fangmu",1);
   
   where=get_random_place(dirs);
   
   sheep=new(__DIR__"sheep");
   sheep->set("owner",ob);
   sheep->set("place",where);
   sheep->set("long","����һֻ��"+ob->name()+"�������������\n");
   sheep->move(environment(ob));
   sheep->set_leader(ob);
   ob->add_temp_array("job_temp_killer",sheep);
   room=load_object(where);
 
    return "�ðɣ��鷳��ȥ"+MISC_D->find_place(room)+"��"+sheep->query("name")+
    "��(wei sheep)��\n";
}

int do_ok(string arg)
{
   object ob,target;
   string paper_name;
   
   
   ob=this_player();
   
   if(!arg||sscanf(arg,"ok with %s",paper_name)!=1)
   return notify_fail("���ʹ�� task ok with xx �����\n");
   if(!ob->query_temp("tujue_fangmu"))
  return notify_fail("��û����"+query("name")+"Ҫ�������\n");
   if(!objectp(target=present(paper_name,environment(ob))))
   return notify_fail("����û�����������\n");
   if(target->query("owner")!=ob)
  return notify_fail("�ⲻ�������\n");
   if(!target->query("job_ok"))
   return notify_fail("��û�Ա��أ�\n");
   
  tell_object(ob,query("name")+"�������ͷ���ã��ɵò���\n");
  
   destruct(target);
      
   ob->delete_temp("tujue_fangmu");
   ob->delete_temp("dtsl_job");
   ob->set("busy_time",time());
   
   JOBSYS_D->give_reward_tjchujijob(ob);
   
   return 1;
}

int cancel_job()
{
  object ob;
  
  ob=this_player();
  
  if(!ob->query_temp("tujue_fangmu")){
    command("?");
    return 1;
  }
  
  JOBSYS_D->do_cancel_job("tjchujijob",ob,this_object());
  command("sigh");
  return 1;
}