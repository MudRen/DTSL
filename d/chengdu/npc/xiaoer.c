
inherit F_VENDOR_SALE;
void create()
{
    reload("cd_xiaoer");
    set_name("��С��", ({ "xiao er", "xiao","er" }));
   
  set("gender", "����");
    set("age", 28);
	set("long",
        "�������С�Ե�ĵ�С����\n");
	set("combat_exp", 50000);
	set("attitude", "friendly");
	
	set("vendor_goods", ([
		"kaoya":__DIR__"obj/kaoya",
	"shuidai":__DIR__"obj/shuidai",
	"mifan":__DIR__"obj/rice",
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

