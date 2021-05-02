
inherit NPC;
inherit F_MASTER;

#include <ansi.h>
#include "bonze.h"
int do_action2();
int do_action1();
int do_action3();
int do_answer(string arg);

void create()
{
   int i;
   object *ob;

   set_name("����",({ "bu chi","bu","chi"}));
        set("gender", "����" );
        set("age", 32);
   set("long", "���Ǿ�����Ժ���Ĵ󻤷����֮һ��\n");
   set("class","bonze");
   set("combat_exp", 600000);
   set("str", 28);
   set_skill("dodge",150);
   set_skill("parry",150);
   set_skill("staff",150);
   set_skill("force",150);

   set_skill("fumo-zhangfa",150);
   set_skill("wuxiang-shengong",150);
   set_skill("bikouchan",150);
   set_skill("chanzong-fofa",160);
   set_skill("literate",160);
   set_skill("lianhua-step",150);

   set("max_gin",2000);
   set("max_kee",2000);
   set("max_sen",2000);
   set("max_force",2000);
   set("force",2000);

   set("inquiry",([
       "����":(:do_action1:),
       "����":(:do_action2:),
       "��ħ�ȷ�":(:do_action3:),
       ]));
   set("perform_quest/fumo",1);
   create_family("������Ժ",5,"����");
   setup();

   ob=children(__DIR__"obj/xiangmo-zhang");
   for(i=0;i<sizeof(ob);i++)
     if(environment(ob[i])&&userp(environment(ob[i]))){
     tell_object(environment(ob[i]),"�����е�"+ob[i]->query("name")+"�����������ջ�ȥ�ˣ�\n");
     if(ob[i]->query("equipped"))
      ob[i]->unequip();
     destruct(ob[i]);}
     else if(environment(ob[i])){
     tell_object(environment(ob[i]),ob[i]->query("name")+"��һ�������ˡ�\n");
     destruct(ob[i]);}
     else destruct(ob[i]);

   carry_object(__DIR__"obj/xiangmo-zhang")->wield();

}

void init()
{
   add_action("do_answer","answer");
}

void attempt_apprentice(object ob)
{
	int lev;

	if(ob->query("family")
	   &&ob->query("family/family_name")=="������Ժ"
	   &&ob->query("family/generation",1)<=5){
	    command("say �����Ὺ��Ц��");
	    return;
	}

	if(ob->query("gender")=="Ů��")
	{
	    command("say ����ʩ����ΪŮ��֮���������е���ѧϰ�𷨡���ʩ������ϣ��\n"+
	            "�������Ŵ�ɵ��Ⱥ���ի��");
	    return;
	}

	if(ob->query("couple")){
	  command("say ��Ϊ�˷�ȴ������֮���Σ����Ǿ�����Ժ��Ҫ��˲��ʲ���֮ͽ��");
	  return;
	}

	if((int)ob->query("PKS",1)>=5)
	{
		command("say ʩ�����������أ����������Ϊͽ�أ�");
		return;
	}

	if(ob->query("bellicosity")>=100){
	  command("say ʩ������ɱ�����أ������ר�Ĺ��������أ�");
	  return;
	}
	if(ob->query_skill("wuxiang-shengong",1)<100){
	  command("say ��ġ������񹦡���Ϊ̫���ˣ�����ȥѧϰһ���ٰ���Ϊʦ�ɣ�");
	  return;
	}
	if(ob->query("office_number")<30){
	  command("say ��Ĺ���̫���ˣ��Ҳ�ϲ������ĵ��ӣ�");
	  return;
	}
	if(ob->query("family/generation",1)>7){
	  command("say ��ı���̫���ˣ���ΰ���Ϊʦ��");
	  return;
	}
	if(!ob->query_temp("try_bai_buchi_ok")){
	  command("say ��û�����ҵĿ��飬�Ҳ�������Ϊͽ�ġ�");
	  return;
	}

	lev=ob->query_skill("cuff",1);
	lev=lev*lev/(lev+100);
	ob->party_reward_skill("staff",lev);
	tell_object(ob,HIY"\n��ӻ���ȭ�����������һЩ�����ȷ���\n\n"NOR);

	command("say �����ӷ�ϣ�����Ժ��ܹ⴫�𷨣��ն�������\n");
	command("recruit "+ob->query("id"));
	ob->delete_temp("try_bai_butan_ok");
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "bonze");
     ob->set("chanyuan_skill","fumo-zhangfa");
}

