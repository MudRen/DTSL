
inherit NPC;

void create()
{
        set_name("����", ({"shang ren","shang","ren"}));
        set("gender", "����");
        set("age", 34);
        set("long","����һλ���ϴ���������.\n");
        set("str", 26);
        set("int", 24);
        set("dex", 18);
        set("con", 18);

        set("kee", 500); 
        set("max_kee", 500);
        set("gin", 100);
        set("max_gin", 100);
        set("sen",300);
        set("max_sen",300);
		set("force",800);
		set("max_force",800);
        set("combat_exp",300000);
        set("shen_type", 1);
        set("attitude", "peaceful");
        set("env/wimpy", 50);

        set_skill("unarmed", 150);
        set_skill("dodge", 150);
        set_skill("parry", 200);
		set_skill("cuff",120);
		set_skill("force",120);
		
        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 40);
       setup();
        carry_object(__DIR__"obj/cloth")->wear();
}

