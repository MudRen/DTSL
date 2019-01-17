
inherit NPC;
#include <ansi.h>
#include <job_money.h>
string give_job();
int do_ok(string arg);
void create()
{
   set_name("����ɽ",({ "xiang yushan","xiang","yushan" }) );
        set("gender", "����" );
        set("age", 25);
   set("long", "����[�����]������ɽ��\n");
       
   set("combat_exp", 80000);
   set("str", 10);
   set("per", 25);
   set_skill("parry",30);
   set_skill("unarmed",30);
   set_skill("dodge",30);
   set("force",200);
   set("max_force",200);
   set_skill("force",30);
   set("attitude", "peaceful");
   set("inquiry",([
	   "�����˿�":(:give_job:),
	   ]));
   setup();
   carry_object(__DIR__"obj/chouyi")->wear();
  
}

void init()
{
	add_action("do_ok","jiaochai");
}

string give_job()
{
	object me;
	me=this_player();
	if(me->query("gender")=="Ů��")
		return "���ֹ���Ů���������ģ�\n";
	if(me->query_temp("fanmai_job"))
		return "�����»���һ��һ�����ɣ�\n";
	if(time()-me->query("busy_time")<=130+random(5))
		return "����ЪЪ�ɣ�\n";
	me->set_temp("fanmai_job",1);
	return "�ð�,��Ȼ"+RANK_D->query_respect(me)+"Ը�⣬�����һ��Ư���Ĺ���������\n���Ҳ��������ģ�\n";
}

int do_ok(string arg)
{
	object me,ob,money;
	int exp,pot,sil,famous;int i,per;
	me=this_player();i=0;
	if(!arg) return notify_fail("����ʲô�����\n");
	if(!me->query_temp("fanmai_job")&&me->query("vocation")!="�˷���")
		return notify_fail("�⻰�Ӻ�˵��\n");
	if(!objectp(ob=present(arg,environment(me))))
		return notify_fail("����û������ˣ�\n");
	if(ob->query("gender")=="����")
		return notify_fail("���˿ɲ�Ҫ��\n");
    if(ob->query("per")<=25&&me->query("vocation")!="�˷���")
		return notify_fail("����˵���ɫ�����ҵ�Ҫ���㻹�ǻ�һ���ɣ�\n");
	exp=me->query("combat_exp");
    while(exp>10)
	{ exp=exp/10; i++;}
	exp=exp+i*20;
	pot=exp*2/3;
	sil=exp/3;
	per=ob->query("per");
    tell_object(environment(me),"����ɽ��ͷ�������ˣ�����λ�������ȥ��\n");
	tell_object(environment(me),"���̳���һ���ˣ���"+ob->name()+"���ȥ�ˡ�\n");
	destruct(ob);
	if(me->query_temp("fanmai_job"))
	{
        sil=QIANGJIE_JOB;
	me->add("deposit",QIANGJIE_JOB);
	me->add("combat_exp",exp);
	me->add("potential",pot);
	add_shili(me,exp/4,QIANGJIE_JOB/3);
	if(me->query("famous")>=15) me->add("famous",-10-random(5)); 
	me->delete_temp("fanmai_job");
	me->set("busy_time",time());
	tell_object(me,"������ж�����õ���"+
                ""HIW""+chinese_number(exp)+""NOR""+"�㾭��ֵ"+
                ""HIW""+chinese_number(pot)+""NOR""+"��Ǳ��"+
                "����ɽ��������"+""HIW""+chinese_number(sil)+""NOR""+"��ͭǮ��\n");
        tell_object(me,"��Ǯׯ�Ĵ�������ˣ�\n");
	tell_object(me,"���ڷ����˿ڣ���Ľ������������ˣ�\n");
	}
	else
	{
		tell_object(me,"����ɽЦ�����ã������Ŭ���ɣ�\n");
		me->add("vocation_score",per);
		me->add("vocation_exp",per+random(10));
		me->add("famous",per/2);
	}
	return 1;
}
