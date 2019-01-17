
inherit NPC;
inherit F_MASTER;
#include <ansi.h>

int do_action1();

void create()
{
   set_name("����",({ "song zhi","song","zhi" }) );
   set("gender", "����" );
   set("nickname",HIC"�ؽ�"NOR);
   set("age", 48);
   set("long", "�������μұ��˳ơ��ؽ��������ǡ�\n");
       
   set("combat_exp",1500000);
   set("str", 28);
   set("per", 25);
   
   set_skill("sword",200);
   set_skill("dodge",200);
   set_skill("parry",200);
   set_skill("force",200);
   
   set_skill("dijian-jue",200);   
   set_skill("anxiang-fuying",200);
   set_skill("tiangang-sanjue",200);
   set_skill("wangdao-jue",200);
   set_skill("literate",200);
  
   set("max_gin",3000);
   set("max_kee",3000);
   set("max_sen",3000);
   set("force",3000);
   set("max_force",3000);
   
   set("perform_quest/ditian",1);
   
   create_family("�μұ�",3,"����");
   set("shili",([
      "name":"songjia_b",
      ]));
   set("inquiry",([
      "������":(:do_action1:),
   
   ]));
   setup();
   carry_object(__DIR__"obj/chouyi")->wear();
   carry_object(__DIR__"obj/changjian")->wield();
  
}

void attempt_apprentice(object ob)
{   
	int lev;
	
	if(ob->query("family"))
	if(ob->query("family/family_name")=="�μұ�")
	if((int)ob->query("family/generation",1)<=3)
	{   
	   command("say �˻��Ӻ�˵��\n");
	   return;
	}
	
        if(ob->query_skill("tiangang-sanjue",1)<150){
        command("say ������������Ϊ̫���ˣ��Ҳ��������ĵ��ӣ�");
        return;
        }
	if(ob->query("office_number")<50){
        command("say ��Ĺ�����ô�ͣ��μұ��ɲ�Ҫ��ô����ĵ��ӣ�\n");
        return;
        }
	if(ob->query("deposit")<500000){
         command("say �����μұ�������һ�󷧣�������ô�������Ƶ����ҿɲ�Ҫ��");
         return;
        }
        if(ob->query("char_lev/bai_songque_fail")){
          lev=ob->query_skill("blade",1);
          ob->set_skill("sword",lev/3);
          tell_object(ob,query("name")+"������Ȼ�㲻��ѧ�����Ҿ�ָ���㼸�н����ɣ�\n");
          tell_object(ob,"�������Щ����������\n");
        }
        if(!ob->query("menpai/songjia3")){         
          ob->set("menpai/songjia3",1);
	}
	command("say ���ǳ���������ǰ�ˣ�ϣ���������μұ��ư����£�\n"+
	        "�μұ��Ľ����Է���Ϊ���������˵У����Ҫ�ú�ѧϰ��");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "song3");
}

int do_action1()
{
  object ob;
  
  ob=this_player();
  
  if(!ob->query("perform_quest/bajue")){
    command("say ƾ����������������������£�");
    return 1;
  }
  if(ob->query("dtsl_quest_ssbp_help_ok")){
    command("say ���Ѿ�����һ���ˣ��Ͳ�Ҫ��ǿ�ˡ�\n");
    return 1;
  }
  if(ob->query("dtsl_quest_ssbp_ok")){
    command("say ��������ɢ�ְ��ˣ�����˵���ȫ���Ը������档");
    return 1;
  }
  
  ob->set_temp("help_ssbp_action1",1);
  
  command("say �������Ǻ���ͳһ���ĸ��󻼡��л����ɱ������");
  
  return 1;
}