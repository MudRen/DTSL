
inherit F_VENDOR_SALE;
void create()
{
   reload("xiangyang_chaguanxiaoer");
   set_name("���С��",({ "xiao er","xiao","er"}) );
        set("gender", "����" );
        set("age", 22);
   set("long", "���ǲ�ݵ�С��������æ����ͣ��\n");
     set("shop_id",({ "xiao er","xiao","er"}) );
   set("combat_exp", 20000);
   set("str", 25);
   set("per", 24);
 
   set("attitude", "peaceful");
   set("vendor_goods",([
	  "kaoya":__DIR__"obj/kaoya",
	   "jiudai":__DIR__"obj/jiudai",
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