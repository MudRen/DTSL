
inherit NPC;

void create()
{
   set_name("С�к�",({ "boy"}) );
        set("gender", "����" );
        set("age", 12);
		
   set("long", "��������Ժ�����С�к���\n");
       
   set("combat_exp", 5000);
   set("str", 20);
   set("per", 25);
   set_skill("unarmed",20);
   set_skill("dodge",20);
   set_skill("parry",20);
  set("attitude", "peaceful");
   set("chat_chance",30);
   set("chat_msg",({
	   "С�к�����:[��֮��,�Ա���.  �����,ϰ��Զ]\n",
	   "С�к�����:[֪֮Ϊ֪֮,��֪Ϊ��֪]!\n",
   }));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
 
}

