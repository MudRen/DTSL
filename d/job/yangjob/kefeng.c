
inherit NPC;

void create()
{
   set_name("�ɷ����",({ "ke feng","ke","feng" }) );
        set("gender", "����" );
        set("age", 32);
   set("long", "������[�Ͼ���]�ĵ��˿ɷ����,��Ҳ������������¡�\n");
       
   set("combat_exp", 400000);
   set("str", 26);
   set("per", 22);
   set("attitude", "peaceful");
   set("max_kee",1500);
   set("max_sen",800);
   set("max_force",1500);
   set("force",1500);
   set("jiali",80);
   set_skill("dodge",100);
   set_skill("babu-ganchan",100);
   set_skill("whip",100);
   set_skill("fuchen-skill",100);
   set_skill("parry",100);
   setup();
   carry_object(__DIR__"daopao")->wear();
   carry_object(__DIR__"fuchen")->wield();
  
}

