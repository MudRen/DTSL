// ����˫����

//�ٱ�


inherit NPC;

#include <ansi.h>
#include <job_money.h>

string give_job();
int do_ok(string arg);
int cancel_job();

void create()
{
        set_name(HIY"�ٱ�"NOR, ({ "guan bing", "bing"}) );
        set("gender", "����");
        set("age", 35);
        set("long","���Ǹ������ŵĹٱ����ܹܸ������ΰ���\n");
        set("combat_exp", 300000+random(40000));
        set("attitude", "heroism");
        set("str", 30);
        set("max_kee", 1000);
        set("max_sen", 500);
        set("max_gin", 700);
        set("force", 400);
        set("max_force", 500);
        set("force_factor", 25);
        set_skill("blade", 100);
        set_skill("unarmed", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("force", 100);
        set("target_id","###");
        set("inquiry",([
         "job":(:give_job:),
         "Ѳ��":(:give_job:),
         "����":(:cancel_job:),
         
         ]));
        setup();

        carry_object("/d/gaoli/obj/gangdao")->wield();
        carry_object("/d/gaoli/obj/armor")->wear();
}

void init()
{
  add_action("do_ok","task");
}
string give_job()
{
  object me;
  me=this_player();
  if(me->query("combat_exp")>100000)
  return "��������ô�򵥹�������̫��ϧ�ˣ�\n";
  if(me->query_temp("gaoli_xunluo"))
  return "�ҿɲ�ϲ�����������ˣ�";
  if(time()-me->query_temp("gaoli_xunluo_busy")<40)
  return "����ЪЪ�ٸɻ�ɣ�\n";
  me->set_temp("gaoli_xunluo",1);
  return "�ðɣ��鷳"+RANK_D->query_respect(me)+"ȥ��������ΧѲ��һ�°ɣ�\n";
}

int do_ok(string arg)
{
  object me;string *here;
  me=this_player();
  
  if(!arg||arg!="ok")
  return notify_fail("ʲô��\n");
  if(!me->query_temp("gaoli_xunluo"))
  return notify_fail("ʲô��\n");
  here=me->query_temp("xunluo_dir");
  if(sizeof(here)<16)
  return notify_fail("��©���ط��ˣ�����ϸ�����ɣ�\n");
  
  me->set("busy_time",time());
  me->delete_temp("xunluo_dir");
  me->delete_temp("gaoli_xunluo");
  JOBSYS_D->give_reward_xunluojob(me);
  return 1;
}

int cancel_job()
{
   object ob;
   
   ob=this_player();
   
   if(!ob->query_temp("gaoli_xunluo")){
   command("?");
   return 1;
   }
   
   JOBSYS_D->do_cancel_job("gaolixunluo",ob,this_object());
   
   command("heng");
   return 1;
}