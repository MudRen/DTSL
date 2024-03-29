
inherit F_MASTER;
inherit NPC;
void create()
{
   set_name("康鞘利",({ "kang qiaoli","kang" }) );
        set("gender", "男性" );

        set("age", 42);
   set("long", "他就是突厥在中原的耳目．\n");

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

   // set_skill("pojun-quan",180);
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
   create_family("突厥",5,"武士");
   set("class","yin1");
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
   carry_object(__DIR__"obj/gangdao")->wield();

}
void attempt_apprentice(object ob)
{
	if(ob->query("family"))
	if(ob->query("family/family_name")=="突厥")
	if((int)ob->query("family/generation",1)<5)
	{   if(ob->query("gender")=="男性")
		tell_object(ob,"康鞘利连忙笑道:师兄真是会开玩笑!\n");
	    else tell_object(ob,"康鞘利连忙笑道:师姐真是会开玩笑!\n");
		return;
	}
	command("say 好,希望你在突厥好好干,以保我突厥将来一统天下!\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "tujue1");
}
