
inherit F_VENDOR_SALE;
void create()
{
   reload("gaoli_piaolaoban");
   set_name("���ϰ�",({ "piao laoban","piao"}) );
        set("gender", "����" );
        set("age", 32);
   set("long", "�������̵��ϰ�,�����Ļ�ˮƽҲ�Ǻܸߵġ�\n");
   set("shop_id",({ "piao laoban","piao"}) );
   set("combat_exp", 20000);
   set("str", 25);
   set("per", 24);
 
   set("attitude", "peaceful");
   set("vendor_goods",([
	  "jing":__DIR__"/d/gaoli/obj/wenxue",	  
  ]));
   setup();
  
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