
inherit F_VENDOR_SALE;
void create()
{
    reload("suiye_xiaoer2");
   set_name("店小二",({ "xiao er","xiao","er" }) );
        set("gender", "男性" );
        set("age", 22);
   set("long", "这是这家杂货铺的店小二。\n");
       set("shop_id",({ "xiao er","xiao","er" }) );
   set("combat_exp", 200);
   set("str", 18);
   set("per", 22);
   set("attitude", "friendly");
   set("vendor_goods",([
	   "jiudai":__DIR__"obj/jiudai",
	   "kaoya":__DIR__"obj/kaoya",
	   "changjian":__DIR__"obj/changjian",
	   "piyi":__DIR__"obj/piyi",
	   "weijin":__DIR__"obj/weijin",
   ]));
   setup();
 //  carry_object(__DIR__"obj/cloth")->wear();
  
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
