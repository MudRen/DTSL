
inherit NPC;

void create()
{
   set_name("����",({ "di zi","di","zi" }) );
        set("gender", "����" );
        set("age", 22);
   set("long", "���������ѧϰ���յĵ��ӡ�\n");
       
   set("combat_exp", 20000);
   set("str", 25);
   set("per", 22);
   set("attitude", "peaceful");
   set_skill("dodge",50);
   set_skill("parry",50);
   set_skill("unarmed",50);
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

