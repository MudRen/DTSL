
inherit NPC;

void create()
{
   set_name("Сɳ��",({ "sha mi","mi","sha"}) );
   set("gender", "����" );
   set("class","bonze");
   set("age", 12);
		
   set("long", "����һ��Сɳ�֡�\n");
       
   set("combat_exp", 70000);
   set("str", 26);
   
   set_skill("unarmed",50);
   set_skill("dodge",50);
   set_skill("parry",50);
  
   set("chat_chance",10);
   set("chat_msg",({
	   (:do_command,"buddhi":),
	   
  }));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
 
}

