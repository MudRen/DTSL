
inherit NPC;
void create()
{
   set_name("������",({ "fang xuanling","fang","xuanling" }) );
        set("gender", "����" );
        set("age", 35);
   set("long", "�������������������·����䣬��Ϊ��������ļ�˲š�\n");
   set("combat_exp", 200000);
   set("str", 28);
   set("per", 26);
   set("attitude", "peaceful");
   set_skill("unarmed",150);
   set_skill("parry",150);
   set_skill("dodge",150);
   set_skill("force",150);
   set("max_gin",2000);
   set("max_sen",2000);
   set("max_kee",2000);
   set("force",2000);
   set("max_force",2000);
   set_skill("literate",100);
   set("shili",([
      "name":"lifa_b",
      ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

