// ´óÌÆË«Áú´«
 
// han.c º«ÀÏ°å

inherit F_VENDOR_SALE;

void create()
{
       reload("gaoli_hanlaoban");
       set_name("º«ÀÏ°å", ({"han baoban","han","laoban"}));
       set("shop_id",({"han baoban","han","laoban"}));
       set("shop_title","Ì«°×¾ÆÂ¥ÀÏ°å");
       set("gender", "ÄĞĞÔ");
        set("combat_exp", 100000);
       set("age", 26);
       set("per", 14);
       set("attitude", "friendly");
       set("shen_type", 1);
       set_skill("unarmed", 100);

       set("vendor_goods", ([
                "jiuhu": "/d/gaoli/obj/jiuhu",
                "liyu": "/d/gaoli/obj/liyu",
                "mifan": "/d/gaoli/obj/rice",
                "shaoji": "/d/gaoli/obj/liji",
        ]) );

setup();
        carry_object("/d/gaoli/obj/pao4")->wear();

   add_money("silver", 10);
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