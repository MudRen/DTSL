
inherit F_VENDOR_SALE;

int give_obj();
int give_book();

void create()
{
   reload("xy_shangguan");
   
   set_name("�Ϲ�����",({ "shangguan xiansheng","shangguan"}) );
   set("gender", "����" );
   set("age", 32);
   set("long", "����ҩ����ϰ�,�������ҩ����ܶ�ġ�\n");
   set("shop_id",({ "shangguan xiansheng","shangguan"}) );
   set("combat_exp", 100000);
   
   set_skill("force",100);
   set_skill("parry",100);
   set_skill("dodge",100);
   set_skill("bencao-shuli",100);
   set_skill("poison",100);
   
   set("attitude", "peaceful");
   set("vendor_goods",([
	  "yangjingdan":__DIR__"obj/yangjingdan",
	   "buxuedan":__DIR__"obj/buxuedan",
	   "huishendan":__DIR__"obj/huishenwan",
	   "yao": "/d/clone/obj/medicine/jinchuang",
                "dan": "/d/clone/obj/medicine/dan",
                "yangjing-dan": "/d/clone/obj/medicine/yangjing-dan",
                "lurong": "/d/job/yishengjob/lurong",
                "niuhuang": "/d/job/yishengjob/niuhuang",
                "xiongdan": "/d/job/yishengjob/xiongdan",
                "zhansu": "/d/job/yishengjob/zhansu",
                "xiafen": "/d/job/yishengjob/xiafen",
                "hugu": "/d/job/yishengjob/hugu",
                "chuanshanjiake": "/d/job/yishengjob/chuanshanjiake",
  ]));
   set("vocation","ҩʦ");
   set("inquiry",([
    "ҩ��":(:give_obj:),
    "��������":(:give_book:),
    ]));
   setup();
   carry_object(__DIR__"obj/chouyi")->wear();
  
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
int is_apprentice_of(object ob)
{
        return 1;
}

int recognize_apprentice(object ob)
{
   return 1;
}

int prevent_learn(object me,string skill)
{
   if(me->query("vocation")!=query("vocation")){
     command("say ���ֲ���"+query("vocation")+"���ҿɲ������㼼�ܣ�");
     return 1;
   }
   if(skill=="bencao-shuli"&&me->query_skill("poison",1)){
    
    command("say ���Ȼѧϰ�˶�����poison�����ҾͲ��ܴ��ڱ�������"+
             "��bencao-shuli���ˣ�");
    return 1;
   }
   if(skill=="poison"&&me->query_skill("bencao-shuli",1)){
    
    command("say ���Ȼѧϰ�˱�������bencao-shuli�����ҾͲ��ܴ��ڶ���"+
             "��poison���ˣ�");
    return 1;
   }
   if(skill!="poison"&&skill!="bencao-shuli"){
     command("say ��ֻ����ҩʦ��������bencao-shuli���� ������poison����");
     return 1;
   }
   return 0;
}

int give_obj()
{
  object ob,obj;
  
  ob=this_player();
  
  if(present("yaoshi_yaoding",ob)){
    command("kok "+ob->query("id"));
    command("say ����һ��ҩ�����㹻�ˣ�");
    return 1;
  }
  if(ob->query("vocation")!="ҩʦ"){
    command("say ��ֻ��ҩʦҩ����\n");
    return 1;
  }
  
  obj=new("/obj/medicine/yaoding");
  obj->move(ob);
  command("say ���ҩ����������ҩ���úñ��ܡ�\n");
  
  return 1;
}

int give_book()
{
  object ob,book;
  
  ob=this_player();
  
  if(ob->query_skill("bencao-shuli",1)>=50){
    command("say ��ı�������ѧ����ô���ˣ������ѧ�͵�ҩʦ�ɣ�");
    return 1;
  }
  if(present("bencao book",ob)){
    command("say ���˲�Ҫ��ô̰�ģ�");
    return 1;
  }
  
  book=new(__DIR__"obj/bencaobook");
  book->move(ob);
  message_vision("$N����$nһ"+book->query("unit")+book->query("name")+"��\n",
   this_object(),ob);
  
  return 1;
}