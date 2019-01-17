
inherit NPC;
#include <ansi.h>
mapping *ask=({
([
 "ask":HIW"���᱾����,�������̨"NOR,
 "answer":"������һ��,�δ��ǳ���",
 ]),
 ([
 "ask":HIW"����������"NOR,
 "answer":"�ڼ����Բ�������Ϊ��",
 ]),
 ([
 "ask":HIW"����������"NOR,
 "answer":"�����ڶ�����Ϊ����",
 ])
});

int do_answer(string arg);
void create()
{
       set_name("����", ({ "he shang","he","shang"}) );
       set("gender", "����" );
       set("age", 30);
       set("long","���ǰ����µ�ɮ��.\n");
       set("combat_exp", 12500);
       set("attitude", "friendly");
       set("class","bonze");
       setup();
 carry_object(__DIR__"obj/sengyi")->wear();


}
void init()
{
	object *ob,here;int i;
	add_action("do_answer","answer");
    here=find_object("/d/yangzhou/baimasi");
	ob=all_inventory(here);
  for(i=0;i<sizeof(ob);i++)
	{
		if(ob[i]->query_temp("buzhi_jiangjing/2")
			&&!ob[i]->query_temp("buzhi_jiangjing/flag"))
			call_out("ask_quest",1,ob[i]);
	}
	return;
        
}

void ask_quest(object me)
{
	object ob;mapping ask_msg;
	ob=this_object();
	me->set_temp("buzhi_jiangjing/flag",1);
    ask_msg=ask[random(sizeof(ask))];
	ob->set("ask",ask_msg);
 	message_vision("$N��$n�ʵ�:"+ask_msg["ask"]+",�˾����ν���?\n",ob,me);
    call_out("clear_jiangjing",60,ob,me);



   remove_call_out("ask_quest");
   return;
}

void clear_jiangjing(object ob,object me)
{
	if(me->query_temp("buzhi_jiangjing"))
	{ob->delete("ask");
	me->delete_temp("buzhi_jiangjing");
	message_vision("$N����$n̾��:�㻹�ǻ�ȥ�ú�ѧѧ������!\n",ob,me);
	remove_call_out("clear_jiangjing");}
	else remove_call_out("clear_jiangjing");
	return;
}

int do_answer(string arg)
{
	object me,ob,bonze,ans;
	int lev,exp,pot;
	mapping answer;
	me=this_player();
	if(!arg) return notify_fail("����ش�ʲô?\n");
	if(sscanf(arg,"%s %s",bonze,ans)!=2)
		return notify_fail("��ʹ�� answer ���� ��\n");
	if(!objectp(ob=present(bonze,environment(me))))
		return notify_fail("����û�������!\n");
	if(!ob->query("ask"))
		return notify_fail(ob->name()+"��û����������!\n");
	answer=ob->query("ask");
	if(ans!=answer["answer"])
		return notify_fail("��Ĵ𰸲���!\n");
	me->delete_temp("buzhi_jiangjing");
	ob->delete("ask");
	exp=(int)me->query("combat_exp",1);
	if(exp<=999) exp=50+random(5);
	else if(exp<=9999) exp=exp/100+50+random(5);
	else if(exp<=99999) exp=exp/1000+200+random(5);
	else exp=exp/10000+500+random(5);
	pot=(int)me->query("max_pot");
	pot=pot/3;
	lev=20+random(5);
	me->add("combat_exp",exp);
	me->add("potential",pot);
	me->improve_skill("chanzong-fofa",lev);
	tell_object(me,"����ν���������,��õ���"+""HIW""+chinese_number(exp)+""NOR""+"�㾭��ֵ "+""HIW""+chinese_number(pot)+""NOR""+"��Ǳ�� \n");
	tell_object(me,"���"+""HIW""+"[���ڷ�]"+""NOR""+"����ΪҲ���˽�һ�������!\n");
	message_vision("$N��ʮ��:��ʦ����,лл!\n",ob);
	return 1;
}
	