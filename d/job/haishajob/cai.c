//job.
// ̩ɽ�ᱦ����
#include <job_money.h>
#include <ansi.h>
inherit NPC;
string give_job();
string clear_job();
void create()
{
   set_name("��ʤ",({ "cai sheng","cai","sheng" }) );
        set("gender", "����" );
        //set("title",
        set("age", 32);
   set("long", "���Ǻ�ɱ��Ĳ�ʤ��\n");
   set("combat_exp", 500000);
   set("str", 30);
   set("inquiry",([
     "����":(:give_job:),
     "����":(:clear_job:),
     ]));
   set("duobao_job",1);
   setup();
  
}

string give_job()
{
  object me,ob;
  me=this_player();
  ob=this_object();
  if(me->query("combat_exp")<800000)
  return "�������Σ�գ��㻹�ǲ�Ҫ���ˣ�\n";
  if(me->query("job/duobao_job"))
  return "�ҿɲ�ϲ�����������ˣ�\n";
  if(time()-me->query("busy_time")<90)
  return "����������ô�౦�ﰡ���㻹��ЪЪ�ɣ�\n";
 if(time()-ob->query("gived_job")<60)
  return "�Ѿ�����ȥ�ˣ���Ȼ�ɣ�\n";
  if(me->query_temp("dtsl_job"))
   return "������������������æ�����İɣ�\n";
   me->set_temp("dtsl_job","�������������");
  me->set("job/duobao_job",1);
 ob->set("gived_job",time());
  return "��˵���̩ɽ��һ���ر�ͼ���֣��Ѿ��кܶ���ȥ���ˡ�\n"+
         "��ȥ�������������ң�һ��ҪС�ģ���˵ȥ�Ķ��Ǹ��ɵ����ָ��֣�\n";
}

string clear_job()
{
  object me,ob;
  me=this_player();
  ob=this_object();
  if(!me->query("job/duobao_job"))
  return "����������ʲô��˼����\n";
  me->delete("job");
  me->delete_temp("dtsl_job");
  ob->delete("gived_job");
  me->set("busy_time",time()+60);
  return "�ߣ�û�뵽������ôû�õ��ˣ�������Ӣ���������ǣ�\n"+
         "�㲻�����ܻ����������ģ�\n";
}

