// ´óÌÆË«Áú´«
 
// zhu.c

inherit F_VENDOR_SALE;

void create()
{
       reload("gaoli_zhulaoban");
       set_name("ÖìÀÏ°å", ({"zhu laoban","zhu","laoban" }));
       set("shop_id",({"zhu laoban","zhu","laoban"}));
       set("shop_title","Öé±¦µêÀÏ°å");
       set("gender", "ÄĞĞÔ");
        set("combat_exp", 10000);
       set("age", 26);
       set("per", 14);
       set("attitude", "friendly");
       set("shen_type", 1);
       set_skill("unarmed", 10);
       set("vendor_goods",([
	   "feicui-xianglian":__DIR__"obj/feicui-neck",
	   "huangjin-xianglian":__DIR__"obj/huangjin-neck",
	   "manao-xianglian":__DIR__"obj/manao-neck",
	   "baiyu-jiezhi":__DIR__"obj/baiyu-finger",
	   "hupo-jiezhi":__DIR__"obj/hupo-finger",
	   
   ]));
         setup();
        carry_object("/d/gaoli/obj/pao1")->wear();

   add_money("silver", 2);
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
