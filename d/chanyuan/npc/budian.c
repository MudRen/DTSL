
inherit NPC;

#include <ansi.h>
#include <job_money.h>

string give_job();
int do_ok(string arg);
int cancel_job();

void create()
{
   set_name("����",({ "bu dian","bu","dian"}));
        set("gender", "����" );
        set("age", 32);
   set("long", "���Ǿ�����Ժ�ĸ�ɮ��\n");
   set("class","bonze"); 
   set("combat_exp", 200000);
   set("str", 28);
   set("attitude", "peaceful");
   set_skill("dodge",100);
   set_skill("parry",100);
   set_skill("staff",100);
   set_skill("force",100);
   set_skill("chanzong-fofa",100);
   set_skill("liuyun",100);
   set_skill("blade",100);
   
   create_family("������Ժ",5,"ɮ��");
   set("target_id","###");
   set("inquiry",([
	   "job":(:give_job:),
	   "����":(:cancel_job:),
	   ]));
   setup();
   carry_object(__DIR__"obj/sengyi")->wear();
   carry_object(__DIR__"obj/staff")->wield();
  
}

void init()
{
	add_action("do_ok","task");
}

string give_job()
{
	object me;
	
	me=this_player();
	
	if((int)me->query("combat_exp",1)>=100000)
		return ""+RANK_D->query_respect(me)+",�����Ĺ���̫ί������!\n";
        
	if(me->query_temp("budian_job"))
		return ""+RANK_D->query_respect(me)+",������������ͷ���°�!\n";
	if(time()-(int)me->query("busy_time",1)<=30+random(10))
		return ""+RANK_D->query_respect(me)+",������ЪЪ��!\n";
	if(me->query_temp("dtsl_job"))
        return "������������������æ�����İɣ�\n";
	me->set("busy_time",time());
	me->set_temp("dtsl_job","������Ժ��������");
	switch(random(3))
	{
	case 0: me->set_temp("budian_job/1",1);return "�ð�,�鷳"+RANK_D->query_respect(me)+"ȥ��ɨһ�¾���(sao ����)��!\n";
        case 1: me->set_temp("budian_job/2",1);return "�ð�,�鷳"+RANK_D->query_respect(me)+"ȥ����԰�ֲ�(zhong ��)��!\n";
	case 2: me->set_temp("budian_job/3",1);return "�ð�,�鷳"+RANK_D->query_respect(me)+"ȥ��ɨһ�����䳡(sao �䳡)��!\n";
	}
}

int do_ok(string arg)
{
	object me;
	
	me=this_player();
	
	if(!arg||arg!="ok") return notify_fail("����˵ʲô?\n");
        if(!me->query_temp("budian_job"))
		return notify_fail(""+RANK_D->query_respect(me)+",�⻰�Ӻ�˵��?\n");
	if(me->query_temp("budian_job"))
	 if(!me->query_temp("budian_job/ok"))
	return notify_fail("����Ц��:��"+RANK_D->query_respect(me)+"��������һЩ��!\n");
	
	me->delete_temp("budian_job");
	me->delete_temp("dtsl_job");
        JOBSYS_D->give_reward_chanyuanjob(me);
	return 1;
}

int cancel_job()
{
  object ob;
  
  ob=this_player();
  
  if(!ob->query_temp("budian_job")){
   command("?");
   return 1;
  }
  
  JOBSYS_D->do_cancel_job("chujichanyuan_job",ob,this_object());
  
  command("sigh "+ob->query("id"));
  return 1;
}
