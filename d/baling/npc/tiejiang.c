
inherit F_VENDOR_SALE;
inherit F_REPAIR;
void create()
{
   reload("bl_tiejiang");
   set_name("铁匠",({ "tie jiang","tie","jiang","tiejiang" }) );
        set("gender", "男性" );
        set("age", 40);
   set("long", "这是巴陵的铁匠，他打造的兵器都是很好。\n");
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
	  "dunpai":__DIR__"obj/dunpai",
	  "gangkui":__DIR__"obj/gangkui",
	  "gangwan":__DIR__"obj/gangwan",
	  "hujing":__DIR__"obj/hujing",
	  "jiazhou":__DIR__"obj/jiazhou",
	  "shoutao":__DIR__"obj/shoutao",
	  "yaodai":__DIR__"obj/yaodai",
	  "zhanxue":__DIR__"obj/zhanxue",
	  "zhihuan":__DIR__"obj/zhihuan",
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