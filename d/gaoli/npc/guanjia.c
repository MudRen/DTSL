// ����˫����
//guanjia.c

inherit NPC;

void create()
{
     set_name("�ܼ�", ({"guan jia", "guanjia"}));
     set("age", 48);
     set("gender", "����");
     set("long", "���ǽ𸮵Ĵ�ܼ�,����������´󲿷���������.\n");
     set("attitude", "peaceful");
     set("str", 20);
     set("combat_exp", 200000);
     set("max_kee", 1400);
     set("max_mana", 1200);
     set("max_sen", 1400);
     set("max_force", 1200);
     set("force", 200);
     set("force_factor", 100);
     set_skill("unarmed", 100);
     set_skill("dodge", 100);
     set_skill("parry", 100);
     set_skill("force", 100);

     setup();
     carry_object("/d/gaoli/obj/pao2")->wear();
}
