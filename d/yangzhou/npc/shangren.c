
inherit NPC;

void create()
{
        set_name("����", ({"shang ren","shang","ren"}));
        set("gender", "����");
        set("age", 34);
        set("long","����һλ���ϴ��������ˡ�\n");
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
	set_skill("wuxing-quan",130);
        set("hand",({"wuxing-quan"}));
        set_temp("apply/dodge", 100);
        set_temp("apply/armor", 100);
        set_temp("apply/damage", 40);
        set("chat_chance",20);
        set("chat_msg",({
          "����˵����˵�����޼鲻�̡����ҿɲ�ͬ�⣬����������Ǻܹ�ƽ�ģ�\n",
          "����Ц������λ��Ҫʲô���ֻҪ����˵һ������֤����Ū����\n",
        }));
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
        add_money("silver",10);
}

