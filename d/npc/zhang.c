
inherit NPC;
inherit F_DEALER;

void create()
{
   set_name("���ƹ�",({ "zhang zhanggui","zhang"}) );
        set("gender", "����" );
        set("age", 42);
   set("long", "���ǲ÷����ϰ壬��������·��ܺá�\n");
       
   set("combat_exp", 200000);
   set("str", 25);
   set("per", 24);
 
   set("attitude", "peaceful");
   set("vendor_goods",({
	  __DIR__"obj/chouyi",
	   __DIR__"obj/shayi",
 }));
  setup();
   carry_object(__DIR__"obj/chouyi")->wear();
  
}

void init()
{
	add_action("do_list","list");
	add_action("do_buy","buy");

}

