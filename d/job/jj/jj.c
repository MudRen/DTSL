#include <ansi.h>
#include <job_money.h>

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
string ask_quest()
{
	object ob,me;mapping ask_msg;
	ob=this_object();
	me=this_player();
	if(!me->query_temp("buzhi_jiangjing/"+ob->query("jj_flag")))
		return "ʩ����˵ʲô��ƶɮ����һ�㶼��������\n";
	if(ob->query("ask_ob")&&ob->query("ask_ob")!=me) return "ʩ���Ժ�ƶɮ��æ���أ�\n";
	if(ob->query("ask_ob")==me)
	return "��ʦ���ǿ�ش��ҵ�����ɣ�\n";
	me->set_temp("buzhi_jiangjing/flag",1);
    ask_msg=ask[random(sizeof(ask))];
	ob->set("ask",ask_msg);
	ob->set("ask_ob",me);
	call_out("cancel_ask",15,me);
 	return ""+ask_msg["ask"]+",�˾����ν���?\n";

}

int do_answer(string arg)
{
	object me,ob,bonze,ans;
	int lev,exp,pot,coin;
	mapping answer;
	me=this_player();
	if(!arg) return notify_fail("����ش�ʲô?\n");
	if(sscanf(arg,"%s %s",bonze,ans)!=2)
		return notify_fail("��ʹ�� answer ���� ��\n");
	if(!objectp(ob=present(bonze,environment(me))))
		return notify_fail("����û�������!\n");
	if(ob->query("ask_ob")!=me)
		return notify_fail(ob->name()+"��û����������!\n");
	answer=ob->query("ask");
	if(ans!=answer["answer"])
		return notify_fail("��Ĵ𰸲���!\n");
	me->delete_temp("buzhi_jiangjing");
	me->delete_temp("no_quit");
	ob->delete("ask");
	ob->delete("ask_ob");
	if(me->query_temp("need_killer")<=me->query_temp("need_killer_flags")){
	if(me->query("combat_exp")<100000)
	exp=me->query("max_pot")/3;
	else exp=200+random(10);
	if(me->query("combat_exp")<100000)
	pot=me->query("max_pot")/4;
	else pot=me->query("max_pot")/3;
	lev=30+random(5);
	coin=JIANGJING;}
	else{
	 exp=10+random(10);
	 pot=5+random(5);
	 lev=2+random(2);}
	me->delete_temp("need_killer");
	me->delete_temp("need_killer_flags");
	me->add("combat_exp",exp);
	me->add("potential",pot);
	if(me->query("potential")>me->query("max_pot"))
	me->set("potential",me->query("max_pot"));
        add_shili(me,exp/3,JIANGJING);
	me->improve_skill("chanzong-fofa",lev);
	me->delete_temp("other_give");
	me->delete_temp("dtsl_job");
	tell_object(me,"����ν���������,��õ���"+""HIW""+chinese_number(exp)+""NOR""+"�㾭��ֵ "+""HIW""+chinese_number(pot)+""NOR""+"��Ǳ�� \n");
	tell_object(me,"���"+""HIW""+"[���ڷ�]"+""NOR""+"����ΪҲ���˽�һ�������!\n");
	message_vision("$N��ʮ��:��ʦ����,лл!\n",ob);
	return 1;
}
void cancel_ask(object me)
{
  if(!me) return;
  if(me->query_temp("buzhi_jiangjing")){
  message_vision(YEL"���г�$N̾����������ķ���Ϊ�����Ǻܸߣ��������ٻش�ɣ�\n"NOR,me);
  this_object()->delete("ask");
  this_object()->delete("ask_ob");
  return;}
  return;
}	