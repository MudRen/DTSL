
inherit F_MASTER;
inherit NPC;

#include <ansi.h>

void create()
{
   set_name("�����",({ "bai qinger","bai" }) );
        set("gender", "Ů��" );
        set("age", 23);
        set("per",26);
   set("long", "����Ǯ������谮��С檣�Ҳ����������\n"+
               "һ����������֡�\n");
       
   set("combat_exp",600000);
   set_skill("dodge",150);
   set_skill("parry",150);
   set_skill("force",150);
   set_skill("cuff",150);
   set_skill("linglong-yuquan",150);
   set_skill("literate",150);
   set_skill("tianmo-dafa",150);
   set_skill("tianmo-jue",150);
   set_skill("tianmo-huanzong",150);
   
   set("max_gin",2000);
   set("max_kee",2000);
   set("max_sen",2000);
   set("force",2000);
   set("max_force",2000);
   create_family("������",5,"����");
   setup();
  
}
void attempt_apprentice(object ob)
{
	int lev;
	
	if(ob->query("family"))
	if(ob->query("family/family_name")=="������")
	if((int)ob->query("family/generation",1)<=5)
	{   
	   command("say �˻��Ӻ�˵��\n");
	   return;
	}
	if(ob->query("gender")=="����"){
	
	command("say �Ҳ����е��ӵģ����������Ͷ�뱾�ɣ�ȥ����ʿ��ɣ�\n");
	return;
        }
        if(ob->query_skill("tianmo-dafa",1)<100){
        command("say �����ħ����Ϊ������������ȥ��ϰһ���ٰ���Ϊʦ�ɣ�\n");
        return;
        }
        
        if(ob->query("class")!="yin1"){
          command("say ��û�С�ն��Ե�������������Ϊͽ��");
          return;
        }
        
        if(ob->query("office_number")<30){
        command("say ��Ĺ�����ô�ͣ��ҿɲ�Ҫ��ô����ĵ��ӣ�\n");
        return;
        }
        if(ob->query_per()<25){
	 command("hmm1");
	 command("say ������Ӳ���Ư�����ҿɲ��������ĵ��ӣ�\n");
	 return;
	}
	
	lev=ob->query_skill("sword",1);
        lev=lev*lev/(lev+100);
        ob->party_reward_skill("cuff",lev);
        tell_object(ob,HIY"��ӻ������������Ե��˻���ȭ����\n"NOR);       
	command("say �ã�ϣ���㽫����һͳħ��������������������\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "yin2");
}

