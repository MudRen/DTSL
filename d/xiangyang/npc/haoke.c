
inherit NPC;

void create()
{
        set_name("��������", ({"jianghu haoke","haoke","ke"}));
        set("gender", "����");
        set("age", 34);
        set("long","���Ǵ���������һ������.\n");
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

        set_skill("blade", 150);
        set_skill("dodge", 150);
        set_skill("parry", 200);
		set_skill("cuff",120);
		set_skill("force",120);
		set_skill("whdmdao",130);
        set("blade",({"whdmdao"}));
        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 40);
        set("chat_chance",30);
		set("chat_msg",({
			"�������������:���۵���,����˭��ʤ������?\n",
		    "��������̾��:�л���һ��Ҫ�ҿ���ȥ���Ա���!\n",
			"�������ʹ�����:���ٵĵ���,ȷʵ�����µ�һ�����!\n",
		}));
		
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
		carry_object(__DIR__"obj/blade")->wield();
		add_money("gold",50);
}

