//Edit By Subzero
inherit NPC;

void create()
{
   set_name("����",({ "chang he","chang","he" }) );
   set("gender", "����" );
   set("age", 30);
   set("long", "�������ʮ���꣬���������������࣬�������͸ߴ�
Ϊ�����ر��Ĵ���֮һ�����ػʳ�Ҫ�������š�\n");
   set("shili","li");
   set("combat_exp", 400000);
   set("str", 28);
   set("per", 18);
   set("attitude", "peaceful");
   set_skill("unarmed",150);
   set_skill("parry",150);
   set_skill("dodge",150);
   set_skill("force",150);
   set("max_gin",1000);
   set("max_sen",1000);
   set("max_kee",1000);
   set("force",1500);
   set("max_force",1500);
   set("shili",([
      "name":"lifa_b",
      ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
}
