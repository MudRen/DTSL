// ����˫����

inherit F_VENDOR_SALE;

void create()
{
       reload("clone_room_yufu");
       set_name("���", ({"yu fu","fu"}));
       set("shop_id",({"yu fu","fu"}));
       set("gender", "����");
       set("combat_exp", 100000);
       set("age", 30+random(20));
       
       set_skill("unarmed", 100);

       set("vendor_goods", ([
                "yugan": __DIR__"obj/yugan",
                
        ]) );

   setup();
     
   add_money("silver", 10);
}

void init()
{
        object ob;
        
        ::init();
	add_action("do_vendor_list", "list");
	
	ob=this_player();
	
	if(!ob||is_fighting()) return;
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
   if(!ob) return;
   if(environment(ob)!=environment(this_object()))
   return;
   
   command("say ������������ˣ�������ĵ����������ˡ�");
   
}