// haidao.c

inherit NPC;

void create()
{
	set_name("海盗", ({ "haidao"}) );
	set("gender", "男性");
	set("age", 30);
	set("long",
		"这是一个独眼海盗，他正想攻击你。\n");
	set("combat_exp", 10000);
        set("shen_type", -100);
	set("attitude", "aggressive");

	set("apply/attack", 20);
	set("apply/defense", 20);


	setup();

        carry_object("/d/junying/obj/blade")->wield();
        carry_object("/d/junying/obj/cloth")->wear();
}
