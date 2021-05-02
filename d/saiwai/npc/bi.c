
inherit F_MASTER;
inherit NPC;
void create()
{
   set_name("毕玄",({ "bi xuan","bi" }) );
        set("gender", "男性" );

        set("age", 42);
   set("long", "他就是武尊毕玄，域内外三大宗师之一\n");

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

   // set_skill("pojun-quan",250);
   // set_skill("yanyang-quan",250);
   // set_skill("yuehen-qiang",250);
   set_skill("tianlang-dao",250);
   set("dodge",({"tianmo-huanzong"}));
   set("force_skill",({"yanyang-dafa"}));
   set("blade",({"tianlang-dao"}));
   // set("hand",({"pojun-quan","yanyang-quan"}));
   set("gin",4000);
   set("max_gin",4000);
   set("kee",4000);
   set("max_kee",4000);
   set("sen",4000);
   set("max_sen",4000);
   set("force",5000);
   set("max_force",5000);
   set("jiali",250);
   create_family("突厥",1,"武尊");
   set("class","yin1");
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
}
void attempt_apprentice(object ob)
{
	if (ob->query_skill("pojun-quan", 1) < 180)
	{
		tell_object(ob,"毕玄冷笑道:我们突厥以武称雄，你的武功，.........!\n");
		return;
	}
	command("say 好,只要在突厥好好干,保证你纵横天下!\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "tujue3");
}
