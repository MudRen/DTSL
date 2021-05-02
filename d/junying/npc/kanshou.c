// kanshou.c 看守

inherit NPC;

void create()
{
	set_name("看守", ({ "kan shou", "shou" }));
	set("age", 22);
	set("gender", "男性");
	set("long", "他是看守。他正盯着你呢。\n");
	set("attitude", "peaceful");

        set("str", 35);
        set("dex", 30);
	set("combat_exp", 11000);
	set("shen_type", 1);
	setup();
        carry_object("/d/junying/obj/blade")->wield();
        carry_object("/d/junying/obj/junfu")->wear();
}


int accept_fight(object me)
{
	command("say 你想找死呀。\n");
	kill_ob(me);
	return 1;
}
