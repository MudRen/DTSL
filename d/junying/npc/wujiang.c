// wujiang.c �佫

inherit NPC;

void create()
{
        set_name("�佫", ({ "wu jiang", "wu", "jiang" }));
        set("gender", "����");
        set("age", random(10) + 30);
        set("str", 25);
        set("dex", 16);
        set("long", "��վ�������ȷ��˵���������硣\n");
        set("combat_exp", 25000);
        set("shen_type", 1);
        set("attitude", "peaceful");
        setup();
        carry_object("/u/smokes/junying/obj/gangjian")->wield();
        carry_object("/u/smokes/junying/obj/tiejia")->wear();
}

