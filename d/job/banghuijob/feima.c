//job.
// �������ϵͳ��
#include <job_money.h>
#include <ansi.h>
inherit NPC;
#include "/d/job/banghuijob/map.h"
string give_job();
void create()
{
   set_name("����",({ "shang leng","shang","leng" }) );
        set("gender", "����" );
        set("title","��������ִ��������");
        set("nickname",HIR"�����ͽ"NOR);
        set("age", 32);
   set("long", "���Ƿ�������ִ����������ר�Ŵ�����ͽ��\n");
   set("combat_exp", 500000);
   set("str", 30);
   set("inquiry",([
     "job":(:give_job:),
     ]));
   setup();
   
}

string give_job()
{
  object me,ob,killer;string *dir,jobdir;int i;
  me=this_player();
  ob=this_object();
  if(me->query("shili/name")!="feima_b")
  return "ֻ�з����������������������\n";
  if(me->query("combat_exp")<100000)
  return "����书̫��΢�ˣ����������������ɣ�\n";
  if(me->query_temp("bhjob/feima"))
  return "�ҿɲ�ϲ������������ˣ�\n";
  if(time()-me->query("busy_time")<90)
  return "�㻹��Ъ��ɣ�\n";
  dir=keys(map);
  i=random(sizeof(dir));
  jobdir=dir[i];
  killer=new(__DIR__"pantu");
  copy_object(killer,me);
  killer->set("job/p_id",me->query("id"));
  killer->delete("family");
  killer->delete("nickname");
  killer->delete("title");
  killer->set("nickname",HIR"����������ͽ"NOR);
  killer->set_name("������",({"pan tu","pan","tu"}));
  killer->move(jobdir);
  tell_object(environment(killer),"һ���紵����һ��������ƮȻ���䣡\n");
  me->set_temp("bhjob/feima",1);
  return "���Ƿ����������������ͽ���ݵ���˵��"+map[jobdir]+",��ȥ����ɱ�ˣ�\n";
}
