// ����˫����
 
// jia.c

inherit F_VENDOR_SALE;

void create()
{
  reload("dingxiang_yaopu_zhou");
  set_name("�ܴ��", ({"zhou daifu", "zhou", "daifu"}));
        set("title", "ҩ���ƹ�");
        set("gender", "����");
  set("shop_id",({"zhou dafu", "zhou", "dafu"}));
  set("age", 37);
  set("combat_exp", 30000);
   set("long","���Ƕ���������������Ĵ��ÿ���������������˺ܶࡣ\n");
  set("age", 38);
  set("attitude", "friendly");
  set_skill("unarmed", 10);
  set_skill("dodge", 40);
  set_skill("parry", 30);
 set("vendor_goods", ([
                "yao": "/d/clone/obj/medicine/jinchuang",
                "dan": "/d/clone/obj/medicine/dan",
                "yangjing-dan": "/d/clone/obj/medicine/yangjing-dan",
        ]) );
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
