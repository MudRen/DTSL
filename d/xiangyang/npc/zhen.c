
inherit NPC;
inherit F_DEALER;
void create()
{
   set_name("��ɩ",({ "zhen sao","zhen"}) );
        set("gender", "Ů��" );
        set("age", 22);
		
   set("long", "�������Ϸ��С���ɩ��\n");
       
   set("combat_exp", 2000);
   set("str", 20);
   set("per", 25);
   set_skill("unarmed",20);
   set_skill("dodge",20);
   set_skill("parry",20);
  set("attitude", "peaceful");
  set("vendor_goods",({
     __DIR__"obj/baozi",
  }));
   set("chat_chance",20);
   set("chat_msg",({
	   "��ɩ΢΢һЦ:����İ��Ӷ�����õ�,������!\n",
	   "��ɩ�����:����İ��Ӿ��Ժ�,����ͯ�����۵�.\n",
  }));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
 
}

void init()
{
	add_action("do_list","list");
	add_action("do_buy","buy");
}