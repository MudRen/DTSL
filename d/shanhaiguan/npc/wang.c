
inherit F_VENDOR_SALE;
void create()
{
   reload("shanhg_wang");
   set_name("���ϰ�",({ "wang" }) );
        set("gender", "����" );
        set("age", 32);
   set("long", "�������ϰ壬��ά�������С�ƹݡ�\n");
      set("shop_id",({ "wang" }) );
   set("combat_exp", 50000);
   set("attitude", "friendly");
   set("vendor_goods",([
      "jiudai":__DIR__"obj/jiudai",
      "gourou":__DIR__"obj/gourou",
      "huasheng":__DIR__"obj/huasheng",
      "huotui":__DIR__"obj/huotui",
      "kaoya":__DIR__"obj/kaoya",
      "niurou":__DIR__"obj/niurou",
      "rougan":__DIR__"obj/rougan",
      "xiancai":__DIR__"obj/xiancai",
      "zharoupai":__DIR__"obj/zharoupai",
      ]));
   setup();
   //carry_object("/d/gaoli/obj/cloth")->wear();
  
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
