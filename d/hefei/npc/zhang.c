
inherit F_VENDOR_SALE;

void create()
{
   reload("hf_zhang");
   set_name("���ƹ�",({ "zhang zhanggui","zhang"}) );
        set("gender", "����" );
        set("age", 42);
   set("long", "���ǲ÷����ϰ壬��������·��ܺá�\n");
    set("shop_id",({ "zhang zhanggui","zhang"}) );
   set("combat_exp", 200000);
   set("str", 25);
   set("per", 24);
 
   set("attitude", "peaceful");
   set("vendor_goods",([
	  "chouyi":__DIR__"obj/chouyi",
	   "shayi":__DIR__"obj/shayi",
 ]));
  setup();
   carry_object(__DIR__"obj/chouyi")->wear();
  
}

void init()
{
	::init();
	add_action("do_vendor_list", "list");
}

int regenerate()
{
        set("called", 0);
        return 1;
}