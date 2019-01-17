
inherit F_VENDOR_SALE;
void create()
{
   reload("yz_xiaoer");
   set_name("��С��",({ "xiao er","xiao"}) );
   set("gender", "����" );
   set("age", 22);
   set("long", "����������ĵ�С����\n");
   set("shop_id",({ "xiao er","xiao"}) );   
   set("combat_exp", 200000);
   set("attitude", "friendly");
   set("vendor_goods",([
	   "yu": __DIR__"obj/yu",
	   "kaoya":__DIR__"obj/kaoya",
	   "jiudai":__DIR__"obj/jiudai",
	   "zhouzi":__DIR__"obj/zhouzi",
	   "jitui":__DIR__"obj/jitui",
	   "huotui":__DIR__"obj/huotui",
	   "niurou":__DIR__"obj/niurou",
	   "huasheng":__DIR__"obj/huasheng",
	   "gourou":__DIR__"obj/gourou",
	   "zharoupai":__DIR__"obj/zharoupai",
	   "rougan":__DIR__"obj/rougan",
	   "xiancai":__DIR__"obj/xiancai",
	   "zhengji":__DIR__"obj/zhengji",
   ]));
   
   set("chat_chance",30);
   set("chat_msg",({
   	(:do_command,"xixi":),
   	(:do_command,"sleepy":),
   	(:do_command,"xinku":),
   	(:do_command,"super":),
   
   }));
   
   setup();
   carry_object(__DIR__"obj/chouyi")->wear();
  
}

void init()
{
	object ob;
	
	::init();
	add_action("do_vendor_list", "list");
	ob=previous_object();
	if(!ob||!userp(ob)) return;
	remove_call_out("welcome");
	call_out("welcome",1,ob);
}

int regenerate()
{
        set("called", 0);
        return 1;
}

void welcome(object ob)
{
  if(!ob||!environment(ob)||
   environment(ob)!=environment(this_object())) return;
  switch(random(3)){
  
   case 0: message_vision("$N��$nЦ���������ʹ�� help ����ð�����\n",
   this_object(),ob);
   break;
   
   case 1: message_vision("$N��$nЦ���������ȥ���ݹ㳡�����Ҫ������\n",
   this_object(),ob);
   break;
   
   case 2: message_vision("$N��$n���˸�������ӭ��������˫������\n",
   this_object(),ob);
   break;
   default:break;}
   return;
}