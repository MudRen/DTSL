//job.
// �������ϵͳ��
#include <job_money.h>
#include <ansi.h>
inherit NPC;
#include "/d/job/banghuijob/map.h"
string give_job();
void create()
{
   set_name("����",({ "song yu","song","yu" }) );
        set("gender", "����" );
       set("age", 32);
   set("long", "�����μұ������ꡣ\n");
   set("combat_exp", 500000);
   set("str", 30);
   set("inquiry",([
     "job":(:give_job:),
     ]));
   setup();
   
}

string give_job()
{
  object me,ob,thing;string *dir,jobdir;int i;
  me=this_player();
  ob=this_object();
  if(me->query("shili/name")!="songjia_b")
  return "ֻ���μұ����������������\n";
  if(me->query("combat_exp")<100000)
  return "����书̫��΢�ˣ����������������ɣ�\n";
  if(me->query_temp("bhjob/songjia"))
  return "�ҿɲ�ϲ������������ˣ�\n";
  if(time()-me->query("busy_time")<90)
  return "�㻹��Ъ��ɣ�\n";
  dir=keys(map);
  i=random(sizeof(dir));
  jobdir=dir[i];
  thing=new(__DIR__"heshibi");
  thing->set("job/p_id",me->query("id"));
  thing->move(jobdir);
  me->set_temp("bhjob/songjia",1);
  return "�����μұ�Ҫ�����±����ҵ�[�����]���ݵ���˵��"+map[jobdir]+",��ȥ���ң�\n";
}
