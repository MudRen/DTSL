
inherit NPC;

void create()
{
   set_name("÷��¹",({ "meihua lu","lu"}) );
        set("race", "Ұ��" );
        set("combat_exp",150000);
     set("long", "����һֻ÷��¹����������Բݡ�\n");
	 set("verbs",({"claw","hoof"}));
     set("limbs",({"ͷ","β��","����","����"}));
  setup();

}

void die()
{
   object ob;
   ob=new(__DIR__"obj/lujiao");
   ob->move(environment(this_object()));
   message_vision("$N���˼��Σ��ڵ�һ�µ����˵��ϡ�\n",this_object());
   destruct(this_object());
   return;
}


