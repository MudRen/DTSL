
inherit NPC;

void create()
{
   set_name("���",({ "xiang ke","xiang","ke"}) );
   set("gender", "����" );
   set("age", 30);
		
   set("long", "����һλ�������������͡�\n");
       
   set("combat_exp", 100000);
   set("str", 26);
   
   set_skill("unarmed",50);
   set_skill("dodge",50);
   set_skill("parry",50);
  
   set("chat_chance",10);
   set("chat_msg",({
	   (:do_command,"flook1":),
	   (:do_command,"story":),
  }));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
 
}

