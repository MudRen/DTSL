
inherit NPC;

void create()
{
   set_name("����",({ "liu qing","liu"}) );
        set("gender", "Ů��" );
        set("age", 24);
		
   set("long", "������³��谮��С檡�\n");
       
   set("combat_exp", 5000);
   set("str", 20);
   set("per", 25);
   set_skill("unarmed",20);
   set_skill("dodge",20);
   set_skill("parry",20);
  set("attitude", "peaceful");

   setup();
   carry_object(__DIR__"obj/cloth2")->wear();
 
}

