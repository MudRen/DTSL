// tufei.c

inherit NPC;

void create()
{
	set_name("土匪", ({ "tufei","bandit","fei" }) );
	set("gender", "男性");
	set("age", 30);
	set("long",
		"这家伙满脸横肉??一付凶神恶煞的模样，令人望而生畏。\n");
	set("combat_exp", 10000);
        set("shen_type", -100);
	set("attitude", "aggressive");

	set("apply/attack", 20);
	set("apply/defense", 20);


	setup();

        carry_object("/d/junying/obj/blade")->wield();
        carry_object("/d/junying/obj/cloth")->wear();
}
