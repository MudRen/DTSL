
inherit NPC;

void create()
{
   set_name("�ο�",({ "you ke","you","ke"}) );
   set("gender", "����" );
   set("age", 30);
		
   set("long", "����һλ������������ο͡�\n");
       
   set("combat_exp", 100000);
   set("str", 26);
   
   set_skill("unarmed",50);
   set_skill("dodge",50);
   set_skill("parry",50);
  
   set("chat_chance",10);
   set("chat_msg",({
	  "�ο�˵������˵����ʮ�ַ���������Ҫȥ������\n",
          "�ο����ҿ���������ķ羰���治��\n",
  }));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
 
}

