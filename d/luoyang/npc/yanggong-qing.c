#include <ansi.h>
#include <job_money.h>
inherit NPC;
string give_job();
void create()
{
   set_name("���",({ "yang gongqing","yang","gong","qing" }) );
        set("gender", "����" );
        set("age", 42);
   set("long", "���������������Ҫ��ʦ���\n");
       
   set("combat_exp", 200000);
   set("str", 20);
   set("per", 20);
   set("shili","wang");
   set("attitude", "peaceful");
   set_skill("dodge",100);
   set_skill("unarmed",100);
   set_skill("parry",100);
   set("inquiry",([
	   "��ͽ":(:give_job:),
	   ]));
   setup();
   carry_object(__DIR__"obj/guanfu")->wear();
  
}

string give_job()
{
	object me;
	me=this_player();
	if(me->query_temp("yang_kill_pantu"))
		return ""+RANK_D->query_respect(me)+",�����˿ɲ�ϲ�����²�������˰�!\n";
	if(time()-(int)me->query("busy_time",1)<=120)
		return ""+RANK_D->query_respect(me)+",�㻹����ЪЪ��!\n";
	if(me->query_temp("dtsl_job"))
        return "������������������æ�����İɣ�\n";
        if(!valid_do_job(me,"killpantu"))
	return "����书�ܸ��ˣ���������С�����Ǵ��С���ˣ�\n";
        me->set_temp("dtsl_job","���ɱ��ͽ����");
	switch(random(3))
	{   case 0:
		me->set_temp("yang_kill_pantu/1",1);
	     return "�ð�,��ô��"+RANK_D->query_respect(me)+"������ȥ[�Ͼ���]ɱ�˿ɷ��Ǹ�����!\n�������û������׼�!\n";
        break;
	case 1:
		me->set_temp("yang_kill_pantu/2",1);
	     return "�ð�,��ô��"+RANK_D->query_respect(me)+"������ȥ��üɽɱ�˿ɷ��Ǹ�����!\n�������û������׼�!\n";
        break;
	case 2:
		me->set_temp("yang_kill_pantu/3",1);
	     return "�ð�,��ô��"+RANK_D->query_respect(me)+"������ȥ����ɱ�˿ɷ��Ǹ�����!\n�������û������׼�!\n";
        break;
	}
}

int accept_object(object me,object ob)
{
	int exp,pot,sil,famous,exp2;
	object npc;
	npc=this_object();
	if(!me->query_temp("yang_kill_pantu")) return 0;
	if((string)ob->query("dead_id")!="ke feng") return 0;
	if(ob->query("killed_by")!=me->query("id")) return 0;
	pot=me->query("max_pot")/3;
	exp=200+random(20);
	sil=KILL_PANTU_JOB;
	me->add("combat_exp",exp);
	me->add("potential",pot);
	me->add("deposit",sil);
	add_shili(me,exp/3,sil);
	me->delete_temp("yang_kill_pantu");
	me->delete_temp("flag");
	me->delete_temp("dtsl_job");
	me->set("busy_time",time());
	tell_object(me,"���Ц��:"+RANK_D->query_respect(me)+",лл��!\n");
	tell_object(me,"��佱������"+""HIW""+chinese_number(sil/100)+""NOR""+"������\n");
	tell_object(me,"���Ǯׯ��������ˣ�\n");
	tell_object(me,"������ж�����õ���"+""HIW""+chinese_number(exp)+""NOR""+"�㾭��ֵ "+""HIW""+chinese_number(pot)+""NOR""+"��Ǳ��.\n");
	return 1;
}