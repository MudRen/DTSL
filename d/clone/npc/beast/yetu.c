
inherit NPC;

void create()
{
   set_name("Ұ��",({ "ye tu","tu","rabbit"}) );
        set("race", "Ұ��" );
        set("combat_exp",100000);
     set("long", "����һֻ�Ұ�ɫ��Ұ�á�\n");
	 set("verbs",({"claw","hoof"}));
     set("limbs",({"ͷ","β��","����","����"}));
  setup();

}

void die()
{
   object ob;
   ob=new(__DIR__"obj/tutui");
   ob->move(environment(this_object()));
   message_vision("$N���˼��Σ��ڵ�һ�µ����˵��ϡ�\n",this_object());
   destruct(this_object());
   return;
}

