
inherit F_VENDOR_SALE;
void create()
{
   reload("ly_ma");
   set_name("���ϰ�",({ "kou laoban","kou"}) );
        set("gender", "����" );
        set("age", 32);
   set("long", "���ǳ��ׯ���ϰ�,���ļ�����������ȫ�ǵġ�\n");
     set("shop_id",({ "kou laoban","kou"}) ); 
   set("combat_exp", 20000);
   set("str", 25);
   set("per", 24);
 
   set("attitude", "peaceful");
   set("vendor_goods",([
	  "chouyi":__DIR__"obj/chouyi",
	   "caiyi":__DIR__"obj/caiyi",
	   "shayi":__DIR__"obj/shayi",
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