
inherit NPC;

void create()
{
   set_name("���ϴ�",({ "yan laoda","yan","lao","da" }) );
        set("gender", "����" );
        set("age", 32);
		set("title","�񻨰�ͷĿ");
   set("long", "�����񻨰��ͷĿ���ϴ�,�����ݳǻ����Ǻ���������\n");
       
   set("combat_exp", 80000);
   set("str", 26);
   set("per", 22);
   set_skill("unarmed",50);
   set_skill("dodge",50);
   set_skill("parry",50);
   set_skill("stick",50);
   set("attitude", "peaceful");
   set("chat_chance",70);
   set("chat_msg",({
	   "���ϴ������ظ�:�����ݳ�����׼û��!\n",
	   "���ϴ�Ц��:�񻨰������ݻ��Ǻ���������!\n",
		   (:random_move:),
   }));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
   carry_object(__DIR__"obj/zhugun")->wield();
  
}

