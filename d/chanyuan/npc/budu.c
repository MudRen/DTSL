
inherit NPC;
inherit F_MASTER;
void create()
{
   set_name("����",({ "bu du","bu","du"}));
        set("gender", "����" );
        set("age", 32);
   set("long", "���Ǿ�����Ժ�ĸ�ɮ֮һ��\n");
   set("class","bonze");
   set("combat_exp", 200000);
   set("str", 28);
   set("per", 22);
   set("attitude", "peaceful");
   set_skill("dodge",100);
   set_skill("parry",100);
   set_skill("staff",100);
   set_skill("tiangang-quan",100);
   set_skill("cuff",100);
   set_skill("literate",100);
   set_skill("finger",100);
   set_skill("liuyun",100);
   set_skill("force",100);
   set_skill("blade",100);
   set_skill("chanzong-fofa",100);
   set_skill("bikouchan",100);
   // set_skill("jinguang-daofa",100);
   // set_skill("wuxiang-zhangfa",100);
   set("staff",({"wuxiang-zhangfa"}));
   set("dodge",({"liuyun"}));
   set("gin",1000);
   set("max_gin",1000);
   set("kee",800);
   set("max_kee",800);
   set("sen",800);
   set("max_sen",800);
   set("force",1000);
   set("max_force",1000);
   create_family("������Ժ",6,"ɮ��");
   setup();
   carry_object(__DIR__"obj/sengyi")->wear();
   carry_object(__DIR__"obj/staff")->wield();

}

void attempt_apprentice(object ob)
{
	if(ob->query("family"))
	if(ob->query("family/family_name")=="������Ժ")
	if((int)ob->query("family/generation",1)<6)
	{   if(ob->query("gender")=="����")
		tell_object(ob,"������æЦ��:ʦ�����ǻῪ��Ц!\n");

	}
	if(ob->query("gender")=="Ů��")
	{
		tell_object(ob,"����Ц��:������Ժֻ���е��ӵ�,ʩ�����һ�����,����ȥ�Ⱥ���ի.\n");
		return;
	}
	if((int)ob->query("PKS",1)>=5)
	{
		tell_object(ob,"����˫�ֺ�ʮ��:ʩ��,���ɱ��̫��,����ô������?\n");
		return;
	}

	command("say �����ӷ�!ϣ��ʩ������ܳ������˵Ŀ���,��Ϊһ����ɮ,����!\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "bonze");
}
