
inherit F_VENDOR_SALE;
inherit F_REPAIR;
void create()
{
   reload("ly_tiejiang");
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
 "toukui":"/obj/armor/toukui",
	  "gaotou":__DIR__"obj/gaotou",
	  "duanci":__DIR__"obj/duanci",
	  "hudun":__DIR__"obj/hudun",
	  "changxue":__DIR__"obj/longboot",
	  "tiechui":__DIR__"obj/tiechui",
	  "tieshou":__DIR__"obj/tiehand",
	  "wandao":__DIR__"obj/wandao",
	  "zhanjia":__DIR__"obj/zhanjia",
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
