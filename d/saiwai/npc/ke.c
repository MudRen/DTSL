
inherit F_MASTER;
inherit NPC;
void create()
{
   set_name("��־��",({ "ke zhida","ke" }) );
        set("gender", "����" );
		
        set("age", 42);
   set("combat_exp",1000000);
   set("str", 25);
   set("per", 22);
   set("attitude", "peaceful");
   set_skill("unarmed",200);
   set_skill("dodge",200);
   set_skill("parry",200);
   set_skill("force",200);
   set_skill("sword",200);
   set_skill("strike",200);
   set_skill("cuff",200);
   set_skill("yanyang-dafa",200);
   
   set_skill("pojun-quan",200);
   set_skill("kuangsha-daofa",200);
   set("dodge",({"tianmo-huanzong"}));
   set("force_skill",({"yanyang-dafa"}));
   set("blade",({"juangsha-daofa"}));
   set("hand",({"pojun-quan"}));
   set("gin",1000);
   set("max_gin",1000);
   set("kee",1000);
   set("max_kee",1000);
   set("sen",1000);
   set("max_sen",1000);
   set("force",1500);
   set("max_force",1500);
   create_family("ͻ��",2,"��ʿ");
   set("class","yin1");
   setup();
   carry_object(__DIR__"obj/cloth")->wear();  
   carry_object(__DIR__"obj/kuangsha-dao")->wear();  
}
void attempt_apprentice(object ob)
{   
	if (present("shuxin",ob))
         {  destruct(present("shuxin",ob));

           command("say �ðɣ���Ȼ" + RANK_D->query_respect(ob) + "�пɺ����ż�����Ϊ��" +
		"��������������Ҿ�������ɡ�\n");}
 else
          {command("say �ҿ�־�����������ͽ!\n");
        return;
        }
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "tujue");
}

