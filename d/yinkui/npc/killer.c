
inherit NPC;
string *name=({"��","ɽ","����","����"});

void create_name(object ob)
{
   ob->set_name("��"+name[random(sizeof(name))],({ "jian ke","jian","ke","fu" }) );
   ob->set("gender", "Ů��" );
   ob->set("tilte","����");
   ob->set("long", "���ǴȺ���ի�İ��½���.\n");
   return;
}

void create()
{
   set_name("��"+name[random(sizeof(name))],({ "jian ke","jian","ke","fu" }) );
        set("gender", "Ů��" );
		set("tilte","����");
        set("age", 22);
   set("long", "���ǴȺ���ի�İ��½���.\n");
       
   set("combat_exp",50000);
   set("str", 25);
   set("per", 25);
   set("attitude", "peaceful");
   set_skill("unarmed",60);
   set_skill("dodge",60);
   set_skill("parry",60);
   set_skill("force",60);
   set_skill("sword",60);
  set("gin",300);
   set("eff_gin",300);
   set("kee",300);
   set("eff_kee",300);
   set("sen",300);
   set("eff_sen",300);
   set("force",300);
   set("max_force",300);
   create_family("�Ⱥ���ի",7,"����");
   setup();
   carry_object(__DIR__"obj/shayi")->wear();
   carry_object(__DIR__"obj/changjian")->wield();
  
}
