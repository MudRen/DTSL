
inherit F_VENDOR_SALE;
void create()
{
   reload("xy_ma");
   set_name("马老板",({ "ma laoban","ma"}) );
        set("gender", "男性" );
        set("age", 32);
   set("long", "这是裁缝店的老板,他的技术可是闻名全城的。\n");
     set("shop_id",({ "ma laoban","ma"}) ); 
   set("combat_exp", 20000);
   set("str", 25);
   set("per", 24);
 
   set("attitude", "peaceful");
   set("vendor_goods",([
	  "chouyi":__DIR__"obj/chouyi",
	   "caiyi":__DIR__"obj/caiyi",
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