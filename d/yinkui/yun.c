
inherit F_MASTER;
inherit NPC;
void create()
{
   set_name("�Ƴ���",({ "yun zhanglao","yun" }) );
        set("gender", "����" );
		
        set("age", 42);
   set("long", "�����������ɵ��Ƴ���,����а������˵������һ����\n");
       
   set("combat_exp",300000);
   set("str", 25);
   set("per", 22);
   set("attitude", "peaceful");
   set_skill("unarmed",120);
   set_skill("dodge",120);
   set_skill("parry",120);
   set_skill("force",150);
   set_skill("sword",150);
   set_skill("strike",150);
   set_skill("cuff",150);
   set_skill("jiutian-huanzhang",150);
   set_skill("literate",150);
   set_skill("tianmo-dafa",150);
   set_skill("tianmo-jianfa",130);
   set_skill("tianmo-huanzong",130);
   set_skill("tianmo-dai",120);
   set("dodge",({"tianmo-huanzong"}));
   set("force_skill",({"tianmo-dafa"}));
   set("sword",({"tianmo-jianfa"}));
   set("hand",({"tianmo-dai","jiutian-huanzhang"}));
   set("gin",1000);
   set("max_gin",1000);
   set("kee",1000);
   set("max_kee",1000);
   set("sen",1000);
   set("max_sen",1000);
   set("force",1500);
   set("max_force",1500);
   create_family("������",5,"����");
   set("class","yin1");
   setup();
   carry_object(__DIR__"obj/caiyi")->wear();
   carry_object(__DIR__"obj/changjian")->wield();
  
}
void attempt_apprentice(object ob)
{   
	if(ob->query("family"))
	if(ob->query("family/family_name")=="������")
	if((int)ob->query("family/generation",1)<5)
	{   if(ob->query("gender")=="����")
		tell_object(ob,"�Ƴ�����æЦ��:ʦ�����ǻῪ��Ц!\n");
	    else tell_object(ob,"�Ƴ�����æЦ��:ʦ�����ǻῪ��Ц!\n");
		return;
	}
	if(ob->query("shen")>0)
	{
		tell_object(ob,"�Ƴ�����Ц��:��������������ʿ,���������ɿ��ǲ�Ҫ!\n");
		return;
	}
	command("say ��,ֻҪ�������ɺúø�,��֤�㽫��Х������!\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "yin1");
}

