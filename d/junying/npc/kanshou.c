// kanshou.c ����

inherit NPC;

void create()
{
	set_name("����", ({ "kan shou", "shou" }));
	set("age", 22);
	set("gender", "����");
	set("long", "���ǿ��ء������������ء�\n");
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
	command("say ��������ѽ��\n");
	kill_ob(me);
	return 1;
}
