
inherit F_VENDOR_SALE;
void create()
{
   reload("yy_yaodian_wang");
   set_name("王药师",({ "wang yaoshi","wang","yaoshi"}) );
        set("gender", "男性" );
        set("age", 40);
   set("long", "这是渔阳的王药师，他这里有很多新奇的药物。\n");
    set("shop_id",({ "wang yaoshi","wang","yaoshi"}) );
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
   set("vendor_goods", ([
                "yao": "/d/clone/obj/medicine/jinchuang",
                "dan": "/d/clone/obj/medicine/dan",
                "yangjing-dan": "/d/clone/obj/medicine/yangjing-dan",
        ]) );
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
