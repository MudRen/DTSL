
inherit NPC;

void create()
{
   set_name("����",({ "old"}) );
        set("gender", "����" );
        set("age", 62);
		
   set("long", "�����������Ǿ�ס�ĵ����ߡ�\n");
       
   set("combat_exp", 5000);
   set("str", 20);
   set("per", 25);
   set_skill("unarmed",20);
   set_skill("dodge",20);
   set_skill("parry",20);
  set("attitude", "peaceful");

   setup();
   carry_object(__DIR__"obj/cloth")->wear();
 
}

