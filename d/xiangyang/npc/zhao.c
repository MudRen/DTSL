
inherit NPC;
inherit F_DEALER;
void create()
{
   set_name("���ϰ�",({ "zhao"}) );
        set("gender", "����" );
        set("age", 32);
   set("long", "������[��¥]���ƹ����ϰ塣\n");
       
   set("combat_exp", 200000);
   set("str", 27);
   set("per", 24);
   set_skill("force",120);
   set("force",800);
   set("max_force",800);
   set("attitude", "friendly");
   set("vendor_goods",({
	   __DIR__"obj/yu",
	   __DIR__"obj/kaoya",
	   __DIR__"obj/jiudai",
	   __DIR__"obj/zhouzi",
   }));
   setup();
   carry_object(__DIR__"obj/chouyi")->wear();
  
}

void init()
{
	add_action("do_list","list");
	add_action("do_buy","buy");
}