
inherit F_VENDOR_SALE;
inherit F_REPAIR;
void create()
{
   reload("xingyang_tiejiang");
   set_name("����",({ "tie jiang","tie","jiang","tiejiang" }) );
        set("gender", "����" );
        set("age", 40);
   set("long", "����������������������ı������Ǻܺá�\n");
    set("shop_id",({ "tie jiang","tie","jiang","tiejiang" }) );
   set("combat_exp",300000);
   set("str",26);
   set("per", 22);
   set("force",500);
   set("max_force",500);
   set("kee",800);
   set("max_kee",800);
   set("sen",500);
   set("max_sen",500);
   set_skill("dodge",80);
   set_skill("parry",80);
   set_skill("unarmed",80);
   set("attitude", "peaceful");
   set("vendor_goods",([
	  "changjian":__DIR__"obj/changjian",
	  "blade":__DIR__"obj/blade",
	  "axe":__DIR__"obj/axe",
	  "tianhongjian":__DIR__"obj/tianhong-jian",
	  "canglongjian":__DIR__"obj/canglong-jian",
	  "zhanmojian":__DIR__"obj/zhanmo-jian",
	  "wanshengdao":__DIR__"obj/wansheng-blade",
	  "zilindao":__DIR__"obj/zilin-blade",
	  "kuangshaqiang":__DIR__"obj/kuangsha-spear",
	  "yinlongqiang":__DIR__"obj/yinlong-spear",
	  "zimangbian":__DIR__"obj/zimang-bian",
	  "duomingbian":__DIR__"obj/duoming-bian",
	  ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

void init()
{
	::init();
	add_action("do_vendor_list", "list");
	add_action("do_repair",({"repair","xiu"}));
	
}

int regenerate()
{
        set("called", 0);
        return 1;
}