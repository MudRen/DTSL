// tufei.c

inherit NPC;

void create()
{
	set_name("����", ({ "tufei","bandit","fei" }) );
	set("gender", "����");
	set("age", 30);
	set("long",
		"��һ���������??һ�������ɷ��ģ��������������η��\n");
	set("combat_exp", 10000);
        set("shen_type", -100);
	set("attitude", "aggressive");

	set("apply/attack", 20);
	set("apply/defense", 20);


	setup();

        carry_object("/d/junying/obj/blade")->wield();
        carry_object("/d/junying/obj/cloth")->wear();
}
