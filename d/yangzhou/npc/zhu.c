
inherit F_VENDOR_SALE;
void create()
{
   reload("yz_zhu");
   set_name("���ϰ�",({ "zhu"}) );
        set("gender", "����" );
        set("age", 42);
		
   set("long", "�����ӻ��̵��ϰ壬ÿ�춼æ����ͣ��\n");
   set("shop_id",({ "zhu"}) );  
   set("combat_exp", 200000);
   set("str", 28);
   set("per", 25);
   set_skill("unarmed",80);
   set_skill("dodge",80);
   set_skill("parry",80);
  set("attitude", "peaceful");
  set("vendor_goods",([
     "kedao":__DIR__"obj/kedao",
	"huozhe":__DIR__"obj/huozhe",
	"paper":"/obj/misc/paper",
	"pifeng":"/obj/armor/pifeng",
	"chanzhang":__DIR__"obj/chanzhang",
	"yao": "/d/clone/obj/medicine/jinchuang",
	"dan": "/d/clone/obj/medicine/dan",
	"yangjing-dan": "/d/clone/obj/medicine/yangjing-dan",
	"rose":__DIR__"obj/rose",
  ]));
  
  set("chat_chance",20);
  set("chat_msg",({
   "���ϰ�Ц������������������ɫ�ģ�\n",
   "���ϰ�˵�������ں��쿴��·�𣿿����򡰻����ӡ��ɣ�\n",
   "���ϰ�Ц�����̵������������Ͽ�������������ɣ�\n",
  }));
  
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
