
inherit F_VENDOR_SALE;

void create()
{
   reload("hz_huang");
   set_name("������",({ "huang xiansheng","huang"}) );
        set("gender", "����" );
        set("age", 32);
   set("long", "����ҩ����ϰ�,�������ҩ����ܶ�ġ�\n");
    set("shop_id",({ "huang xiansheng","huang"}) );
   set("combat_exp", 60000);
   set("str", 25);
   set("per", 24);
 
   set("attitude", "peaceful");
   set("vendor_goods",([
	  "yao": "/d/clone/obj/medicine/jinchuang",
                "dan": "/d/clone/obj/medicine/dan",
                "yangjing-dan": "/d/clone/obj/medicine/yangjing-dan",
	 
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
