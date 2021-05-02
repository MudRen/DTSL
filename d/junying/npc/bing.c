// bing.c 官兵

inherit NPC;

void create()
{
	set_name("官兵", ({ "guan bing", "bing" }));
	set("age", 22);
	set("gender", "男性");
	set("long", "虽然官兵的武艺不能和武林人士相比，可是他们讲究的是人多力量大。\n");
	set("attitude", "peaceful");

        set("str", 34);
        set("dex", 36);
	set("combat_exp", 10000);
	set("shen_type", 1);
	setup();
        carry_object("/d/junying/obj/blade")->wield();
        carry_object("/d/junying/obj/junfu")->wear();
}


int accept_fight(object me)
{
	command("say 大爷我正想找人杀呐，今天算你倒霉。\n");
	kill_ob(me);
	return 1;
}
