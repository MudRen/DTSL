
inherit F_MASTER;
inherit NPC;
void create()
{
   set_name("可志达",({ "ke zhida","ke" }) );
        set("gender", "男性" );

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

  //  set_skill("pojun-quan",200);
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
   create_family("突厥",2,"武士");
   set("class","yin1");
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
   carry_object(__DIR__"obj/kuangsha-dao")->wear();
}
void attempt_apprentice(object ob)
{
	if (present("shuxin",ob))
         {  destruct(present("shuxin",ob));

           command("say 好吧，既然" + RANK_D->query_respect(ob) + "有可汗的信件，难为你" +
		"如此辛苦跑来，我就收下你吧。\n");}
 else
          {command("say 我可志达岂能随便收徒!\n");
        return;
        }
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "tujue");
}
