
inherit F_MASTER;
inherit NPC;
void create()
{
   set_name("������",({ "kang qiaoli","kang" }) );
        set("gender", "����" );
		
        set("age", 42);
   set("long", "������ͻ������ԭ�Ķ�Ŀ��\n");
       
   set("combat_exp",300000);
   set("str", 25);
   set("per", 22);
   set("attitude", "peaceful");
   set_skill("unarmed",120);
   set_skill("dodge",120);
   set_skill("parry",120);
   set_skill("force",120);
   set_skill("sword",120);
   set_skill("strike",120);
   set_skill("cuff",120);
   set_skill("yanyang-dafa",120);
   
   set_skill("pojun-quan",180);
   set_skill("tianlang-dao",180);
   set("dodge",({"tianmo-huanzong"}));
   set("force_skill",({"yanyang-dafa"}));
   set("blade",({"tianlang-dao"}));
   set("hand",({"pojun-quan"}));
   set("gin",1000);
   set("max_gin",1000);
   set("kee",1000);
   set("max_kee",1000);
   set("sen",1000);
   set("max_sen",1000);
   set("force",1500);
   set("max_force",1500);
   create_family("ͻ��",5,"��ʿ");
   set("class","yin1");
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
   carry_object(__DIR__"obj/gangdao")->wield();
  
}
void attempt_apprentice(object ob)
{   
	if(ob->query("family"))
	if(ob->query("family/family_name")=="ͻ��")
	if((int)ob->query("family/generation",1)<5)
	{   if(ob->query("gender")=="����")
		tell_object(ob,"��������æЦ��:ʦ�����ǻῪ��Ц!\n");
	    else tell_object(ob,"��������æЦ��:ʦ�����ǻῪ��Ц!\n");
		return;
	}
	command("say ��,ϣ������ͻ�ʺúø�,�Ա���ͻ�ʽ���һͳ����!\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "tujue1");
}

