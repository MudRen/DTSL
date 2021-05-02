#include <ansi.h>
inherit NPC;
#include <job_money.h>
string give_job();
int i=3;
void create()
{
   set_name("����",({ "bu zhi","bu","zhi"}));
        set("gender", "����" );
        set("age", 32);
   set("long", "���Ǿ�����Ժ�ĵõ���ɮ,���ķ�ˮƽ�����൱�ߵġ�\n");
   set("class","bonze");
   set("combat_exp", 400000);
   set("str", 28);
   set("per", 22);
   set("attitude", "peaceful");
   set_skill("dodge",80);
   set_skill("parry",90);
   set_skill("staff",90);
   set_skill("force",150);
   set_skill("blade",150);
   set_skill("chanzong-fofa",150);
   set_skill("chanzong-fofa",100);
//    set_skill("jinguang-daofa",150);
//    set_skill("wuxiang-zhangfa",90);
   set("staff",({"wuxiang-zhangfa"}));
   set_skill("liuyun",150);
   set("dodge",({"liuyun"}));
    create_family("������Ժ",5,"ɮ��");
	set("inquiry",([
		"����":(:give_job:),
		"���᱾����,�������̨":"������һ��,�δ��ǳ���",
		"��������":"�ڼ����Բ�������Ϊ��",
		"��������":"�����ڶ�����Ϊ����",
		]));
   setup();
   carry_object(__DIR__"obj/sengyi")->wear();
   carry_object(__DIR__"obj/staff")->wield();

}

void init()
{
	object ob,ob2;
	ob=this_player();
	ob2=this_object();
	::init();
	if(!ob||!present(ob,environment())) return;

	call_out("welcome",1,ob,ob2);

}

void welcome(object ob,object ob2)
{
   if(!ob||!present(ob,environment())) return;
	switch(random(2))
	{
	case 0: message_vision("$N�����е��������ӷ�!\n",ob2);break;
	case 1: message_vision("$N��$n���������Ե�ˡ�\n",ob2,ob);
	}
	remove_call_out("welcome");
	return;
}

string give_job()
{
	object ob,me;string str;
	ob=this_object();me=this_player();

	if(me->query("class")!="bonze") return "���Ƿ�ҵ���,���ȥ��������?\n";
	if((int)me->query_skill("chanzong-fofa",1)<=30)
		return "���[���ڷ�]��Ϊ̫����,������ѧϰ��!\n";
	if(me->query_temp("buzhi_jiangjing"))
		return "�㻹�����������е��°�!������,��ô����?\n";
	if(time()-me->query("busy_time")<120)
	return "�㻹��ЪЪ�ɣ�\n";
	if(me->query_temp("dtsl_job"))
        return "������������������æ�����İɣ�\n";
        if(!valid_do_job(me,"jiangjing"))
	return "��ķ���Ϊ�Ѿ��ܸ��ˣ������ٳ�ȥ�����ˣ�\n";
	me->set("busy_time",time());
	me->set_temp("dtsl_job","������Ժ��������");
	if((int)me->query("combat_exp",1)>=100000)
	{ call_out("killer_jj",15,me);str="·�Ͽ����ж���,��ҪС��!\n";
	  me->set_temp("other_give",100);
	}
	else str="\n";
	switch(random(i))
	{
	case 0: me->set_temp("buzhi_jiangjing/1",1);return "�ð�,��ȥ�ɶ���һ������ȥ������!\n"+str;
	case 1: me->set_temp("buzhi_jiangjing/2",1);return "�ð�,��ȥ���ݵİ�����ȥ������!\n"+str;
	case 2: me->set_temp("buzhi_jiangjing/3",1);return "�ð�,��ȥ�����ı�����ȥ������!\n"+str;

	}
}

void killer_jj(object me)
{
	object killer;
	if(!objectp(me)||!me->query_temp("buzhi_jiangjing")) {remove_call_out("killer_jj");return;}
	if(me->query_temp("buzhi_jiangjing"))
	{
		killer=new(__DIR__"killer");
	killer->set("combat_exp",(int)me->query("combat_exp",1)-20);
	copy_object(killer,me);
	set_all_skill(killer,me->query("max_pot")-140);
	killer->set_name("ɱ��",({"killer"}));
	killer->delete("family");
	killer->delete("nickname");
	killer->delete("shili");
	killer->move(environment(me));
	message_vision(HIR"$N��$n��Ц��:ʲô�𷨷�,���ӾͲ������,��Ͱ�С�������������!\n"NOR,killer,me);
	message_vision("$N�ƺ�����$n��!\n",killer,me);
	me->start_busy(1);
	killer->set_leader(me);
	killer->kill_ob(me);
	}
	remove_call_out("killer_jj");
	return;
}
