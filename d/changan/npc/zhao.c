
inherit F_VENDOR_SALE;
void create()
{
   reload("ca_zhao");
   set_name("���ϰ�",({ "zhao laoban","zhao","laoban" }) );
        set("gender", "����" );
        set("age", 32);
   set("long", "����ˮ������ϰ塣\n");
      set("shop_id",({ "zhao laoban","zhao","laoban" }) );
   set("combat_exp", 100000);
   set("str", 28);
   set("per", 23);
   set("attitude", "peaceful");
   set_skill("unarmed",70);
   set_skill("parry",70);
   set_skill("dodge",70);
   set("vendor_goods",([
	   "xiangjiao":__DIR__"obj/xiangjiao",
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

