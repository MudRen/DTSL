
inherit NPC;

void create()
{
   set_name("��Ԫ��",({ "li yuanba","li","yuanba" }) );
        set("gender", "����" );
        set("age", 25);
   set("long", "����ǳ��������������Ԫ�ԣ����Ĺ������������ߵġ�\n");
   set("combat_exp", 1000000);
   set("str", 28);
   set("per", 24);
   set("attitude", "peaceful");
   set_skill("unarmed",230);
   set_skill("parry",230);
   set_skill("dodge",230);
   set_skill("force",230);
   set_skill("hammer",230);
   // set_skill("hongtian-chuifa",230);
   // set("hammer",({"hongtian-chuifa"}));
   set("max_gin",2000);
   set("max_sen",2000);
   set("max_kee",2000);
   set("force",3500);
   set("max_force",3500);
   set("shili",([
      "name":"lifa_b",
      ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
   carry_object(__DIR__"obj/jinchui")->wield();
}
