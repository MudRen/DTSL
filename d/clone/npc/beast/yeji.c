
inherit NPC;

void create()
{
   set_name("Ұ��",({ "ye ji","ji"}) );
        set("race", "Ұ��" );
        set("combat_exp",30000);
     set("long", "����һֻҰ�������ϵ���ë�ܺÿ���\n");
	 set("verbs",({"bite","claw"}));
     set("limbs",({"ͷ","����","����"}));
  setup();

}

void die()
{
   object ob;
   ob=new(__DIR__"obj/yumao");
   ob->move(environment(this_object()));
   message_vision("$N��ͷ����һ�����ڵ�һ�µ����˵��ϡ�\n",this_object());
   destruct(this_object());
   return;
}

