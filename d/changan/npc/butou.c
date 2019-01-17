
inherit NPC;
#include <ansi.h>
#include <job_money.h>
string give_job();
int do_ok(string arg);
void create()
{
   set_name("��ͷ",({ "bu tou","bu","tou" }) );
        set("gender", "����" );
        set("age", 32);
   set("long", "���ǳ����Ĳ�ͷ���������ǵ��ΰ���\n");
       
   set("combat_exp", 200000);
   set("str", 28);
   set("per", 23);
   set("attitude", "peaceful");
   set_skill("unarmed",70);
   set_skill("parry",70);
   set_skill("dodge",70);
   set_skill("force",70);
   set("max_force",200);
   set("force",200);
   set("inquiry",([
	   "����":(:give_job:),
	   ]));
   setup();
   
}

void init()
{
	add_action("do_ok","guian");
}

string give_job()
{
	object me,ob;object *t;int i;string str;
	me=this_player();ob=this_object();
	//return "�Բ�������������޸��С�\n";
	t=me->query_team();
	if(sizeof(t)==0){
		return "����������Լ�����̫Σ���ˣ����Ǻͱ������һ�����ɣ�\n";}
	if(!me->is_team_leader())
		return "�㲻�Ƕ�������죬�����ǵ��������ɣ�\n";
	if(time()-me->query("busy_time")<30+random(10))
		return "���ûʲô���������һ���������ɣ�\n";
	if(sizeof(t)>2) 
	 return "��ô�򵥵�����Ҫ��ô���ˣ�����ɣ�\n";
	for(i=0;i<sizeof(t);i++)
	  if(objectp(t[i]))
		  if(environment(me)!=environment(t[i]))
			  return "��Ķ�Ա��û���룬�ȵȰɣ�\n";
	for(i=0;i<sizeof(t);i++)
	 if(t[i])
	  if(t[i]->query("combat_exp")<200000)
	   return t[i]->name()+"�ľ���̫�ͣ���̫Σ���ˣ�\n";
	for(i=0;i<sizeof(t);i++)
	  if(objectp(t[i]))
		  if(me->query("combat_exp")>=t[i]->query("combat_exp")){
			  if(me->query("combat_exp")-t[i]->query("combat_exp")>20000)
				  return "���ǵľ������̫�����Σ�գ�\n";}
		  else{ if(t[i]->query("combat_exp")-me->query("combat_exp")>20000)
			      return "���ǵľ������̫�����Σ�գ�\n";}
	if(me->query_temp("butou_job"))
		return "���Ǹ���������ȥ��������ô����ȥ��\n";
	switch(random(5))
	{
	case 0:
		for(i=0;i<sizeof(t);i++)
      if(objectp(t[i]))
		  t[i]->set_temp("butou_job/1",1);
	  me->set_temp("butou_job/1",1);
	   str="�ðɣ��鷳����ȥ�����С���аѵ���ɱ������������ɣ�\n";
	   break;
	case 1:
		for(i=0;i<sizeof(t);i++)
      if(objectp(t[i]))
		  t[i]->set_temp("butou_job/2",1);
	  me->set_temp("butou_job/2",1);
	   str="�ðɣ��鷳����ȥ�ɶ�������ĳ��������ѵ���ɱ������������ɣ�\n";
	   break;
	case 2:
		for(i=0;i<sizeof(t);i++)
      if(objectp(t[i]))
		  t[i]->set_temp("butou_job/3",1);
	  me->set_temp("butou_job/3",1);
	   str="�ðɣ��鷳����ȥ���Ϸ��ĸۿڰѵ���ɱ������������ɣ�\n";
	   break;
	case 3:
		for(i=0;i<sizeof(t);i++)
      if(objectp(t[i]))
		  t[i]->set_temp("butou_job/4",1);
	  me->set_temp("butou_job/4",1);
	   str="�ðɣ��鷳����ȥ���ݵ���ͤ�ѵ���ɱ������������ɣ�\n";
	   break;
	case 4:
		for(i=0;i<sizeof(t);i++)
      if(objectp(t[i]))
		  t[i]->set_temp("butou_job/5",1);
	  me->set_temp("butou_job/5",1);
	   str="�ðɣ��鷳����ȥ����������ĳ��������ѵ���ɱ������������ɣ�\n";
	   break;
	}
	return str;
}

int do_ok(string arg)
{
	object me,ob,*t;int i;object money;
	int exp,pot,sil,famous;
	me=this_player();
	if(!arg||!objectp(ob=present(arg,environment(me))))
		return notify_fail("��Ҫ��˭�鰸��\n");
	if(!me->query_temp("butou_job"))
		return notify_fail(""+RANK_D->query_respect(me)+",�⻰�Ӻ�˵��\n");
	if(!me->query_temp("butou_job_ok"))
        return notify_fail(""+RANK_D->query_respect(me)+",���ǵ�����С������ƭ�𣿣�\n");
	t=me->query_team();
	if(sizeof(t)==0)
		return notify_fail("��û����������ӣ��ҾͲ��������������ô��޵�����\n");
    for(i=0;i<sizeof(t);i++)
	  if(objectp(t[i]))
		  if(environment(me)!=environment(t[i]))
			  return notify_fail("��Ķ�Ա��û���룬�ȵȰɣ�\n");
	for(i=0;i<sizeof(t);i++)
	  if(objectp(t[i]))
		  if(!t[i]->query_temp("butou_job"))
			  return notify_fail("���ǵĶ����л���������ˣ����������ߣ�����ν������ǣ�\n");
    for(i=0;i<sizeof(t);i++)
		if(objectp(t[i])){
		  exp=260+random(40);
          pot=t[i]->query("max_pot")/3;
             sil=BUTOU_JOB+t[i]->query("max_pot")-100;
	      t[i]->add("deposit",sil);
		  t[i]->add("combat_exp",exp);
		  t[i]->add("potential",pot);
		  add_shili(t[i],exp/2,sil/2);
		  t[i]->delete_temp("butou_job");
		  t[i]->delete_temp("butou_job_ok");
		  t[i]->delete_temp("butou_job_flag");
		  t[i]->set("busy_time",time());
		  tell_object(t[i],"��ͷЦ�����ðɣ������鷳"+RANK_D->query_respect(t[i])+"�ˣ�\n");
		  tell_object(t[i],"������ж��У�������"+""HIW""+chinese_number(exp)+""NOR""+"��ʵս���顣\n");
          tell_object(t[i],"                      "+""HIW""+chinese_number(pot)+""NOR""+"��Ǳ�ܡ�\n");
		  tell_object(t[i],"��ͷ������"+MONEY_D->money_str(sil)+"��Ϊ������\n");
		  tell_object(t[i],"��Ǯׯ�Ĵ�������ˣ�\n");}
	return 1;
}
