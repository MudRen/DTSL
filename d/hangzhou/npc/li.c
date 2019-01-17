#include <ansi.h>
#include <job_money.h>
inherit NPC;
string give_job();
int do_ok(string arg);
void create()
{
   set_name("�����",({ "li caizhu","li","caizhu" }) );
        set("gender", "����" );
        set("age", 52);
   set("long", "���Ǻ��ݵĴ������������������ΪŮ���ٰ�������ס�\n");
       
   set("combat_exp", 50000);
   set("str", 10);
   set("per", 22);
   set("attitude", "friendly");
   set("inquiry",([
	   "��������":(:give_job:),
	   ]));
   set("chat_chance",80);
   set("chat_msg",({
	   (:random_move:),
   }));
   setup();
   carry_object(__DIR__"obj/chouyi")->wear();
  
}

void init()
{
	add_action("do_ok","task");
}

string give_job()
{
	object me,ob,letter;
	me=this_player();ob=this_object();
	if(me->query_temp("li_job"))
		return "�㻹����������ͷ���°ɣ�\n";
	if(ob->query_temp("defence_girl"))
		return "лл��λ"+RANK_D->query_respect(me)+"�ˣ�Ӧ�����˰�æ������Ů���ˣ�\n";
	if(time()-me->query("busy_time")<=150+random(10))
		return "�㻹����ЪЪ�ɣ�\n";
	if(me->query_temp("dtsl_job"))
   return "������������������æ�����İɣ�\n";
   me->set_temp("dtsl_job","�������������");
	me->set_temp("li_job",1);
	me->set("busy_time",time());
	switch(random(3))
	{  case 0:
	me->set_temp("defence_girl",1);
	ob->set_temp("defence_girl",1);
	call_out("cancel_job",180,me,ob);
	return "ʲô�������װ��������������������ҵ�Ů������Ҫ���������ˣ�\n�鷳"+RANK_D->query_respect(me)+"�����ҵ�Ů���ɣ�\n";
	break;
	   case 1:
		me->set_temp("li_songxin_job/1",1);
		me->start_busy(2);
		letter=new(__DIR__"obj/letter");
		letter->move(me);
		return "�ðɣ��鷳"+RANK_D->query_respect(me)+"���������͵�����Ǯׯ�����ϰ�����ɣ�\n";
		break;
	   case 2:
		me->set_temp("li_songxin_job/2",1);
		me->start_busy(2);
		letter=new(__DIR__"obj/letter");
		letter->move(me);
		return "�ðɣ��鷳"+RANK_D->query_respect(me)+"���������͵��ɶ�[���϶ķ�]���ƹ����������ɣ�\n";
		break;
	}
}

void cancel_job(object me,object ob)
{
	if(!objectp(me)||!objectp(ob))
	{ remove_call_out("cancel_job");return;}
	if(me->query_temp("defence_girl"))
		if(!me->query_temp("defence_ok"))
		{ tell_object(me,"��������㺰����������ôû�ã���Ů�����û�ˣ��Ҳ������ˣ�\n");
		  me->delete_temp("defence_girl");
		  me->delete_temp("defence_flag");
		  ob->delete_temp("defence_girl");
          remove_call_out("cancel_job");return;
		}
	remove_call_out("cancel_job");return;
}

int do_ok(string arg)
{
	object me,ob,money;
	int exp,i,sil,pot,famous,score;
	me=this_player();i=0;
	ob=this_object();
	if(!me->query_temp("defence_girl"))
		return notify_fail("ʲô��\n");
	if(!arg||arg!="ok")
		return notify_fail("�������������task ok.\n");
	if(!me->query_temp("defence_ok"))
		return notify_fail("�㲻ɱ���ٱ�����ô����Ů������\n");
	exp=me->query("max_pot")+random(5);
	sil=LI_DEFENCE_JOB+me->query("max_pot")/5;
	pot=me->query("max_pot")/3;
	if(me->query("vocation")=="ɱ��")
	{  me->add("vocation_score",exp/3);
	   me->add("vocation_exp",exp/4);
	}
	me->add("combat_exp",exp);
	me->add("potential",pot);
	me->add("deposit",sil);
	add_shili(me,exp/2,LI_DEFENCE_JOB/2);
	me->delete_temp("defence_girl");
	me->delete_temp("defence_flag");
	me->delete_temp("defence_ok");
	me->delete_temp("li_job");
	me->delete_temp("dtsl_job");
    ob->delete_temp("defence_girl");
	tell_object(me,"������ж��У���������"+""HIW""+chinese_number(exp)+""NOR""+"��ս�����飬"
                                          +""HIW""+chinese_number(pot)+""NOR""+"��Ǳ��.\n");
	if(me->query("vocation")=="ɱ��")
	tell_object(me,"��������ɱ�֣����ְҵ������ְҵ���鶼����ˣ�\n");
	tell_object(me,"�������������"+MONEY_D->money_str(sil)+"\n");
	tell_object(me,"��Ǯׯ�Ĵ�������ˣ�\n");
	return 1;
}
