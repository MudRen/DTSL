
inherit F_VENDOR_SALE;
void create()
{
   reload("xc_xiaoer2");
   set_name("��С��",({ "xiao er","xiao","er" }) );
        set("gender", "����" );
        set("age", 22);
   set("long", "���Ǿƹݵĵ�С����\n");
       set("shop_id",({ "xiao er","xiao","er" }) );
   set("combat_exp", 200);
   set("str", 18);
   set("per", 22);
   set("attitude", "friendly");
   set("vendor_goods",([
	   "naijiu":__DIR__"obj/jiudai",
	  // "baozi":__DIR__"obj/baozi",
	   "mifan":__DIR__"obj/mifan",
	   "kaoyangrou":__DIR__"obj/kaoyangrou",
	  "gongbaojiding":__DIR__"obj/gongbao-jiding",
	  "liudoufu":__DIR__"obj/liudoufu",
	  "jiachangliangcai":__DIR__"obj/jiachang-liangcai",
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
