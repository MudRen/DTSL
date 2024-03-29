
inherit F_MASTER;
inherit NPC;
void create()
{
   set_name("墩欲谷",({ "dun yugu","dun" }) );
        set("gender", "男性" );

        set("age", 42);
   set("long", "他就是毕玄的弟弟，深得突厥大汗的信任．\n");

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
   // set("hand",({"pojun-quan"}));
   set("gin",3000);
   set("max_gin",3000);
   set("kee",3000);
   set("max_kee",3000);
   set("sen",3000);
   set("max_sen",3000);
   set("force",4000);
   set("max_force",4000);
   create_family("突厥",2,"武士");
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
   carry_object(__DIR__"obj/gangdao")->wield();

}
void attempt_apprentice(object ob)
{
	if(ob->query("family"))
	if(ob->query("family/family_name")=="突厥")
	if((int)ob->query("family/generation",1)<2)
	{   if(ob->query("gender")=="男性")
		tell_object(ob,"墩欲谷连忙笑道:师兄真是会开玩笑!\n");
	    else tell_object(ob,"墩欲谷连忙笑道:师姐真是会开玩笑!\n");
		return;
	}
	if (ob->query_skill("pojun-quan", 1) < 120)
	{
		tell_object(ob,"墩欲谷冷笑道:我们突厥以武称雄，你的武功，回去向康鞘利学学吧!\n");
		return;
	}
	command("say 好,只要在突厥好好干,保证你将来成为一方自主!\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "tujue2");
}
