
inherit F_MASTER;
inherit NPC;
#include <ansi.h>

void create()
{
   set_name("�й�",({ "shang gong","shang","gong" }) );
   set("gender", "����" );
   set("age", 42);
   set("long", "���Ƕ�������ơ��й�������ƽ��\n");
       
    set("combat_exp",3500000);
    set_skill("dodge",300);
    set_skill("parry",300);
    set_skill("force",300);
    set_skill("hammer",300);
    set_skill("strike",300);
   set_skill("youyue-zhangfa",300);
   set_skill("strike",300);
    set_skill("dongming-xinfa",300);
    set_skill("bihai-force",300);
    set_skill("leiting-chuifa",300);
    set_skill("nishang-piaoming",300);
    set_skill("literate",300);
   // set_skill("bencao-shuli",300);

    set("perform_quest/pili",1);
    set("apply_points",2000);
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
        (: command("perform pili") :),
        (: command("exert shui") :),
        (: command("exert huo") :),
    }));
    set("max_gin",5000);
    set("max_sen",6000);
    set("max_kee",7000);
    set("max_force",9000);
    set("force",9000);
   create_family("������",3,"����");
      
   setup();
    carry_object("/obj/cloth/mandongming3")->wear();
   carry_object(__DIR__"obj/hammer")->wield();
  
}

void attempt_apprentice(object ob)
{   
	int lev;
	
	if(ob->query("family"))
	if(ob->query("family/family_name")=="������")
	if((int)ob->query("family/generation",1)<=3)
	{   
	   command("say �˻��Ӻ�˵��\n");
	   return;
	}
	
	if(ob->query("gender")=="Ů��"){
	
	command("say �Ҳ���Ů���ӵģ����������Ͷ�뱾�ɣ�ȥ�ҵ�ϼ�ɣ�\n");
	return;
        }
        
        if(ob->query_skill("bihai-force",1)<150){
          command("say �̺��������Ƕ����ɵĸ������㲻�ú�ѧ����ô������Ϊ�����أ�");
          return;
        }
        if(ob->query("office_number")<60){
        command("say ��Ĺ�����ô�ͣ��ҿɲ�Ҫ��ô����ĵ��ӣ�\n");
        return;
        }
               
	command("say ����ս�ҷ������Ƕ���δ�����������⣬�����Ҫ�ú���ϰ���գ������������ɣ�\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "dongming3");
}

