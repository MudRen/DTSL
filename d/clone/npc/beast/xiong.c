
inherit NPC;

void create()
{
   set_name("����",({ "hei xiong","xiong"}) );
        set("race", "Ұ��" );
        set("combat_exp",300000);
     set("long", "����һֻ����ܣ���ɵɵ�ؿ����㡣\n");
	 set("verbs",({"bite","claw","hoof"}));
    set("limbs",({"ͷ","β��","����","����"}));
  setup();

}

void die()
{
   object ob;
   ob=new(__DIR__"obj/xiongpi");
   ob->move(environment(this_object()));
   message_vision("$N��ͷ����һ�����ڵ�һ�µ����˵��ϡ�\n",this_object());
   destruct(this_object());
   return;
}

