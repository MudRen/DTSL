
inherit F_VENDOR_SALE;
void create()
{
   reload("jj_chunzailou_zhanggui");
   set_name("�ƹ�",({ "zhang gui","zhang","gui" }) );
        set("gender", "����" );
        set("age",42);
   set("long", "���Ǵ���¥���ƹ�\n");
    set("shop_id",({ "zhang gui","zhang","gui" }) ); 
   set("combat_exp",300000);
   set_skill("parry",130);
   set_skill("dodge",130);
   set_skill("force",130);
   set_skill("tiangang-sanjue",130);
   set_skill("anxiang-fuying",130);
   set_skill("poyu-quan",130);
   set("attitude", "friendly");
   set("vendor_goods",([
	   "cha":__DIR__"cha",
	   "liji":__DIR__"liji",
	   "songgao":__DIR__"songgao",
	   "huasheng":__DIR__"huasheng",
	   "jiu":__DIR__"jiu",
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
