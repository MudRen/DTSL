
inherit F_MASTER;
inherit NPC;
#include <ansi.h>

int do_action1();
int do_action2();

void create()
{
   set_name("����",({ "shang ming","shang","ming" }) );
   set("gender", "����" );
   set("nickname","��˧");
   set("age", 28);
   set("long", "���Ƕ������˳ơ���˧����������\n");
       
   set("combat_exp",600000);
   set_skill("dodge",150);
   set_skill("parry",150);
   set_skill("force",150);
   set_skill("hammer",150);
  
   set_skill("dongming-xinfa",150);
   set_skill("bihai-force",150);
   set_skill("leiting-chuifa",150);
   set_skill("nishang-piaoming",150);
   set_skill("literate",150);
   
   set("max_gin",2000);
   set("max_sen",2000);
   set("max_kee",2000);
   set("force",2000);
   set("max_force",2000);
   create_family("������",5,"����");
   
   set("inquiry",([
     "���鹫��":(:do_action1:),
     "�ֺù���":(:do_action2:),
     ]));
   
   setup();
   carry_object(__DIR__"obj/hammer")->wield();
  
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
	
	if(ob->query("gender")=="Ů��"){
	
	command("say �Ҳ���Ů���ӵģ����������Ͷ�뱾�ɣ�ȥ�ҵ�ϼ�ɣ�\n");
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
        
        if(!ob->query_temp("bai_shangming/ok")){
          command("say ������Ϊ���������أ����ȵȻ�ɣ�");
          return;
        }
        
        lev=ob->query_skill("strike",1);
        lev=lev*lev/(lev+100);
        ob->party_reward_skill("hammer",lev);
        tell_object(ob,HIY"��ӻ����Ʒ������Ե��˻���������\n"NOR);
		
	command("say �����е����ڶ����������䵱�������Σ���ҲҪ�ú�ѧϰ���գ�\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "dongming2");
}

int do_action1()
{
   object ob;
   
   ob=this_player();
   
   if(ob->query("family"))
   if(ob->query("family/family_name")=="������")
   if((int)ob->query("family/generation",1)<=6){   
       command("say ���������Ĵ����Σ���ʶ�˲������ˡ�\n");
       return 1;
   }
   if(!ob->query("family")){   
       command("say ���������Ĵ����Σ���ʶ�˲������ˡ�\n");
       return 1;
   }
   if(ob->query("family"))
   if(ob->query("family/family_name")!="������"){   
       command("say ���������Ĵ����Σ���ʶ�˲������ˡ�\n");
       return 1;
   }
   if(ob->query_skill("bihai-force",1)<100){   
       command("say ���������Ĵ����Σ���ʶ�˲������ˡ�\n");
       return 1;
   }
   
   ob->set_temp("bai_shangming/action1",1);
   command("say ���������Ĵ����Σ���ʶ�˲������ˡ�\n");
   command("sigh");
   return 1;
}

int do_action2()
{
   object ob;
   
   ob=this_player();
   
   if(!ob->query_temp("bai_shangming/action1")){
      command("say ���������ж�����ô�����������£�\n");
       return 1;
   }
   if(ob->query("family"))
   if(ob->query("family/family_name")=="������")
   if((int)ob->query("family/generation",1)<=6){   
       command("say ���������ж�����ô�����������£�\n");
       return 1;
   }
   if(!ob->query("family")){   
       command("say ���������ж�����ô�����������£�\n");
       return 1;
   }
   if(ob->query("family"))
   if(ob->query("family/family_name")!="������"){   
       command("say ���������ж�����ô�����������£�\n");
       return 1;
   }
   if(ob->query_skill("bihai-force",1)<100){   
       command("say ���������ж�����ô�����������£�\n");
       return 1;
   }
   
   ob->set_temp("bai_shangming/ok",1);
   ob->delete_temp("bai_shangming/action1");
   command("say ����ôû���뵽�ء���������ŮϵΪ���������书���������������ϵ���������������ߡ�\n");
   return 1;
}