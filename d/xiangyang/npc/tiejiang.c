
inherit F_VENDOR_SALE;
inherit F_REPAIR;

void create()
{
   reload("xy_tiejiang");
   
   set_name("铁匠",({ "tie jiang","tie","jiang","tiejiang" }) );
   set("gender", "男性" );
   set("age", 40);
   set("long", "这是襄阳的铁匠，他打造的兵器都是很好。\n");
   set("shop_id",({ "tie jiang","tie","jiang","tiejiang" }) );
   set("combat_exp",300000);
   
   set("force",500);
   set("max_force",500);
   set("kee",800);
   set("max_kee",800);
   set("sen",500);
   set("max_sen",500);
   
   set_skill("dodge",80);
   set_skill("parry",80);
   set_skill("force",80);
   set_skill("duanzao-jishu",100);
   
   set("attitude", "peaceful");
   set("vendor_goods",([
	  "changjian":__DIR__"obj/changjian",
	  "blade":__DIR__"obj/blade",
	  "axe":__DIR__"obj/axe",
	  "changmao":__DIR__"obj/changmao",
	  "duanjian":__DIR__"obj/duanjian",
	  "gangcha":__DIR__"obj/gangcha",
	  "gangzhang":__DIR__"obj/gangzhang",
	  "toukui":__DIR__"obj/toukui",
	  "yaodai":__DIR__"obj/yaodai",
	  ]));
   set("vocation","铁匠");
   set("vocation_skill","duanzao-jishu");
   set("inquiry",([
     "分支":"目前铁匠有三个分支：\n"+
            "1。打造兵器类(weapon) 2。锻造盔甲、药鼎类(armor) 3。打造可以涂毒兵器类(poison)。\n"+
            "你可以使用choose 来选择。如 choose weapon 。\n",
   ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

void init()
{
	::init();
	add_action("do_vendor_list", "list");
	add_action("do_repair",({"repair","xiu"}));
	add_action("do_choose","choose");
	
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
   if(skill!=query("vocation_skill")){
    command("say 我只传授"+to_chinese(query("vocation_skill"))+
             "「"+query("vocation_skill")+"」！");
    return 1;
   }
   return 0;
}
    
int do_choose(string arg)
{
   object ob;
   
   ob=this_player();
   
   if(ob->query("vocation")!="铁匠")
   return notify_fail("你还是先当铁匠吧！\n");
   
   if(ob->query("vocation_fenzhi"))
   return notify_fail("你无法更改自己的分支。\n");
   
   if(!arg||
      (arg!="weapon"&&arg!="armor"&&arg!="poison")
     )
   return notify_fail("你要选择什么分支？\n");
   
   tell_object(ob,"你选择了 "+arg+" 分支！\n");
   ob->set("vocation_fenzhi",arg);
   return 1;
}
   