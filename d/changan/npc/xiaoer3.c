
inherit F_VENDOR_SALE;
void create()
{
   reload("ca_xiaoer3");
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
	   "jiudai":__DIR__"obj/jiudai",
	   "niurou":__DIR__"obj/niurou",
	   "xiancai":__DIR__"obj/xiancai",
	   "huasheng":__DIR__"obj/huasheng",
	   "huotui":__DIR__"obj/huotui",
	   "rougan":__DIR__"obj/rougan",
	   "gourou":__DIR__"obj/gourou",
	   "yangtui":__DIR__"obj/yangtui",
	   "zharoupai":__DIR__"obj/zharoupai",
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
