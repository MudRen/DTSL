
inherit NPC;
#include <ansi.h>
#include <job_money.h>
string give_job();
int do_ok(string arg);
void create()
{
   set_name("Τ��٢",({ "wei huatuo","wei"}) );
        set("gender", "����" );
        set("age", 35);
   set("long", "����������ҽ��ҽ���������˳�[��٢����]��\n");
   set("combat_exp", 200000);
   set("str", 28);
   set("per", 26);
   set("attitude", "peaceful");
   set_skill("unarmed",150);
   set_skill("parry",150);
   set_skill("dodge",150);
   set_skill("force",150);
   set("max_gin",2000);
   set("max_sen",2000);
   set("max_kee",2000);
   set("force",2000);
   set("max_force",2000);
   set_skill("literate",100);
   set("inquiry",([
	   "��ҩ":(:give_job:),
	   ]));
   set("shili",([
      "name":"lifa_b",
      ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

string give_job()
{
	object me,ob,tool;
	me=this_player();ob=this_object();
	
	if(me->query("vocation")!="ҩʦ")
	return "ֻ��ҩʦ���ܰ��Ҳ�ҩ��\n";
	if(me->query_temp("wei_job"))
		return "���¿ɲ�Ҫ�����������\n";
	if(me->query_temp("wei_ok"))
		return "�㻹�ǰѲ�ҩ���Ұɣ�\n";
	if(time()-me->query("busy_time")<60)
		return "�㻹��ЪЪ�ɣ�\n";
	if(me->query_temp("dtsl_job"))
   return "������������������æ�����İɣ�\n";
   me->set_temp("dtsl_job","����Τ��٢��ҩ����");
	switch(random(3))
	{
	case 0:me->set_temp("wei_job/1",1);break;
	case 1:me->set_temp("wei_job/2",1);break;
	case 2:me->set_temp("wei_job/3",1);break;
	}
	tool=new(__DIR__"obj/chutou");
	tool->move(me);
	return "�ðɣ��鷳"+RANK_D->query_respect(me)+"����ɽ���Ҳɵ�ҩ�ɣ�\n";
}

int accept_object(object me,object ob)
{
	int v_score;
	if(!me->query_temp("wei_ok"))
		return notify_fail("�������ڵĲ�ҩ�𣿲�Ҫ͵������\n");
	if(!ob->query("wei_med"))
		return notify_fail("���Ǵӻ�ɽ�ڵĲ�ҩ�𣿲�Ҫ͵������\n");
	
	v_score=me->query_int()*me->query("max_pot");
	me->delete_temp("wei_ok");
	me->delete_temp("dtsl_job");
	me->set("busy_time",time());
	me->improve_skill("bencao-shuli",v_score);
	tell_object(me,"��ı����������˽�һ������ߣ�\n");
	if(present("chu tou",me))
	  destruct(present("chu tou",me));
	return 1;
}