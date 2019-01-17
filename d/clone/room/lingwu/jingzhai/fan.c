#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string do_quest1();
string do_quest2();
void create()
{
   set_name("�����",({ "fan qinghui","fan" }) );
        set("gender", "Ů��" );
        set("age",42);
   set("long", "���ǴȺ���ի����������ݡ�\n");
       
   set("combat_exp",3500000);
   set("str", 25);
   set("per",25);
   set("max_gin",5000);
   set("max_kee",5000);
   set("max_sen",5000);
   set("max_force",5000);
   set("force",5000);
   set("attitude", "peaceful");
   set_skill("sword",480);
   set_skill("cuff",480);
   set_skill("parry",480);
   set_skill("strike",480);
   set_skill("dodge",480);
   set_skill("finger",480);
   set_skill("literate",480);
   set_skill("force",480);
   set_skill("sekong-jianfa",480);      
   set_skill("xiuluo-zhi",480);
   set_skill("wuwang-jing",500);
   set_skill("qingxin-force",480);
   set_skill("lingyun-shenfa",480);
  
   create_family("�Ⱥ���ի",2,"����");
   set("inquiry",([
      "��Ů":(:do_quest1:),
      "����":(:do_quest2:),
      ]));
   set("class","bonze");
   setup();
   carry_object(__DIR__"daopao")->wear();
   carry_object(__DIR__"changjian")->wield();
  
}

void attempt_apprentice(object ob)
{   
	
	if(ob->query("gender")=="����")
	{
	  command("say ���ǴȺ���ի�����е��ӵģ������һ�����ȥ������Ժ�ɣ�\n");
	  return;
	}
	if(ob->query("family")&&ob->query("family/family_name")=="�Ⱥ���ի"
	  &&ob->query("family/generation")<=2)
	{
	  command("say �⻰�Ӻ�˵��\n");
	  return;
	}
	if(ob->query("kar")<24)
	{
	  command("say �������������ڷ���Ե���㻹��Ͷ���������ɰɣ�\n");
	  return;
	}
	if(ob->query_int()<31)
	{
	  command("say ���ͷ�Բ������������ú�ѧѧ�����ɣ�\n");
	  return;
	 }
       if(ob->query("PKS")>=5){
	  command("say ����������̫�࣬�ҿɲ�Ҫ�����ĵ��ӣ�");
	  return;
	}
	
	if(ob->query("bellicosity")>=100){
	  command("say ������ɱ�����أ�����������ŵ��书��");
	  return;
	}
       if(ob->query_skill("qingxin-force",1)<200)
       {
       	 command("say ����������ƾ�����������������ȥ�����ɣ�\n");
       	 return;
       	}
       	
       	if(ob->query("couple")){
       	command("say ��Ȼ���Ѿ��ɻ���ޣ����ǲ�Ҫ�ݵ��ҵ����°ɣ�\n");
       	return;}
       
       if(ob->query("office_number")<40){
        command("say ��Ĺ�����ô�ͣ��ҿɲ�Ҫ��ô����ĵ��ӣ�\n");
        return;
      }

       if(!ob->query_temp("try_recruit")){
       	command("say �������£�������ң��㻹�Ǻú�����ɣ�\n");
       	ob->set_temp("try_recruit",1);
       	return;}
       	ob->delete_temp("try_recruit");
             
       	command("say �ã��������Ѿ�����ˣ�\n");
	command("say ��,��Ȼ�ܰݵ��ҵ����£�˵��������ܹ����������ļ��!\n");
	command("say ϣ�����Ժ������Ƽ�����Ϊ�����츣��\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "bonze");
}

string do_quest1()
{
  object ob;
  ob=this_player();
  
  if(ob->query("family_lingwu")=="jingzhai")
  return "���Ѿ��Ǳ�����Ů�ˣ�ֱ��ȥ��������ɣ�\n";
  
  if(ob->query_temp("dtsl_fquest_jz/step6")){
    ob->delete_temp("dtsl_fquest_jz");
    ob->set("family_lingwu","jingzhai");
    ob->set("title","��Ů");
    message("vision",HIG"���Ⱥ���ի��:"+query("name")+"ϲ��:ϣ��������Ů"+ob->name()+HIG+
    "������Э������ƽ�����£�ʹ���հ�����ҵ��\n"NOR,users());
    ob->reward_family_point();
   return "��ȥ�Աߵ�����ȥ����ɣ��ܲ��ܽ�ȥ���Ϳ�����컯�ˣ�\n";
  
  }
   
  if(!ob->query_temp("dtsl_fquest_jz/step3"))
  return "�Ƿ��ܳ�Ϊ���ŵ���Ů���������սʤ���ŵ���ʦ������\n";
  ob->delete_temp("dtsl_fquest_jz/step3");
  ob->set_temp("dtsl_fquest_jz/step4",1);
  return "�ðɣ����Ϊ������Ů����ҪΪ���°�����һ���²ſ��ԡ�\n";
}

string do_quest2()
{
  object ob;
  object letter;
  ob=this_player();
  if(!ob->query_temp("dtsl_fquest_jz/step4"))
  return "��˵��ʲô���ҿ�һ��Ҳ����������\n";
  ob->delete_temp("dtsl_fquest_jz/step4");
  ob->set_temp("dtsl_fquest_jz/step5",1);
  letter=new(__DIR__"letter");
  letter->move(ob);
  return "�ðɣ���ȥ����������͸�(song)δ�����µ�������Ȼ����������ɣ�\n";
}
