
inherit NPC;
inherit F_MASTER;

#include <ansi.h>
#include "bonze.c"
int do_action2();
int do_action1();
int do_action3();
int do_answer(string arg);

void create()
{
 
   set_name("����",({ "bu ju","bu","ju"}));
        set("gender", "����" );
        set("age", 32);
   set("long", "���Ǿ�����Ժ���Ĵ󻤷����֮һ��\n");
   set("class","bonze"); 
   set("combat_exp", 600000);
   set("str", 28);
   set_skill("dodge",150);
   set_skill("parry",150);
   set_skill("finger",150);
   set_skill("force",150);
   
   set_skill("dujie-zhi",150);
   set_skill("bikouchan",150);
   set_skill("chanzong-fofa",160);
   set_skill("literate",160);
   set_skill("wuxiang-shengong",150);
   set_skill("lianhua-step",150);
   
   set("max_gin",2000);
   set("max_kee",2000);
   set("max_sen",2000);
   set("max_force",2000);
   set("force",2000);
   
   set("inquiry",([
       "����":(:do_action1:),
       "����":(:do_action2:),
       "�ɽ�ָ":(:do_action3:),
       ]));
   set("perform_quest/liudao",1);
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
	if(ob->query_temp("try_bai_buju_fail")){
	  command("say ����ɮ����Ҳ�ܵ����������γ�ħ������������ͽ���Ҳ�Ҫ��");
	  return;
	}
	if(!ob->query_temp("try_bai_buju_ok")){
	  command("say ��û�����ҵĿ��飬�Ҳ�������Ϊͽ�ġ�");
	  return;
	}
	
	lev=ob->query_skill("cuff",1);
	lev=lev*lev/(lev+100);
	ob->party_reward_skill("finger",lev);
	tell_object(ob,HIY"\n��ӻ���ȭ�����������һЩ����ָ����\n\n"NOR);
	
	
	command("say �����ӷ�ϣ�����Ժ��ܹ⴫�𷨣��ն�������\n");
	command("recruit "+ob->query("id"));
	ob->delete_temp("try_bai_buju_ok");
	ob->delete_temp("try_bai_buju_fail");
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "bonze");
     ob->set("chanyuan_skill","dujie-zhi");
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
	
	if(time()-ob->query("mud_flags/try_bai_buju_time")<300){
	  command("say ���������ĵ�С������ʱ��������㣡");
	  return 1;
	}
	
	msg="$N��$n˵����������ҵ��������ü�ɮ�¹����ɣ���\n";
	message_vision(msg,this_object(),ob);
	ob->delete("mud_flags/try_bai_buju_time");
	ob->set_temp("try_bai_buju_actoin1",1);
	return 1;
}

int accept_object(object ob,object obj)
{
   if(obj->query("owner_id")!=ob->query("id"))
   return 0;
   ob->set_temp("try_bai_buju_ok",1);
   ob->delete_temp("try_bai_buju_fail");
   ob->delete_temp("try_bai_buju_actoin1");
   command("say ����Σ���壬�պ��ǳ�ħ�����������ѡ����");
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
   
   if(ob->query("perform_quest/liudao")){
     command("say ���Ѿ������˶ɽ�ָ�ľ��裬�Ժ����Լ�������߰ɣ�");
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
   if(ob->query("perform_quest/fumo")){
     command("say ���Ѿ������˷�ħ�ȷ��ľ��裬���޷����������ž����ģ�");
     return 1;
   }
   if(ob->query_skill("dujie-zhi",1)<160){
     command("say ��Ķɽ�ָ��Ϊ̫���ˣ������޷��������еľ��裡");
     return 1;
   }
   if((int)ob->query("PKS",1)>=5)
	{
		command("say ���������أ�����ô������������ˣ�");
		return 1;
	}
   if(ob->query("bellicosity")>=100){
	  command("say ������ɱ�����أ���������մ�ָ���ľ����أ�");
	  return 1;
   }
   
   command("say �ðɣ������ھ͸�����ɽ�ָ���������裡");
   fight_ob(ob);
   remove_call_out("do_fight");
   call_out("do_fight",5,ob);
   return 1;
}

int do_fight(object ob)
{
  if(!ob) return 1;
  if(!living(ob)) return 1;
  if(!is_fighting(ob)){
     command("say ��Ĺ����а����ٻ�ȥ��ϰһ�°ɣ�");
     return 1;
  }
  command("say С�Ŀ���ϸ�ˣ���\n\n");
  set("max_pot",282);
  command("execute wuyu");
  command("perform liudao");
  call_out("do_fight2",6,ob);
  return 1;
}

int do_fight2(object ob)
{
  string msg;
  
  if(!ob) return 1;
  if(!living(ob)) return 1;
  if(!is_fighting(ob)){
     command("say ��Ĺ����а����ٻ�ȥ��ϰһ�°ɣ�");
     return 1;
  }
  remove_enemy(ob);
  ob->remove_enemy(this_object());
  msg="\n\n$N΢΢һЦ������ᵽʲô����\n"+
      "$n��˼һ�ᣬͻȻһЦ����ؿ���ͷ��ллʦ������\n\n";
  ob->set("perform_quest/liudao",1);
  message_vision(msg,this_object(),ob);
  return 1;
}