
inherit F_MASTER;
inherit NPC;
void create()
{
   set_name("������",({ "dun yugu","dun" }) );
        set("gender", "����" );

        set("age", 42);
   set("long", "�����Ǳ����ĵܵܣ����ͻ�ʴ󺹵����Σ�\n");

   set("combat_exp",1000000);
   set("str", 25);
   set("per", 22);
   set("attitude", "peaceful");
   set_skill("unarmed",180);
   set_skill("dodge",180);
   set_skill("parry",180);
   set_skill("force",180);
   set_skill("sword",180);
   set_skill("strike",180);
   set_skill("cuff",180);
   set_skill("yanyang-dafa",180);

   // set_skill("pojun-quan",180);
   set_skill("tianlang-dao",180);
   set("dodge",({"tianmo-huanzong"}));
   set("force_skill",({"yanyang-dafa"}));
   set("blade",({"tianlang-dao"}));
   set("hand",({"pojun-quan"}));
   set("gin",3000);
   set("max_gin",3000);
   set("kee",3000);
   set("max_kee",3000);
   set("sen",3000);
   set("max_sen",3000);
   set("force",4000);
   set("max_force",4000);
   create_family("ͻ��",2,"��ʿ");
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
   carry_object(__DIR__"obj/gangdao")->wield();

}
void attempt_apprentice(object ob)
{
	if(ob->query("family"))
	if(ob->query("family/family_name")=="ͻ��")
	if((int)ob->query("family/generation",1)<2)
	{   if(ob->query("gender")=="����")
		tell_object(ob,"��������æЦ��:ʦ�����ǻῪ��Ц!\n");
	    else tell_object(ob,"��������æЦ��:ʦ�����ǻῪ��Ц!\n");
		return;
	}
	if (ob->query_skill("pojun-quan", 1) < 120)
	{
		tell_object(ob,"��������Ц��:����ͻ��������ۣ�����书����ȥ������ѧѧ��!\n");
		return;
	}
	command("say ��,ֻҪ��ͻ�ʺúø�,��֤�㽫����Ϊһ������!\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "tujue2");
}
