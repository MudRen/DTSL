// ����˫����
// jin.c ������
 
inherit NPC;
inherit F_BANKOWNER;
void create()
{
   set_name("������", ({"jin mangui", "jin", "boss"}));
   set("shop_id",({"jin mangui", "jin", "boss"}));
   set("gender", "����");
   set("age", 47);
   set("kee", 500); 
   set("max_kee", 500);
   set("sen", 200);
   set("max_sen", 200); 
   set("max_mana", 200); 
   set("mana", 200); 
   set("combat_exp", 50000);
   set("attitude", "friendly");
   set("rank_info/respect", "�ƹ��");
   set("env/wimpy", 50);
   set("chat_chance", 10);
   set_skill("parry", 60);
   set_skill("unarmed", 60);
   set_skill("dodge", 60);

   setup();
        carry_object("/d/gaoli/obj/pao2")->wear();

   add_money("silver", 10);
}

void init()
{
	add_action("do_check", ({"check", "chazhang", "����"}));
	add_action("do_convert", ({"convert", "duihuan", "�һ�"}));
	add_action("do_deposit", ({"deposit", "cun", "��"}));
	add_action("do_withdraw", ({"withdraw", "qu", "ȡ"}));
}

