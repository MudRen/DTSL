
inherit F_VENDOR_SALE;
void create()
{
    reload("leshou_zhubao-boss");
   set_name("���ϰ�",({ "li laoban","li","lao","ban" }) );
   set("gender", "����" );
   set("age", 40);
   set("long", "�����鱦����ϰ壬�������Ŵ����֡�\n");
   set("combat_exp", 500000);   
   set("attitude", "friendly");
   set("vendor_goods",([
	   "feicui-xianglian":__DIR__"obj/feicui-neck",
	   "huangjin-xianglian":__DIR__"obj/huangjin-neck",
	   "manao-xianglian":__DIR__"obj/manao-neck",
	   "baiyu-jiezhi":__DIR__"obj/baiyu-finger",
	   "hupo-jiezhi":__DIR__"obj/hupo-finger",
	   
   ]));
   setup();
 //  carry_object(__DIR__"obj/cloth")->wear();
  
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
