
inherit NPC;

void create()
{
   set_name("��ҧ��",({ "cheng yaojin","cheng","yaojin" }) );
        set("gender", "����" );
        set("age", 39);
   set("long", "����ǳ��������������³�ҧ��\n���������߸�կ���ˣ���תͶ��ҧ��");
   set("combat_exp", 300000);
   set("str", 29);
   set("per", 20);
   set("attitude", "peaceful");
   set_skill("unarmed",130);
   set_skill("parry",130);
   set_skill("dodge",130);
   set_skill("force",130);
   set_skill("axe",130);
   set_skill("sanban-fu",130);
   set("axe",({"sanban-fu"}));
   set("max_gin",1000);
   set("max_sen",1000);
   set("max_kee",1000);
   set("force",1000);
   set("max_force",1000);
   set("shili",([
      "name":"lifa_b",
      ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
   carry_object(__DIR__"obj/axe")->wield();
}

