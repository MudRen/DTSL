
inherit NPC;

void create()
{
   set_name("�ϻ�",({ "lao hu","hu","tigger"}) );
        set("race", "Ұ��" );
        set("combat_exp",200000);
     set("long", "����һֻ���͵��ϻ���\n");
	 set("verbs",({"bite","claw","hoof"}));
     set("attitude","aggressive");
     set("limbs",({"ͷ","β��","����","����"}));
  setup();

}

void die()
{
   object ob;
   ob=new(__DIR__"obj/hupi");
   ob->move(environment(this_object()));
   message_vision("$N��ͷ����һ�����ڵ�һ�µ����˵��ϡ�\n",this_object());
   destruct(this_object());
   return;
}

