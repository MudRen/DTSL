
inherit NPC;
#include <job_money.h>
#include <ansi.h>
string give_job();
void create()
{
   set_name("����",({ "shang zhen","shang","zhen" }) );
        set("gender", "����" );
        set("age", 50);
   set("long", "�����Ƿ��������Ĵ�ܼ�,�Ӳ�����ȥ��Ӧ����ʮ���£�����ƽֱ���ϴ��Ļ���
���ߺ���΢���̵��´��ľ���������ʾ�����к�ǿ�ĸ��Ժ����š�\n");
       
   set("combat_exp",400000);
   set("str", 26);
   set("per", 22);
   set("attitude", "peaceful");
   set_skill("unarmed",150);
   set_skill("dodge",150);
   set_skill("parry",150);
   set_skill("tao",150);
   set_skill("strike",150);
   set_skill("cuff",150);
   set_skill("babu-ganchan",170);
   set("hand",({"liu","liang","tao"}));
   set("dodge",({"babu-ganchan"}));
   set("inquiry",([
	   "��ͽ":(:give_job:),
	   ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

void init()
{
	object ob,ob2;
	ob=this_player();
	ob2=this_object();
	::init();
	if(!ob||!present(ob,environment())||ob2->is_fighting()) return;
	call_out("welcome",1,ob,ob2);
	
}

void welcome(object ob,object ob2)
{
   if(!ob||!present(ob,environment())||ob2->is_fighting()) return;
	switch(random(2))
	{
	case 0: message_vision("$N����غ���һ��.\n",ob2);break;
	case 1: message_vision("$N�����۴�����$n\n",ob2,ob);
	}
	remove_call_out("welcome");
	return;
}
string give_job()
{
   object me;object ob;
   ob=this_object();
   me=this_player();
   if(me->query_temp("shang_kill_pantu"))
	   return "�㻹���Ȱ���ͽɱ����˵��!\n";
 /*  if(ob->query("job_time"))
	   if(time()-ob->query("job_time")<=30)
		   return "��..���,�Ѿ����˰�æ��,���ȵȻ��!\n";*/
   if(time()-me->query("busy_time")<30)
   return "�㻹����ЪЪ�ɣ�\n";
   if(me->query_temp("dtsl_job"))
   return "������������������æ�����İɣ�\n";
   if(!valid_do_job(me,"feimajob"))
	return "����书�ܸ��ˣ���������С�����Ǵ��С���ˣ�\n";
   me->set_temp("dtsl_job","��������ɱ��ͽ����");
   ob->set("job_time",time());
 //  call_out("cancel_shang_kill_pantu",420,me);
   switch(random(6))
   {
   case 0: me->set_temp("shang_kill_pantu/1",1);return "�ð�,��ȥ�ѷ�����������ͽɱ��,�������û������׼�!\n��˵�������ݵ�һ��������԰�������!\n";break;
   case 1: me->set_temp("shang_kill_pantu/2",1);return "�ð�,��ȥ�ѷ�����������ͽɱ��,�������û������׼�!\n��˵���ڳɶ���һ������֮�Ҳ���!\n";break;
   case 2: me->set_temp("shang_kill_pantu/3",1);return "�ð�,��ȥ�ѷ�����������ͽɱ��,�������û������׼�!\n��˵����������������Ľ�ͷС����!\n";break;
   case 3: me->set_temp("shang_kill_pantu/4",1);return "�ð�,��ȥ�ѷ�����������ͽɱ��,�������û������׼�!\n��˵����������ڳ����ĳ�������!\n";break;
   case 4: me->set_temp("shang_kill_pantu/5",1);return "�ð�,��ȥ�ѷ�����������ͽɱ��,�������û������׼�!\n��˵�����������ɽ���ص���Į����!\n";break;
   case 5: me->set_temp("shang_kill_pantu/6",1);return "�ð�,��ȥ�ѷ�����������ͽɱ��,�������û������׼�!\n��˵����������ں��ݵ�������!\n";break;
   }
   
}

void cancel_shang_kill_pantu(object me)
{
	if(!objectp(me)) {remove_call_out("cancel_shang_kill_pantu");return;}
	if(me->query_temp("shang_kill_pantu"))
	{
		tell_object(me,HIW"������̫����,�������ȡ����!\n"NOR);
		me->delete_temp("shang_kill_pantu");
		remove_call_out("cancel_shang_kill_pantu");
		return;
	}
	remove_call_out("cancel_shang_kill_pantu");
}

int accept_object(object me,object ob)
{
	int exp,sil,pot,i,j;
	object npc;
	j=10;
	npc=this_object();
	if(!me->query_temp("shang_kill_pantu"))
		return notify_fail("�ҿɲ����Ҫ���˵Ķ�����\n");
	if((string)ob->query("dead_id")!="tao shusheng")
		return notify_fail("��ɱ�����˰ɣ�\n");
	if(ob->query("killed_by")!=me->query("id"))
	return notify_fail("�ߣ�������ɱ���ˣ�����ð���𣿣�\n");
	me->delete_temp("shang_kill_pantu");
	me->delete_temp("dtsl_job");
        exp=210+random(20);
        pot=me->query("max_pot")/3;
	me->add("combat_exp",exp);
	sil=FEIMA_JOB;
	pot=50+random(10);
	me->set("busy_time",time());
	me->add("potential",pot);
	me->add("deposit",FEIMA_JOB);
	add_shili(me,exp/3,FEIMA_JOB/2);
	tell_object(me,HIW"\n�㱻������"+exp+"�㾭��ֵ "+pot+"��Ǳ��"+sil/100+"������\n"NOR);
	tell_object(me,HIW"лл��,Ϊ���Ƿ�������������ô��ĺ���!\n"NOR);
	tell_object(me,"���Ǯׯ��������ˣ�\n");
	remove_call_out("cancel_shang_kill_pantu");
	return 1;
}

