
inherit NPC;

void create()
{
   set_name("��Ԩ",({ "li yuan","li","yuan" }) );
        set("gender", "����" );
        set("title", "�����" );
        set("age", 55);
   set("long", "����ǳ�����ķ�����Ԩ��\n");
   set("combat_exp", 500000);
   set("str", 28);
   set("per", 24);
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
      "leader":"lifa_b",
      ]));
   setup();
   carry_object(__DIR__"obj/longpao")->wear();
  
}

