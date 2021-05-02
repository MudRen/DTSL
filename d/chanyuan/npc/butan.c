
inherit NPC;
inherit F_MASTER;

#include <ansi.h>
#include <job_money.h>
#include "bonze.h"

int do_action2();
int do_action1();
int do_action3();
int do_answer(string arg);

string *dirs=({
"/d/hengshan","/d/taishan","/d/wuyishan","/d/huashan",
});

void create()
{

   set_name("��̰",({ "bu tan","bu","tan"}));
        set("gender", "����" );
        set("age", 32);
   set("long", "���Ǿ�����Ժ���Ĵ󻤷����֮һ��\n");
   set("class","bonze");
   set("combat_exp", 600000);
   set("str", 28);
   set_skill("dodge",150);
   set_skill("parry",150);
   set_skill("cuff",150);
   set_skill("force",150);

   set_skill("tiangang-quan",150);
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
       "���ȭ":(:do_action3:),
       ]));
   set("perform_quest/tiangang",1);
   create_family("������Ժ",5,"����");
   setup();

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
	if(!ob->query_temp("try_bai_butan_ok")){
	  command("say ��û�����ҵĿ��飬�Ҳ�������Ϊͽ�ġ�");
	  return;
	}

	lev=ob->query_skill("cuff",1);
	lev=lev*lev/(lev+100);
	ob->party_reward_skill("cuff",lev);
	tell_object(ob,HIY"\n��Ի���ȭ�������µ���ʶ��\n\n"NOR);

	command("say �����ӷ�ϣ�����Ժ��ܹ⴫�𷨣��ն�������\n");
	command("recruit "+ob->query("id"));
	ob->delete_temp("try_bai_buchi_ok");
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
    ob->set("class", "bonze");
    ob->set("chanyuan_skill","tiangang-quan");
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
	if(ob->query_temp("try_bai_butan_actoin2")){
	  command("say �ҿɲ�ϲ��̰�Ƶĵ��ӣ�");
	  return 1;
	}

	msg="$N��$n˵��������ľ���̫�ã���ȥ��Ϣһ�°ɣ���\n";
	message_vision(msg,this_object(),ob);
	ob->set_temp("try_bai_butan_actoin1",1);
	return 1;
}

int accept_object(object ob,object obj)
{
   if(!ob->query_temp("try_bai_butan_actoin2"))
   return 0;
   if(!obj->query("bai_butan_quest"))
   return 0;
   command("say �㲻̰�Ʊ��������ҵ���Ը��");
   ob->delete_temp("try_bai_butan_actoin2");
   ob->set_temp("try_bai_butan_ok",1);
   return 1;
}

int do_action3()
{
   object ob,target;

   ob=this_player();

   if(is_fighting())
   return notify_fail("�Է���æ���أ�");
   if(is_busy())
   return notify_fail("�Է���æ���أ�");

   if(ob->query("perform_quest/tiangang")){
     command("say ���Ѿ����������ȭ�ľ��裬�Ժ����Լ�������߰ɣ�");
     return 1;
   }
   if(ob->query("perform_quest/pudu")){
     command("say ���Ѿ��������������Ƶľ��裬���޷����������ž����ģ�");
     return 1;
   }
   if(ob->query("perform_quest/fumo")){
     command("say ���Ѿ������˷�ħ�ȷ��ľ��裬���޷����������ž����ģ�");
     return 1;
   }
   if(ob->query("perform_quest/liudao")){
     command("say ���Ѿ������˶ɽ�ָ�ľ��裬���޷����������ž����ģ�");
     return 1;
   }

   if(ob->query_skill("tiangang-quan",1)<160){
     command("say ������ȭ��Ϊ̫���ˣ������޷��������еľ��裡");
     return 1;
   }
   if((int)ob->query("PKS",1)>=5)
	{
		command("say ���������أ�����ô������������ˣ�");
		return 1;
	}
   if(ob->query("bellicosity")>=100){
	  command("say ������ɱ�����أ���������մ�ȭ���ľ����أ�");
	  return 1;
   }

   command("say ���и����ӣ�ֻ���书�����Է𷨣��߻���ħ����ȥ����������(jiangjing)��");
   target=new(__DIR__"dizi1");
   target->set("target_id",ob->query("id"));
   target->set("last",time());
   if(!random_place(target,dirs)){
     command("say ������ܵ�����ȥ���أ���������... ...");
     return 1;
   }
   if(!environment(target)){
     command("say ������ܵ�����ȥ���أ���������... ...");
     return 1;
   }
   command("say ��˵������ܵ���"+MISC_D->find_place(environment(target))+"����ȥ���Կ��ɣ�");
   ob->add_temp_array("job_temp_killer",target);
   return 1;
}
