
inherit F_VENDOR_SALE;
void create()
{
    reload("pl_xiaoer3");
   set_name("��С��",({ "xiao er","xiao","er" }) );
        set("gender", "����" );
        set("age", 22);
   set("long", "���ǲ�ݵĵ�С����\n");
       set("shop_id",({ "xiao er","xiao","er" }) );
   set("combat_exp", 200);
   set("str", 18);
   set("per", 22);
   set("attitude", "friendly");
   set("vendor_goods",([
	   //"jiudai":__DIR__"obj/jiudai",
	   "kaoya":__DIR__"obj/kaoya",
	   //"mifan":__DIR__"obj/mifan",
   ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
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
