
inherit NPC;

void create()
{
   set_name("����",({ "gong zi","gong","zi"}) );
        set("gender", "����" );
        set("age", 22);
		
   set("long", "�������ݳǵĹ���,ƽʱ�������й䡣\n");
       
   set("combat_exp", 30000);
   set("str", 26);
   set("per", 22);
   set_skill("unarmed",50);
   set_skill("dodge",50);
   set_skill("parry",50);
  set("attitude", "peaceful");
   set("chat_chance",50);
   set("chat_msg",({
	   "����΢΢һЦ:��û��Ư��������,������ʶ��ʶ��!\n",
	   "���Ӵ�����:�Ҽ���Ǯ����,��ʲô�²��а�!\n",
  }));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
 
}

