
inherit F_VENDOR_SALE;
void create()
{
   reload("yz_li");
   set_name("���ϰ�",({ "li"}) );
        set("gender", "����" );
        set("age", 32);
   set("long", "�����Ǿ�¥���ƹ����ϰ塣\n");
    set("shop_id",({ "li"}) );   
   set("combat_exp", 200000);
   set("str", 27);
   set("per", 24);
   set("attitude", "friendly");
   set("vendor_goods",([
	   "doufu":__DIR__"obj/doufu",
	   "kaoya":__DIR__"obj/kaoya",
	   "jiudai":__DIR__"obj/jiudai",
	   "zhengji":__DIR__"obj/zhengji",
	   "zhouzi":__DIR__"obj/zhouzi",
	   "jitui":__DIR__"obj/jitui",
	   "huotui":__DIR__"obj/huotui",
	   "niurou":__DIR__"obj/niurou",
	   "huasheng":__DIR__"obj/huasheng",
	   "gourou":__DIR__"obj/gourou",
	   "zharoupai":__DIR__"obj/zharoupai",
	   "rougan":__DIR__"obj/rougan",
	   "xiancai":__DIR__"obj/xiancai",
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