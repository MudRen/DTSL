
inherit F_VENDOR_SALE;
void create()
{
   reload("changan_chaguan");
   set_name("����ϰ�",({ "cha laoban","cha","laoban" }) );
        set("gender", "����" );
        set("age", 32);
   set("long", "���ǲ�ݵ��ϰ塣\n");
       set("shop_id",({ "cha laoban","cha","laoban" }) );
   set("combat_exp", 10000);
   set("str", 28);
   set("per", 23);
   set("attitude", "peaceful");
   set_skill("unarmed",70);
   set_skill("parry",70);
   set_skill("dodge",70);
   set("vendor_goods",([
	   "baozi":__DIR__"obj/baozi",
   ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

void init()
{
	::init();
	add_action("do_vendor_list", "list");
	add_action("do_teach","qingjiao");
}
int regenerate()
{
        set("called", 0);
        return 1;
}

