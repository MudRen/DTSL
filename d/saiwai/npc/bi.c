
inherit F_MASTER;
inherit NPC;
void create()
{
   set_name("����",({ "bi xuan","bi" }) );
        set("gender", "����" );
		
        set("age", 42);
   set("long", "���������������������������ʦ֮һ\n");
       
   set("combat_exp",5000000);
   set("str", 30);
   set("per", 22);
   set("attitude", "peaceful");
   set_skill("unarmed",250);
   set_skill("dodge",250);
   set_skill("parry",250);
   set_skill("force",250);
   set_skill("sword",250);
   set_skill("strike",250);
   set_skill("cuff",250);
   set_skill("yanyang-dafa",250);
   
   set_skill("pojun-quan",250);
   set_skill("yanyang-quan",250);
   set_skill("yuehen-qiang",250);
   set_skill("tianlang-dao",250);
   set("dodge",({"tianmo-huanzong"}));
   set("force_skill",({"yanyang-dafa"}));
   set("blade",({"tianlang-dao"}));
   set("hand",({"pojun-quan","yanyang-quan"}));
   set("gin",4000);
   set("max_gin",4000);
   set("kee",4000);
   set("max_kee",4000);
   set("sen",4000);
   set("max_sen",4000);
   set("force",5000);
   set("max_force",5000);
   set("jiali",250);
   create_family("ͻ��",1,"����");
   set("class","yin1");
   setup();
   carry_object(__DIR__"obj/cloth")->wear();  
}
void attempt_apprentice(object ob)
{   
	if (ob->query_skill("pojun-quan", 1) < 180)
	{
		tell_object(ob,"������Ц��:����ͻ��������ۣ�����书��.........!\n");
		return;
	}
	command("say ��,ֻҪ��ͻ�ʺúø�,��֤���ݺ�����!\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "tujue3");
}

