// haidao.c

inherit NPC;

void create()
{
	set_name("����", ({ "haidao"}) );
	set("gender", "����");
	set("age", 30);
	set("long",
		"����һ�����ۺ����������빥���㡣\n");
	set("combat_exp", 10000);
        set("shen_type", -100);
	set("attitude", "aggressive");

	set("apply/attack", 20);
	set("apply/defense", 20);


	setup();

        carry_object("/u/smokes/junying/obj/blade")->wield();
        carry_object("/u/smokes/junying/obj/cloth")->wear();
}
