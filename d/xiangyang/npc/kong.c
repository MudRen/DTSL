
inherit F_VENDOR_SALE;
void create()
{
   reload("xy_kong");
   set_name("���ϰ�",({ "kong laoban","kong"}) );
        set("gender", "����" );
        set("age", 32);
   set("long", "�������̵��ϰ�,�����Ļ�ˮƽҲ�Ǻܸߵġ�\n");
   set("shop_id",({ "kong laoban","kong"}) );
   set("combat_exp", 20000);
   set("str", 25);
   set("per", 24);
 
   set("attitude", "peaceful");
   set("vendor_goods",([
	  "fojing":__DIR__"obj/fojing",
	   "jing":__DIR__"obj/wenxue",
	   "quanpu":__DIR__"obj/quanpu",
	   "daggerbook":__DIR__"obj/dagger",
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