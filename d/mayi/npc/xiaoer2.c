
inherit F_VENDOR_SALE;
void create()
{
    reload("mayi_xiaoer2");
   set_name("��С��",({ "xiao er","xiao","er" }) );
        set("gender", "����" );
        set("age", 22);
   set("long", "��������ӻ��̵ĵ�С����\n");
       set("shop_id",({ "xiao er","xiao","er" }) );
   set("combat_exp", 200);
   set("str", 18);
   set("per", 22);
   set("attitude", "friendly");
   set("vendor_goods",([
	   "jiudai":__DIR__"obj/jiudai",
	   "kaoya":__DIR__"obj/kaoya",
	   "changjian":__DIR__"obj/changjian",
	   "huotui":__DIR__"obj/huotui",
	   "niurou":__DIR__"obj/niurou",
	   "huasheng":__DIR__"obj/huasheng",
	   "gourou":__DIR__"obj/gourou",
	   "zharoupai":__DIR__"obj/zharoupai",
	   "rougan":__DIR__"obj/rougan",
	   "pidun":__DIR__"obj/pidun",
	   "piyi":__DIR__"obj/piyi",
	   "weijin":__DIR__"obj/weijin",
	   "spear":__DIR__"obj/spear",
	   "yangtui":__DIR__"obj/yangtui",
   ]));
   setup();
    carry_object("/d/yangzhou/npc/obj/chouyi")->wear();
  
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
