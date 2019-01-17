//job.
// ��������
//100k ��һ��ɱ��
//500k �Ժ�������ɱ�֡�
inherit NPC;
#include <job_money.h>
#include <ansi.h>
#include <map.h>
string give_job();
void create()
{
   set_name("��ܼ�",({ "guan jia","guan","jia" }) );
        set("gender", "����" );
        set("age", 42);
   set("long", "���Ƕ���Ĵ�ܼҡ�\n");
   set("combat_exp", 600000);
   set("str", 30);
   set_temp("apply/armor",30);
   set_temp("apply/damage",30);
   set_temp("apply/dodge",30);
   set("max_gin",2000);
   set("max_sen",2000);
   set("max_kee",2000);
   set("max_force",2000);
   set("force",2000);
   set("inquiry",([
     "����":(:give_job:),
     ]));
   setup();
  
}

string give_job()
{
  object me;
  object ob;
  string *t;
  int i;
  
  me=this_player();
  
  if(me->query("combat_exp")<100000)
  return "��Ĺ���̫���ˣ��������������ġ�\n";
  if(me->query_temp("dm_job_find"))
  return "�㻹�ǸϿ�ȥѰ�ҵ����ɣ������������ߵĺܽ���\n";
  if(time()-me->query("busy_time")<120+random(20))
  return "�㻹����ЪЪ�ɣ�\n";
  if(me->query_temp("dtsl_job")&&
    me->query_temp("dtsl_job")!="������Ѱ������")
  return "���������������񣬻�����æ�������İɣ�\n";
  
  me->set_temp("dm_job_find",1);
  me->set_temp("dtsl_job","������Ѱ������");
  
  i=random(sizeof(map));
  me->set_temp("dm_job_find_where",DM_JOB_PATH+map[i]);
  ob=new(__DIR__"ditu");
  ob->set("dm_job_find_where",DM_JOB_PATH+map[i]);
  ob->move(me);
  return "����е���͵���˶�����˵�һ�����\n"+
         "��˵�˵����Ѿ��ӵ��ˡ�����ɽ��������\n"+
         "���ŵ�ͼȥ������ϸ�Ѳ�(soucha)�ɣ�\n";

}

int accept_object(object who,object ob)
{
  int exp,pot,silver;
  
  if(!who->query_temp("dm_job_find"))
  return 0;
  if(!ob->query("dm_find_job"))
  return 0;
  if(ob->query("owner")!=who)
  return 0;
  
  who->delete_temp("dm_job_find");
  who->delete_temp("dm_job_find_where");
  who->delete_temp("have_killer");
  who->delete_temp("dtsl_job");
  
  who->set("busy_time",time());
  if(who->query("combat_exp")<500000)
  exp=200+random(30);
  else
  exp=220+random(30);
  pot=110+random(10);
  silver=who->query("max_pot");
  
  who->add("combat_exp",exp);
  who->add("potential",pot);
  who->add("deposit",silver);
  if(who->query("potential")>who->query("max_pot"))
	who->set("potential",who->query("max_pot"));
  tell_object(who,query("name")+"Ц��������лл���ˣ�\n"+
              "������ж��У���õ���"+HIW+chinese_number(exp)+NOR+"�㾭�飬\n"+
              "                      "+HIY+chinese_number(pot)+NOR+"��Ǳ�ܣ�\n"+
              "                      "+MONEY_D->money_str(silver)+"\n");
  add_shili(who,exp/3,silver/3);
  tell_object(who,"���Ǯׯ��������ˣ�\n");
  return 1;
}
