
inherit NPC;

void create()
{
   set_name("Ѿ��",({ "ya huan","ya","huan"}) );
   set("gender", "Ů��" );
   set("age", 22);
		
   set("long", "���ǻ����ϵ�Ѿ�ߡ�\n");
       
   set("combat_exp", 30000);
   set("str", 20);
   set("per", 20);
   set_skill("unarmed",50);
   set_skill("dodge",50);
   set_skill("parry",50);
 
   set("chat_chance",30);
   set("chat_msg",({
	   "Ѿ��΢΢һЦ���Ҽ�С��ȵĿ��ż��أ�\n",
	   (:do_command,"bf":),
	   (:do_command,"shy":),
	  
  }));
   setup();
   carry_object(__DIR__"obj/shayi")->wear();
 
}

