
inherit NPC;
inherit F_MASTER;

#include <ansi.h>
#include "bonze.h"

#define TIME_TICK1 time()*60

int do_action2();
int do_action1();
int do_action3();
int do_answer(string arg);

void create()
{

   set_name("����",({ "bu chen","bu","chen"}));
        set("gender", "����" );
        set("age", 32);
   set("long", "���Ǿ�����Ժ���Ĵ󻤷����֮�ס�\n");
   set("class","bonze");
   set("combat_exp", 600000);
   set("str", 28);
   set_skill("dodge",150);
   set_skill("parry",150);
   set_skill("strike",150);
   set_skill("force",150);

   set_skill("rulai-shenzhang",150);
   set_skill("bikouchan",150);
   set_skill("chanzong-fofa",160);
   set_skill("literate",160);
   set_skill("lianhua-step",150);
   set_skill("wuxiang-shengong",150);

   set("max_gin",2000);
   set("max_kee",2000);
   set("max_sen",2000);
   set("max_force",2000);
   set("force",2000);

   set("inquiry",([
       "����":(:do_action1:),
       "����":(:do_action2:),
       "��������":(:do_action3:),
       ]));
   set("perform_quest/pudu",1);
   create_family("������Ժ",5,"����");
   setup();

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

	if(!ob->query_temp("try_bai_buchen_ok")){
	  command("say ��û�����ҵĿ��飬�Ҳ�������Ϊͽ�ġ�");
	  return;
	}
	command("say ƶɮ����ȥ���Ķ����쳣�򵥵��£��㶼����ŭ����ɵĺܺã�����ƶɮ����֮�⡣");
	lev=ob->query_skill("cuff",1);
	lev=lev*lev/(lev+100);
	ob->party_reward_skill("strike",lev);
	tell_object(ob,HIY"\n��ӻ���ȭ�����������һЩ�����Ʒ���\n\n"NOR);

	command("say �����ӷ�ϣ�����Ժ��ܹ⴫�𷨣��ն�������\n");
	command("recruit "+ob->query("id"));
	ob->delete_temp("try_bai_buchen_ok");
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "bonze");
     ob->set("chanyuan_skill","rulai-shenzhang");
}

int do_action1()
{
   object ob,obj;
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

	msg="$N��$n˵�������������м������֣���ȥ����ɽ�ľ����㡢���϶�����Ů�塢\n"+
	    "�����塢ӭ������ȫ���¡����칬������塢�����塢����ƺ ȥ���������°ɣ�\n";
	message_vision(msg,this_object(),ob);
	obj=new(__DIR__"obj/shuzhong");
	obj->move(ob);
	tell_object(ob,query("name")+"������һ"+obj->query("unit")+obj->query("name")+"��\n");
	ob->set_temp("try_bai_buchen_actoin1",1);
	return 1;
}


int do_action3()
{
   object ob;
   string str1,str2,msg;

   ob=this_player();

   if(is_fighting())
   return notify_fail("�Է���æ���أ�");
   if(is_busy())
   return notify_fail("�Է���æ���أ�");

   if(ob->query("perform_quest/pudu")){
     command("say ���Ѿ��������������Ƶľ��裬�Ժ����Լ�������߰ɣ�");
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
   if(ob->query("perform_quest/tiangang")){
     command("say ���Ѿ����������ȭ�ľ��裬���޷����������ž����ģ�");
     return 1;
   }

   if(ob->query_skill("rulai-shenzhang",1)<160){
     command("say �������������Ϊ̫���ˣ������޷��������еľ��裡");
     return 1;
   }
   if((int)ob->query("PKS",1)>=5)
	{
		command("say ���������أ�����ô������������ˣ�");
		return 1;
	}
   if(ob->query("bellicosity")>=100){
	  command("say ������ɱ�����أ���������մ��Ʒ��ľ����أ�");
	  return 1;
   }

   if(!ob->query_temp("perform_quest_pudu")){
   	command("say ��ѧϰ�������Ƶľ���Ҳ���ԣ��������ڻ�����ʱ������");
   	ob->set_temp("perform_quest_pudu",1);
   	return 1;
   }
  str1=CHINESE_D->chinese_date(TIME_TICK1);
  str2=CHINESE_D->chinese_date((ob->query("birthday") -14*365*24*60)*60);
  if(str1[sizeof(str1)-8..sizeof(str1)]!=str2[sizeof(str2)-8..sizeof(str2)]){
  	command("say ��ѧϰ�������Ƶľ���Ҳ���ԣ��������ڻ�����ʱ������");
  	return 1;
  }
  ob->delete_temp("perform_quest_pudu");
  ob->set("perform_quest/pudu",1);
  command("say �ܺã����ܲ��������������ѧϰ�������Ƶľ����ˣ�");

  msg="\n$N��$n�Ķ��ߵ����˼��䡣\n"+
      "$n��ͷ��˼��һ�ᣬͻȻһЦ����ؿ���ͷ��ллʦ��ָ�㣡\n\n";
  message_vision(msg,this_object(),ob);
  return 1;
}
