
inherit F_MASTER;
inherit NPC;
#include <ansi.h>
void create()
{
   set_name("����",({ "shan qing","shan","qing" }) );
   set("gender", "Ů��" );
   set("nickname","��������");
   set("age", 24);
   set("long", "���Ƕ����ɵ��Ĵ󻤷�����֮һ��\n");
       
   set("combat_exp",600000);
   set("per", 25);
   set_skill("dodge",150);
   set_skill("parry",150);
   set_skill("force",150);
   set_skill("sword",150);
  
   set_skill("dongming-xinfa",150);
   set_skill("bihai-force",150);
   set_skill("piaomeng-jianfa",150);
   set_skill("nishang-piaoming",150);
   set_skill("strike",150);
   set_skill("literate",150);
   
   set("max_gin",2000);
   set("max_sen",2000);
   set("max_kee",2000);
   set("force",2000);
   set("max_force",2000);
   create_family("������",5,"����");
   
   setup();
   carry_object(__DIR__"obj/caiyi")->wear();
   carry_object(__DIR__"obj/changjian")->wield();
  
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
	
	command("say �Ҳ����е��ӵģ����������Ͷ�뱾�ɣ�ȥ�����ʰɣ�\n");
	return;
        }
        
        if(ob->query_skill("bihai-force",1)<100){
          command("say �̺��������Ƕ����ɵĸ������㲻�ú�ѧ����ô������Ϊ�����أ�");
          return;
        }
        if(ob->query("office_number")<30){
        command("say ��Ĺ�����ô�ͣ��ҿɲ�Ҫ��ô����ĵ��ӣ�\n");
        return;
        }        
	
	if(!ob->query("menpai/dongming2")){
		lev=ob->query_skill("strike",1);
    lev=lev*lev/(lev+100);
    ob->party_reward_skill("sword",lev);
    tell_object(ob,HIY"��ӻ����Ʒ������Ե��˻���������\n"NOR);
		
	  ob->set("menpai/dongming2",1);

	}
	command("say ����ս�ҷ������Ƕ���δ�����������⣬�����Ҫ�ú���ϰ���գ������������ɣ�\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "dongming2");
}