
inherit F_VENDOR_SALE;
void create()
{
   reload("ls_yaodian_song");
   set_name("�δ��",({ "song daifu","song","daifu"}) );
        set("gender", "����" );
        set("age", 40);
   set("long", "������������ҩʦ���������кܶ������ҩ�\n");
    set("shop_id",({ "song daifu","song","daifu"}) );
   set("combat_exp",300000);
   set("str",26);
   set("per", 22);
   set("force",500);
   set("max_force",500);
   set("kee",800);
   set("max_kee",800);
   set("sen",500);
   set("max_sen",500);
   set_skill("dodge",80);
   set_skill("parry",80);
   set_skill("unarmed",80);
   set("attitude", "peaceful");
   set("vendor_goods", ([
                "yao": "/d/clone/obj/medicine/jinchuang",
                "dan": "/d/clone/obj/medicine/dan",
                "yangjing-dan": "/d/clone/obj/medicine/yangjing-dan",
        ]) );
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
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
