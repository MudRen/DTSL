
inherit NPC;

void create()
{
   set_name("���߱�",({ "huaban bao","bao"}) );
        set("race", "Ұ��" );
        set("combat_exp",400000);
     set("long", "����һֻ���͵Ļ��߱����������㿴��\n");
	 set("verbs",({"bite","claw","hoof"}));
     set("attitude","aggressive");
     set("limbs",({"ͷ","β��","����","����"}));
  setup();

}

void die()
{
   object ob;
   ob=new(__DIR__"obj/baopi");
   ob->move(environment(this_object()));
   message_vision("$N��ͷ����һ�����ڵ�һ�µ����˵��ϡ�\n",this_object());
   destruct(this_object());
   return;
}