int do_action1()
{
   object ob;
   string msg;

   ob=this_player();

        if(ob->query("family")
	   &&ob->query("family/family_name")=="������Ժ"
	   &&ob->query("family/generation",1)<=5){
	    command("say �����Ὺ��Ц��");
	    return 1;
	}

        if(ob->query("family/generation")<=6){
          command("say ���Ѿ��������飬�����ٴο����ˣ�");
          return 1;
        }

	if(ob->query("gender")=="Ů��")
	{
	    command("say ����ʩ����ΪŮ��֮���������е���ѧϰ�𷨡���ʩ������ϣ��\n"+
	            "�������Ŵ�ɵ��Ⱥ���ի��");
	    return 1;
	}

	if(ob->query("couple")){
	  command("say ��Ϊ�˷�ȴ������֮���Σ����Ǿ�����Ժ��Ҫ��˲��ʲ���֮ͽ��");
	  return 1;
	}

	if((int)ob->query("PKS",1)>=5)
	{
		command("say ʩ�����������أ����������Ϊͽ�أ�");
		return 1;
	}

	if(ob->query("bellicosity")>=100){
	  command("say ʩ������ɱ�����أ������ר�Ĺ��������أ�");
	  return 1;
	}
	if(ob->query_skill("wuxiang-shengong",1)<100){
	  command("say ��ġ������񹦡���Ϊ̫���ˣ�����ȥѧϰһ���ٰ���Ϊʦ�ɣ�");
	  return 1;
	}
	if(ob->query("office_number")<30){
	  command("say ��Ĺ���̫���ˣ��Ҳ�ϲ������ĵ��ӣ�");
	  return 1;
	}
	if(ob->query("family/generation",1)>7){
	  command("say ��ı���̫���ˣ���ΰ���Ϊʦ��");
	  return 1;
	}
	if(time()-ob->query("mud_flags/try_bai_buchi_time")<300){
	  command("say �㻹�ǹ�һ��ʱ���������Ұɣ�");
	  return 1;
	}

	msg="$N��$n˵�������ҿ�Ҫ������һ�£�\n"+
	"���������������ս�����飨exp����Ҫ������ս�����ܣ�skills����Ҫ����\n"+
	"���ǽ�Ǯ��gold����Ҫ������\n";
	message_vision(msg,this_object(),ob);
	ob->set_temp("try_bai_buchi_actoin1",1);
	ob->delete("mud_flags/try_bai_buchi_time");
	return 1;
}

