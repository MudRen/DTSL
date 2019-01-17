
inherit NPC;
#include <ansi.h>
#include <job_money.h>

string *dirs1=({
"/d/gaoli"
});
string *dirs2=({
"/d/changbaishan"
});
string *dirs3=({
"/d/shanhaiguan"
});

string give_job();
int cancel_job();

void create()
{
   set_name("������ʿ",({ "wu shi","wu","shi"}) );
        set("gender", "����" );
        set("age",42);
        set("long","�����Ľ��ɵĵ��ӣ����ڹ�������Ĳ����ΰ�������\n");
  set("max_kee",1000);
  set("max_gin",1000);
  set("max_sen",1000);
  set("max_force",1000);
  set("force",2000);
  set("combat_exp",300000);
  set_skill("unarmed",120);
  set_skill("strike",120);
  set_skill("leg",120);
  set_skill("literate", 120);
 set_skill("force", 120);
  set_skill("dodge", 130);
  set_skill("parry", 150);
  
  set_skill("jiuxuan-dafa",120);
  set_skill("fengxue-leg",130);
  set_skill("xingyun-dodge",130);

  
  set("target_id","####");//��ֹ������ ansha ������ɱ����
  
  set("inquiry",([
     "job":(:give_job:),
     "����":(:cancel_job:),
     ]));
  setup();
  
  create_family("�Ľ���",5, "����");
   carry_object(__DIR__"guanfu")->wear();
  
}

int cancel_job()
{
  object ob;
  
  ob=this_player();
  
  if(!ob->query_temp("gaoli_kill_job")){
  command("heng "+ob->query("id"));
  return 1;
  }
  
  JOBSYS_D->do_cancel_job("gaolijob",ob,this_object());
  
  return 1;
}

string give_job()
{
  object ob,killer;
  string *dirs;
  
  
  ob=this_player();
  if(ob->query_temp("gaoli_kill_job"))
  return "�㻹�ǸϿ�ȥ�ҵ����ɣ�\n";
   
  if(time()-ob->query("busy_time")<10+random(5))
        return "�㻹��ЪЪ�ɣ�\n";
        
  if(ob->query_temp("dtsl_job"))
   return "������������������æ�����İɣ�\n";
   
   ob->set_temp("dtsl_job","����ɱ��������");
  
   if(ob->query("combat_exp")<400000)
     dirs=dirs1;
   else
   if(ob->query("combat_exp")<800000)
     dirs=dirs1+dirs2;
   else
     dirs=dirs1+dirs2+dirs3;
   
   killer=new(__DIR__"killer");
   if(!killer->set_status(ob))
    return "�찡�������������⣬��ȥ������ʦ��\n";
   
   if(!random_place(killer,dirs))
    return "�����е����أ���������... ...\n";
   
   if(!environment(killer))
    return "�����е����أ���������... ...\n";
    
  ob->set_temp("gaoli_kill_job",1);
  ob->add_temp_array("job_temp_killer",killer);
  return "��˵����е�����"+MISC_D->find_place(environment(killer))+"�����ȥ����ɱ�ˣ�\n";
}
  
int accept_fight(object who)
{
   return 0;
}

void kill_ob(object ob)
{
  ob->remove_killer(this_object());
  command("bi "+ob->query("id"));
  return;
}
