
inherit NPC;

void create()
{
   set_name("ʨ��",({ "shi zi","zi","shi"}) );
        set("race", "Ұ��" );
        set("combat_exp",400000);
     set("long", "����һֻ���͵�ʨ�ӣ��������㿴��\n");
	 set("verbs",({"bite","claw","hoof"}));
     set("attitude","aggressive");
     set("limbs",({"ͷ","β��","����","����"}));
  setup();

}

void die()
{
   object ob;
   ob=new(__DIR__"obj/shipi");
   ob->move(environment(this_object()));
   message_vision("$N��ͷ����һ�����ڵ�һ�µ����˵��ϡ�\n",this_object());
   destruct(this_object());
   return;
}

