
inherit NPC;
string start_bet();
int do_zuozhuang(string arg);
int do_start(string arg);
int do_fapai(string arg);
int do_kaipai(string arg);
void clear(object me,object ob);
int do_close();
void create()
{
   set_name("赌徒",({ "du tu","du","tu"}) );
        set("gender", "男性" );
        set("age", 32);
		
   set("long", "这是一个好赌成性的赌徒,家里的钱都快要输光了。\n");
       
   set("combat_exp", 5000);
   set("str", 20);
   set("per", 25);
   set_skill("unarmed",20);
   set_skill("dodge",20);
   set_skill("parry",20);
  set("attitude", "peaceful");
  set("inquiry",([
	  "赌博":(:start_bet:),
	  ]));

   setup();
   carry_object(__DIR__"obj/cloth")->wear();
 
}

void init()
{
	add_action("do_zuozhuang","zuozhuang");
	add_action("do_start","start");
	add_action("do_fapai","fapai");
	add_action("do_kaipai","kaipai");
	add_action("do_close","enough");
}

string start_bet()
{
	object me,ob;
	me=this_player();
	ob=this_object();
	if(ob->query("betting")) return "我正和别人赌呢,你等会吧!\n";
	message_vision("$N说道:好啊,咱们来赌二十一点吧!\n",ob);
	return "如果你想坐庄,就可以用 zuozhuang 开始,如果不想坐庄,可以用start开始.\n";
}

int do_zuozhuang(string arg)
{
	object me,ob,obj;object paper,pa1,pa2;
	string item,money;int count;
	me=this_player();ob=this_object();
	if(!arg) return notify_fail("请用 zuozhuang 金钱数目 金钱种类\n");
	if(sscanf(arg,"%s %s",item,money)!=2)
		return notify_fail("请用 zuozhuang 金钱数目 金钱种类\n");
	if(sscanf(item,"%d",count)!=1)
		return notify_fail("请用 zuozhuang 金钱数目 金钱种类\n");
    if(!objectp(obj=present(money,me)))
		return notify_fail("你身上没有这种货币!\n");
	if(!obj->query("money_id")) return notify_fail("你只可以用钱赌博!\n");
	if(obj->value()<100) return notify_fail("至少也要1两银子才可以参加赌博!\n");
    if(obj->query_amount()<count) return notify_fail("你身上没有这么多的"+obj->name()+"\n");
	obj->set_amount((obj->query_amount())-count);
	ob->set("betting",1);
	me->set("betting",1);
	me->set("bet/count",count);
	me->set("bet/money",obj);
	paper=new(__DIR__"obj/papers");
	paper->move(me);
	message_vision("$N说道:好了,快发牌(fapai)吧!\n",ob);

	return 1;
}

int do_fapai(string arg)
{
	object target,pa;int i;
	object me;object papers;object ob;
	me=this_player();ob=new(__DIR__"dutu");
	if(!arg) return notify_fail("请使用 fapai 人名\n");
	if(!objectp(target=present(arg,environment(me))))
		return notify_fail("这里没有这个人\n");
	if(!objectp(papers=present("papers",me)))
		return notify_fail("你身上没有纸牌\n");
	if(!me->query("betting")) return notify_fail("请重新开始坐庄吧!\n");
	if(papers->query("amounts")<=0)
	{   destruct(papers);
		return notify_fail("纸牌用完了,请重新坐庄吧!\n");
	}
	if(!me->query("bet/target"))
	me->set("bet/target",target);
	else 
	{if(me->query("bet/target")==target&&!target->query("bet/enough")) 
	     return notify_fail("不能总给一个人发牌!\n");
	  me->set("bet/target",target);
	}
	papers->add("amounts",-1);
	i=random(5)+random(5)+random(3);
	pa=new(__DIR__"obj/paper");
	pa->set("short",pa->short()+chinese_number(i)+"点");
	pa->move(target);
	if(userp(target)) me->add("desc",i);
	else ob->add("desc",i);
	if(userp(target))
	{  if(target!=me)
		tell_object(target,"还要牌吗?\n");
	   else tell_object(target,"你给了自己一张牌\n");
	}
	else
	{
       if((int)target->query("desc",1)<10)
		   tell_object(me,target->name()+"点点头:再来一张吧!\n");
	   else if((int)target->query("desc",1)<15)
		   tell_object(me,target->name()+"有些犹豫:再来一张吧!\n");
	   else 
	   {tell_object(me,target->name()+"道:可以了,可以开牌(kaipai)了!\n");
	     me->set("bet/enough",1);
	   }
	}
	return 1;
}

int do_kaipai(string arg)
{
	object me,ob;int c1,c2;int m1,m2;object money;
	me=this_player();
	if(!arg) return notify_fail("请使用kaipai 赌博对象\n");
	if(!objectp(ob=present(arg,environment(me))))
		return notify_fail("这里没有这个人!\n");
	c1=me->query("desc");
	c2=ob->query("desc");
	if(c1>21&&c2>21)
	{
		money=me->query("bet/money");
		money->set_amount(money->query_amount()+me->query("bet/count"));
		clear(me,ob);
		return notify_fail("双方暴点,平局!\n");
	}
	if(c1>21)
	{clear(me,ob);
	return notify_fail("你暴点了,这一局你输了!\n");}
		if(c2>21)
	{
       money=me->query("bet/money");
		money->set_amount(money->query_amount()+2*me->query("bet/count"));
		clear(me,ob);
		return notify_fail("对方暴点,这一局你赢了!\n");
	}
	if(c2>c1)
	{clear(me,ob);
	return notify_fail("对方点数取胜,这一局你输了!\n");}
	if(c1>c2)
	{
		money=me->query("bet/money");
		money->set_amount(money->query_amount()+2*me->query("bet/count"));
		clear(me,ob);
		return notify_fail("你以点数取胜,这一局你赢了!\n");
	}
	if(c1==c2)
	{
		
		money=me->query("bet/money");
		money->set_amount(money->query_amount()+me->query("bet/count"));
		clear(me,ob);
		return notify_fail("双方点数相同,平局!\n");
	}

	return 1;
}

void clear(object me,object ob)
{
	me->delete("bet");
	me->delete("betting");
	me->delete("desc");
	ob->delete("desc");
    ob->delete("bet");
	ob->delete("betting");
	return;
}

int do_close()
{
	object me,ob;
	me=this_player();
	ob=new(__DIR__"dutu");
	ob->set("bet/enough",1);
	tell_object(me,"你决定不要牌了\n");
	return 1;
}