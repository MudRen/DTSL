// qiangdao.c

inherit NPC;

void create()
{
	set_name("强盗", ({ "qiangdao","robber"}) );
	set("gender", "男性");
	set("age", 30);
	set("long",
		"这家伙蒙着脸，一看就知道决非善类。\n");
	set("combat_exp", 10000);
        set("shen_type", -100);
	set("attitude", "aggressive");

	set("apply/attack", 20);
	set("apply/defense", 20);


	setup();

        carry_object("/d/junying/obj/blade")->wield();
        carry_object("/d/junying/obj/cloth")->wear();
}
