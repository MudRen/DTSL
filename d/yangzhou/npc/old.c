
inherit NPC;

void create()
{
   set_name("����",({ "lao zhe","lao","zhe","old"}) );
   set("gender", "����" );
   set("age", 62);		
   set("long", "���������ݳǾ�ס�ĵ����ߡ�\n");
       
   set("combat_exp", 5000);
   set("per",15);	
   set_skill("unarmed",20);
   set_skill("dodge",20);
   set_skill("parry",20);
   set("attitude", "peaceful");
   
   set("chat_chance",10);
   set("chat_msg",({
   	(:do_command,"chitchat":),
   	(:do_command,"dream2":),
   	(:do_command,"fakuan":),
   }));
   	
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
 
}

