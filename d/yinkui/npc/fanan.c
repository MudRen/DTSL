
inherit F_MASTER;
inherit NPC;
void create()
{
   set_name("����",({ "fa nan","fa","nan" }) );
        set("gender", "����" );
		
        set("age", 34);
   set("long", "�������˳ơ���ɮ���ķ��ѡ�\n");
       
   set("combat_exp",300000);
   set("per",4);
  
   set_skill("dodge",100);
   set_skill("parry",100);
   set_skill("force",100);
   set_skill("strike",100);
   set_skill("cuff",100);
   
   set_skill("jiutian-huanzhang",100);
   set_skill("literate",100);
   set_skill("tianmo-dafa",100);
   set_skill("tianmo-huanzong",100);
  
   set("max_gin",1000);
   set("max_kee",1000);
   set("max_sen",1000);
   set("force",1000);
   set("max_force",1000);
   create_family("������",7,"����");
   set("class","yin1");
   setup();
   
}
void attempt_apprentice(object ob)
{   
	if(ob->query("family"))
	if(ob->query("family/family_name")=="������")
	if((int)ob->query("family/generation",1)<=7)
	{   
	   command("say �˻��Ӻ�˵��\n");
	   return;
	}
	
	if(ob->query("gender")=="Ů��"){
	
	command("say �Ҳ���Ů���ӵģ����������Ͷ�뱾�ɣ�ȥ�ҡ����ᡱ����ɣ�\n");
	return;
	}
	
	command("say �ã�ϣ���㽫����һͳħ��������������������\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "yin1");
}

