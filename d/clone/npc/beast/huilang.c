
inherit NPC;

void create()
{
   set_name("����",({ "hui lang","lang","wolf"}) );
        set("race", "Ұ��" );
        set("combat_exp",200000);
     set("long", "����һֻ���͵Ļ��ǣ��������㡣\n");
	 set("verbs",({"bite","claw","hoof"}));
     set("attitude","aggressive");
     set("limbs",({"ͷ","β��","����","����"}));
  setup();

}

void die()
{
   object ob;
   ob=new(__DIR__"obj/langtui");
   ob->move(environment(this_object()));
   message_vision("$N��ͷ����һ�����ڵ�һ�µ����˵��ϡ�\n",this_object());
   destruct(this_object());
   return;
}

