
inherit F_VENDOR_SALE;

int give_obj();
int give_book();

void create()
{
   reload("xy_shangguan");
   
   set_name("上官先生",({ "shangguan xiansheng","shangguan"}) );
   set("gender", "男性" );
   set("age", 32);
   set("long", "这是药店的老板,他这里的药种类很多的。\n");
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
   set("vocation","药师");
   set("inquiry",([
    "药鼎":(:give_obj:),
    "本草术理":(:give_book:),
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
     command("say 你又不是"+query("vocation")+"，我可不传授你技能！");
     return 1;
   }
   if(skill=="bencao-shuli"&&me->query_skill("poison",1)){
    
    command("say 你既然学习了毒术「poison」，我就不能传授本草术理"+
             "「bencao-shuli」了！");
    return 1;
   }
   if(skill=="poison"&&me->query_skill("bencao-shuli",1)){
    
    command("say 你既然学习了本草术理「bencao-shuli」，我就不能传授毒术"+
             "「poison」了！");
    return 1;
   }
   if(skill!="poison"&&skill!="bencao-shuli"){
     command("say 我只传授药师本草术理「bencao-shuli」或 毒术「poison」！");
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
    command("say 你拿一个药鼎就足够了！");
    return 1;
  }
  if(ob->query("vocation")!="药师"){
    command("say 我只给药师药鼎。\n");
    return 1;
  }
  
  obj=new("/obj/medicine/yaoding");
  obj->move(ob);
  command("say 这个药鼎可以炼制药物，你好好保管。\n");
  
  return 1;
}

int give_book()
{
  object ob,book;
  
  ob=this_player();
  
  if(ob->query_skill("bencao-shuli",1)>=50){
    command("say 你的本草术理学得这么高了，想继续学就当药师吧！");
    return 1;
  }
  if(present("bencao book",ob)){
    command("say 做人不要那么贪心！");
    return 1;
  }
  
  book=new(__DIR__"obj/bencaobook");
  book->move(ob);
  message_vision("$N给了$n一"+book->query("unit")+book->query("name")+"。\n",
   this_object(),ob);
  
  return 1;
}