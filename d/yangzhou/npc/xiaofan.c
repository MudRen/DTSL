
inherit NPC;

void create()
{
   set_name("С��",({ "xiao fan","xiao","fan"}) );
   set("gender", "����" );
   set("age", 22);
		
   set("long", "����һ��С����\n");
       
   set("combat_exp", 70000);
   set("str", 26);
   
   set_skill("unarmed",50);
   set_skill("dodge",50);
   set_skill("parry",50);
  
   set("chat_chance",30);
   set("chat_msg",({
	   (:do_command,"gf":),
	   (:do_command,"flook1":),
	   (:do_command,"ai":),
	   (:do_command,"story":),
  }));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
 
}

