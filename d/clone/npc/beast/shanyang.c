
inherit NPC;

void create()
{
   set_name("ɽ��",({ "shan yang","yang","goat"}) );
        set("race", "Ұ��" );
        set("combat_exp",30000);
     set("long", "����һֻ��ɫ��ɽ��\n");
	 set("verbs",({"hoof"}));
     set("limbs",({"ͷ","β��","����","����"}));
  setup();

}

void die()
{
   object ob;
   ob=new(__DIR__"obj/yangjiao");
   ob->move(environment(this_object()));
   message_vision("$N���˼��Σ��ڵ�һ�µ����˵��ϡ�\n",this_object());
   destruct(this_object());
   return;
}

