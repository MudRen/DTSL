
inherit NPC;

void create()
{
   set_name("���²�",({ "dugu ce","dugu","ce" }) );
        set("gender", "����" );
        set("age", 40);
   set("long", "���Ƕ��·��ĸ��ֶ��²ߣ�������Ϊ���·������˲š�\n");
   set("shili","dugu");   
   set("combat_exp",600000);
   set("str", 28);
   set("per", 23);
   set("attitude", "peaceful");
   set_skill("unarmed",180);
   set_skill("dodge",180);
   set_skill("parry",180);
   set_skill("force",180);
   set_skill("sword",180);
   set_skill("cuff",180);
   set_skill("dugu-jianfa",180);
   set("sword",({"dugu-jianfa"}));
   set("max_gin",1500);
   set("max_sen",1500);
   set("max_kee",2000);
   set("force",2000);
   set("max_force",2000);
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
   carry_object(__DIR__"obj/sword")->wield();
}

void init()
{
	add_action("do_shengzhi","shengzhi");
	add_action("do_fenglu","fenglu");
	
}

