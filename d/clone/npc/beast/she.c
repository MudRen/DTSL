
inherit NPC;

void create()
{
   set_name("��",({ "she","snake"}) );
        set("race", "Ұ��" );
        set("combat_exp",200000);
     set("long", "����һֻ�ߣ������ź����ӿ����㡣\n");
	 set("verbs",({"bite"}));
     set("limbs",({"ͷ","β��"}));
  setup();

}

void die()
{
   object ob;
   ob=new(__DIR__"obj/shedan");
   ob->move(environment(this_object()));
   message_vision("$N�鴤�˼������ˡ�\n",this_object());
   destruct(this_object());
   return;
}

