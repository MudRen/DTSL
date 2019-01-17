
inherit NPC;

#include <ansi.h>
#include <job_money.h>

string give_job();
int cancel_job();

void create()
{
       set_name("������", ({ "zhang popo", "zhang","popo" }) );
       set("gender", "Ů��" );
     
       set("age", 50);
       set("long",
               "���Ƕ����ɵĵ��ӡ�\n");
       set("combat_exp",450000);
       set("attitude", "peaceful");
       set("str", 40);
        set("int", 40);
        set("con", 40);
        set("dex", 40);
        set("max_qi", 1500);
        set("max_jing", 1500);
        set("eff_jingli", 1500);
        set("jing", 1500);
        set("jingli", 1500);
        set("eff_jing", 1500);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali",100);
        set("target_id","###");
        create_family("������",4,"����");
    	set("inquiry",([
			"job":(:give_job:),
			"����":(:cancel_job:),
			]));
       

 
       setup();
 carry_object(__DIR__"obj/cloth")->wear();
 carry_object(__DIR__"obj/changjian")->wield();
 
 
}
void init()
{
        object ob;

        ::init();add_action("do_ok","task");
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
	 

	if (!ob || !present(ob, environment())) return;
	switch( random(2) ) {
		case 0:
			say( "������˵��������"+ob->query("name")
          + "ô��,��������ɻ��!\n");
			break;
		case 1:
			say( "������˵��:��ú�Ŭ��!!\n");
			break;
	}

}

string give_job()
{
	object ob,thing;ob=this_player();
	if((int)ob->query("combat_exp",1)>150000)
		return "�������ڵ������������򵥵�����̫��ϧ��!\n";
	if(ob->query_temp("popo_job"))
		return "�����ɵĵ������¿�û�л�ͷ��β��!\n";
	if(ob->query("family/family_name")!="������")
		return "ֻ�ж����ɵĵ��ӿ���������ɻ\n";
	if(time()-ob->query("busy_time")<=30)
		return "�㻹��ЪЪ�ɣ�\n";
	if(ob->query_temp("dtsl_job"))
   return "������������������æ�����İɣ�\n";
   ob->set_temp("dtsl_job","�����ɳ�������");
	switch(random(3))
	{
	case 0:ob->set_temp("popo_job",1);ob->set_temp("popo_job1",1);ob->set_temp("count",1);return "�ð�,��ȥ����������(zhong ����)��!\n";break;
    case 1:ob->set_temp("popo_job",1);ob->set_temp("popo_job2",1);ob->set_temp("count",1);return "�ð�,��ȥ��ɨ���ƹ�(sao ��)��!\n";break;
    case 2:ob->set_temp("popo_job",1);ob->set_temp("popo_job3",1);ob->set_temp("count",1);return "�ð�,��ȥ������ĥ����(mo ����)��!\n";break;
    
    }
}

int do_ok(string arg)
{
	
	object ob=this_player();
	
	if(!arg||arg!="ok") return notify_fail("����˵ʲô?\n");
    if(!ob->query_temp("popo_ok"))
		return notify_fail("�����ɵ������¿�û�л�ͷ��β��!\n");
    ob->delete_temp("popo_ok");
    ob->delete_temp("dtsl_job");
    
    JOBSYS_D->give_reward_dmchujijob(ob);
    
    return 1;
}

int cancel_job()
{
   object ob;
   
   ob=this_player();
   
   if(!ob->query_temp("popo_job")){
   command("?");
   return 1;
   }
   JOBSYS_D->do_cancel_job("dmchujijob",ob,this_object());
   command("sigh");
   return 1;
}

   