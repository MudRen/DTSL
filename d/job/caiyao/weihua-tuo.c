
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
   set("target_id","####");
   setup();
   
}

int accept_fight(object who)
{
   return 0;
}

string *dirs1=({
"/d/huashan",
});

string *dirs2=({
"/d/wuyishan","/d/hengshan","/d/taishan"
});

string give_job()
{
	object me,where,tool;
	string place,*dirs;
	
	me=this_player();
	
	if(me->query("vocation")!="ҩʦ")
	return "ֻ��ҩʦ���ܰ��Ҳ�ҩ��\n";
	
	if(me->query_temp("wei_job"))
		return "���¿ɲ�Ҫ�����������\n";
		
	if(me->query_temp("wei_ok"))
		return "�㻹�ǰѲ�ҩ���Ұɣ�\n";
		
	if(time()-me->query("busy_time")<40)
		return "�㻹��ЪЪ�ɣ�\n";
		
	if(me->query_temp("dtsl_job"))
   return "������������������æ�����İɣ�\n";
   
   if(me->query_skill("bencao-shuli",1)<100)
    dirs=dirs1;
   else dirs=dirs1+dirs2;
   
   place=get_random_place(dirs);
   if(place=="error")
   return "��������е����⣬�뱨����ʦ��\n";
   
   where=load_object(place);
	
	
	tool=new(__DIR__"obj/chutou");
	tool->set("place",place);
	tool->move(me);
	
   me->set_temp("dtsl_job","����Τ��٢��ҩ����");
   me->set_temp("wei_job",1);
	return "�ðɣ��鷳"+RANK_D->query_respect(me)+"��"+MISC_D->find_place(where)+"���Ҳɵ�ҩ�ɣ�\n";
}

int accept_object(object me,object ob)
{
	
	if(!me->query_temp("wei_ok"))
		return notify_fail("�������ڵĲ�ҩ�𣿲�Ҫ͵������\n");
	if(ob->query("owner")!=me)
	return notify_fail("�������ڵĲ�ҩ�𣿲�Ҫ͵������\n");
	
	
	me->delete_temp("wei_ok");
	me->delete_temp("wei_job");
	me->delete_temp("dtsl_job");
	me->set("busy_time",time());
	if(present("chu tou",me))
	  destruct(present("chu tou",me));
	
	JOBSYS_D->give_reward_caiyao(me);
	
	return 1;
}