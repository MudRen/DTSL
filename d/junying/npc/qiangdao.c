// qiangdao.c

inherit NPC;

void create()
{
	set_name("ǿ��", ({ "qiangdao","robber"}) );
	set("gender", "����");
	set("age", 30);
	set("long",
		"��һ���������һ����֪���������ࡣ\n");
	set("combat_exp", 10000);
        set("shen_type", -100);
	set("attitude", "aggressive");

	set("apply/attack", 20);
	set("apply/defense", 20);


	setup();

        carry_object("/d/junying/obj/blade")->wield();
        carry_object("/d/junying/obj/cloth")->wear();
}