int do_answer(string arg)
{
  object ob;
  string msg;

  ob=this_player();

  if(!ob->query_temp("try_bai_buchi_actoin1")&&
     !ob->query_temp("try_bai_buchi_actoin2"))
  return 0;
  if(!arg||
      (arg!="exp"&&
       arg!="skill"&&
       arg!="gold"&&
       arg!="agree"&&
       arg!="disagree"
       )
     )
  return notify_fail("����ȷ�ش����⡣\n");

 if(ob->query_temp("try_bai_buchi_actoin1")){
   if(arg!="exp"&&arg!="skill"&&arg!="gold")
   return notify_fail("����ȷ�ش����⡣\n");
  if(arg=="exp")
    msg="$N��$n˵�������ã��������Ӿ���ֻ��̲��Է����Գɳ��������ڷ��㾭�飬��Ը���𣿡�\n";
  if(arg=="skill")
    msg="$N��$n˵��������Ĺ����ѹ�ʱ����ʱ���ƾ������ˣ����������¾͸÷�ȥ�书����Ը���𣿡�\n";
  if(arg=="gold")
    msg="N��$n˵������������ԺҲ������һ���ˣ����ȫ���Ƹ����׸���Ժ��������\n";
  ob->delete_temp("try_bai_buchi_actoin1");
  ob->set_temp("try_bai_buchi_actoin2",arg);
  message_vision(msg,this_object(),ob);
  return 1;
 }

 if(arg!="agree"&&arg!="disagree")
 return notify_fail("����ȷ�ش����⡣\n");

 if(arg=="disagree"){
   ob->delete_temp("try_bai_buchi_actoin2");
   ob->set("mud_flags/try_bai_buchi_time",time());
   msg="$N��$n̾������������һ�����Ե����\n";
   message_vision(msg,this_object(),ob);
   return 1;
 }

 msg=ob->query_temp("try_bai_buchi_actoin2");
 switch(msg){

  case "exp":
     msg="$N�����ָ��$n̫��Ѩ��ȥ��ɲ�Ǽ�$n����һƬ�հף�Ҳ��û��ս���������\n"+
         "�����İɡ�$N˵�������㲻�����������Ϊʦ���յ��Ը��Ժ�͸���Ϊʦ\n"+
         "ѧϰ�ɡ���\n";
     break;
  case "skill":
     msg="$Nһ������$nͷ���ϣ�$nȫ��һ���ֽ���ԣ��ƺ���Ҳ����ʩչ��ǰ��ѧ���书�ˡ�\n"+
     "$N˵�������㲻�����������Ϊʦ���յ��Ը��Ժ�͸���Ϊʦѧϰ�ɡ���\n";
     break;
  case "gold":
     msg="$N���ֵ�$n�ڴ�����$nȫ���ֽ�ʹ�����ߡ�\n"+
     "$N˵�������㲻�����������Ϊʦ���յ��Ը��Ժ�͸���Ϊʦѧϰ�ɡ���\n";
 }

 message_vision(msg,this_object(),ob);
 ob->delete_temp("try_bai_buchi_actoin2");
 ob->set_temp("try_bai_buchi_ok",1);
 return 1;
}

int do_action3()
{
   object ob;

   ob=this_player();

   if(is_fighting())
   return notify_fail("�Է���æ���أ�");
   if(is_busy())
   return notify_fail("�Է���æ���أ�");

   if(ob->query("perform_quest/fumo")){
     command("say ���Ѿ������˷�ħ�ȷ��ľ��裬�Ժ����Լ�������߰ɣ�");
     return 1;
   }
   if(ob->query("perform_quest/liudao")){
     command("say ���Ѿ������˶ɽ�ָ�ľ��裬���޷����������ž����ģ�");
     return 1;
   }
   if(ob->query("perform_quest/tiangang")){
     command("say ���Ѿ����������ȭ�ľ��裬���޷����������ž����ģ�");
     return 1;
   }
   if(ob->query("perform_quest/pudu")){
     command("say ���Ѿ��������������Ƶľ��裬���޷����������ž����ģ�");
     return 1;
   }

   if(ob->query_skill("fumo-zhangfa",1)<160){
     command("say ��ķ�ħ�ȷ���Ϊ̫���ˣ������޷��������еľ��裡");
     return 1;
   }
   if((int)ob->query("PKS",1)>=5)
	{
		command("say ���������أ�����ô������������ˣ�");
		return 1;
	}
   if(ob->query("bellicosity")>=100){
	  command("say ������ɱ�����أ���������մ��ȷ��ľ����أ�");
	  return 1;
   }

   command("say ��ħ�ȵľ�ѧ�ǻ���һ�У���ֻ����ᣬ�����Դ���\n"+
           "�㵽���µ�һЩ��������ȥ���һ�°ɣ�");
   ob->set_temp("perform_quest/fumo_action1",1);
   return 1;
}
