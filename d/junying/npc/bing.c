// bing.c �ٱ�

inherit NPC;

void create()
{
	set_name("�ٱ�", ({ "guan bing", "bing" }));
	set("age", 22);
	set("gender", "����");
	set("long", "��Ȼ�ٱ������ղ��ܺ�������ʿ��ȣ��������ǽ��������˶�������\n");
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
	command("say ��ү����������ɱ�ţ��������㵹ù��\n");
	kill_ob(me);
	return 1;
}
