
inherit NPC;

void create()
{
   set_name("Ұ��",({ "ye zhu","zhu"}) );
        set("race", "Ұ��" );
        set("combat_exp",100000);
     set("long", "Ұ����ߺ߽��˼�����\n");
	 set("verbs",({"bite","claw","hoof"}));
     set("limbs",({"ͷ","β��","����","����"}));
  setup();

}

void die()
{
   object ob;
   ob=new(__DIR__"obj/zhutui");
   ob->move(environment(this_object()));
   message_vision("$N��ͷ����һ�����ڵ�һ�µ����˵��ϡ�\n",this_object());
   destruct(this_object());
   return;
}

