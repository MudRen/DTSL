inherit F_VENDOR_SALE;
inherit F_REPAIR;
void create()
{  
   reload("gaoli_tiejiang");
   set_name("����",({ "tie jiang","tie","jiang","tiejiang" }) );
   set("gender", "����" );
   set("shop_id",({ "tie jiang","tie","jiang","tiejiang" }) );
   set("age", 40);
   set("long", "���Ǹ�����������������ı������Ǻܺá�\n");
   set("combat_exp",300000);
   set("str",26);
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
	  "changjian":"/d/gaoli/obj/changjian",
	  "gangdao":"/d/gaoli/obj/gangdao",
	  "axe":"d/gaoli/obj/axe",
	  ]));
  setup();
  carry_object("d/gaoli/obj/cloth")->wear();

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
