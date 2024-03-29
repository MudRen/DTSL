
inherit NPC;
inherit F_MASTER;
void create()
{
   set_name("不渡",({ "bu du","bu","du"}));
        set("gender", "男性" );
        set("age", 32);
   set("long", "这是净念禅院的高僧之一。\n");
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
   create_family("静念禅院",6,"僧人");
   setup();
   carry_object(__DIR__"obj/sengyi")->wear();
   carry_object(__DIR__"obj/staff")->wield();

}

void attempt_apprentice(object ob)
{
	if(ob->query("family"))
	if(ob->query("family/family_name")=="静念禅院")
	if((int)ob->query("family/generation",1)<6)
	{   if(ob->query("gender")=="男性")
		tell_object(ob,"不渡连忙笑道:师兄真是会开玩笑!\n");

	}
	if(ob->query("gender")=="女性")
	{
		tell_object(ob,"不渡笑道:我们禅院只收男弟子的,施主如果一心向佛,可以去慈航静斋.\n");
		return;
	}
	if((int)ob->query("PKS",1)>=5)
	{
		tell_object(ob,"不渡双手合十道:施主,你的杀气太重,我怎么收你呢?\n");
		return;
	}

	command("say 阿弥陀佛!希望施主今后能超度世人的苦恼,成为一代高僧,光大佛法!\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "bonze");
}
