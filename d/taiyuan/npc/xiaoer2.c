
inherit F_VENDOR_SALE;
void create()
{
   reload("ty_xiaoer2");
   set_name("��С��",({ "xiao er","xiao","er" }) );
        set("gender", "����" );
        set("age", 22);
   set("long", "�������С�ƹݵĵ�С����\n");
    set("shop_id",({ "xiao er","xiao","er" }) );
   set("combat_exp", 200);
   set("str", 18);
   set("per", 22);
   set("attitude", "friendly");
   set("vendor_goods",([
	   "kaoya":__DIR__"obj/kaoya",
	   "jiudai":__DIR__"obj/jiudai",
	   "huotui":__DIR__"obj/huotui",
	   "niurou":__DIR__"obj/niurou",
	   "huasheng":__DIR__"obj/huasheng",
	   "gourou":__DIR__"obj/gourou",
	   "zharoupai":__DIR__"obj/zharoupai",
	   "rougan":__DIR__"obj/rougan",
	   "xiancai":__DIR__"obj/xiancai",
	   "yangtui":__DIR__"obj/yangtui",
	
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
