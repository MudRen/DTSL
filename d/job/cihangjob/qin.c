
inherit NPC;

#include <ansi.h>
#include <job_money.h>

string give_job();
int do_ok(string arg);
int cancel_job();

mapping here=([
"�о���":"/d/jingzhai/songjingfang","�ؾ���":"/d/jingzhai/cangjingfang",
"������":"/d/jingzhai/wenzhitang","������":"/d/jingzhai/wuchentang",
"���ķ�":"/d/jingzhai/kuxinfang","��̰��":"/d/jingzhai/wutantang",
"������":"/d/jingzhai/wuyutang",
]);

void create()
{
   set_name("������",({ "qin yunming","qin" }) );
        set("gender", "Ů��" );
        set("age", 22);
   set("long", "���ǴȺ���ի����������\n");
       
   set("combat_exp",300000);
   set("str", 25);
   set("per", 26);
   set("max_gin",3000);
   set("max_kee",3000);
   set("max_sen",3000);
   set("max_force",3000);
   set("force",3000);
   set("attitude", "friendly");
   set_skill("sword",120);
   set_skill("cuff",120);
   set_skill("strike",120);
   set_skill("dodge",120);
   set_skill("finger",120);
   set_skill("literate",120);
   set_skill("force",120);
   set_skill("sekong-jianfa",120);   
   set_skill("xiuluo-zhi",120);
   set_skill("wuwang-jing",120);
   set_skill("qingxin-force",120);
   set_skill("lingyun-shenfa",120);
   
   create_family("�Ⱥ���ի",8,"����");
   set("target_id","###");
   set("inquiry",([
     "job":(:give_job:),
     "����":(:cancel_job:),
     ]));
   setup();
  
}
void init()
{
  add_action("do_ok","task");
}
string give_job()
{
  object ob,book;string *map;int i;
  ob=this_player();
  if(ob->query("family/family_name")!="�Ⱥ���ի")
  return "ʩ�����ǲ�Ҫ������ͣ���ĺã�\n";
  if(ob->query("combat_exp")>150000)
  return "��ó�ȥ�������������������ˣ�\n";
  if(time()-ob->query("busy_time")<40+random(10))
  return "����Ъ��ɣ�\n";
  if(ob->query_temp("cihang-job"))
  return "�Ⱥ���ի�ĵ������´�������ô���ģ�\n";
  map=keys(here);
  i=random(sizeof(map));
  ob->set_temp("cihang-job",here[map[i]]);
  book=new(__DIR__"book");
  book->move(ob);
  ob->add_temp_array("job_temp_killer",book);
  return "�ðɣ���ȥ"+map[i]+"������ɣ�\n";
}
int do_ok(string arg)
{
  object ob,book;string name;
  
  
  ob=this_player();
  if(!arg||!sscanf(arg,"ok with %s",name))
  return notify_fail("��ʹ��task ok with sth ����������\n");
  if(!ob->query_temp("cihang-job-ok"))
  return notify_fail("�Ⱥ���ի�ĵ������´�������ô���ģ�\n");
if(!objectp(book=present(name,ob)))
return notify_fail("������û�����������\n");
  if(!book->query_temp("cihang-job-ok"))
  return notify_fail("������һ��ü����������ܽ����𣿣�\n");
  destruct(book);
  
  ob->delete_temp("cihang-job");
  ob->delete_temp("cihang-job-ok");
  ob->delete_temp("cihang-job-times");
  ob->set("busy_time",time());
  
  JOBSYS_D->give_reward_chchujijob(ob);
  
  return 1;
}

int cancel_job()
{
   object ob;
   
   ob=this_player();
   
   if(!ob->query_temp("cihang-job")){
    command("?");
    return 1;
   }
   
   JOBSYS_D->do_cancel_job("chchujijob",ob,this_object());
   command("sigh");
   return 1;
}