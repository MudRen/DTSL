//job.
// �������ϵͳ��
#include <job_money.h>
#include <ansi.h>
inherit NPC;
#include "/d/job/banghuijob/map.h"
string give_job();
void create()
{
   set_name("������",({ "leng wuming","leng","wuming" }) );
        set("gender", "����" );
        set("title","ִ��������");
        set("nickname",HIR"��������"NOR);
        set("age", 32);
   set("long", "���Ǻ�ɳ���ִ����������\n");
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
  if(me->query("shili/name")!="haisha_b")
  return "ֻ�к�ɳ����������������\n";
  if(me->query("combat_exp")<100000)
  return "����书̫��΢�ˣ����������������ɣ�\n";
  if(me->query_temp("bhjob/haisha"))
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
  killer->set("nickname",HIR"��ɳ����ͽ"NOR);
  killer->set_name("��ͽ",({"pan tu","pan","tu"}));
  killer->move(jobdir);
  tell_object(environment(killer),"һ���紵����һ��������ƮȻ���䣡\n");
  me->set_temp("bhjob/haisha",1);
  return "���Ǻ�ɳ�����������ͽ���ݰ��ڵ���˵��"+map[jobdir]+",��ȥ����ɱ�ˣ�\n";
}
