// wujiang.c 武将

inherit NPC;

void create()
{
        set_name("武将", ({ "wu jiang", "wu", "jiang" }));
        set("gender", "男性");
        set("age", random(10) + 30);
        set("str", 25);
        set("dex", 16);
        set("long", "他站在那里，的确有说不出的威风。\n");
        set("combat_exp", 25000);
        set("shen_type", 1);
        set("attitude", "peaceful");
        setup();
        carry_object("/d/junying/obj/gangjian")->wield();
        carry_object("/d/junying/obj/tiejia")->wear();
}
