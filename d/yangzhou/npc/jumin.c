
inherit NPC;

void create()
{
   set_name("����",({ "ju min","ju","min"}) );
   set("gender", "����" );
   set("age", 30);
		
   set("long", "�������ݳ��ڵľ���\n");
       
   set("combat_exp", 70000);
   set("str", 26);
   
   set_skill("unarmed",50);
   set_skill("dodge",50);
   set_skill("parry",50);
  
   set("chat_chance",10);
   set("chat_msg",({
	   (:do_command,"flook1":),
	   (:do_command,"ai":),
	   (:do_command,"story":),
  }));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
 
}

