
inherit F_VENDOR_SALE;
void create()
{
   reload("xy_xiaoer3");
   set_name("��С��",({ "xiao er","xiao","er" }) );
        set("gender", "����" );
        set("age", 22);
   set("long", "�������С�Ե�ĵ�С����\n");
      set("shop_id",({ "xiao er","xiao","er" }) );
   set("combat_exp", 2000);
   set("str", 22);
   set("per", 22);
   set("attitude", "friendly");
   set("vendor_goods",([
	   "doufu":__DIR__"obj/doufu",
	   "kaoya":__DIR__"obj/kaoya",
	   "jiudai":__DIR__"obj/jiudai"
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