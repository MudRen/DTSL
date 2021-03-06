
inherit ITEM;
#include "map.h"
mapping name=([
"藏宝图":"cangbao tu",
"武功秘籍":"miji",
]);

int do_wa();
int do_linghui(string arg);

void create()
{
	string *n;
	int i;
	n=keys(name);
	i=random(sizeof(n));
	set_name(n[i], ({ name[n[i]] }));
	set_weight(10);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "张");
		set("no_drop",1);
		set("no_give",1);
		set("no_get",1);
		set("material", "布");		
	}
	setup();
}

string long()
{
   string *here;
   int i;
   if(query("long"))
   return query("long");
   if(query("name")=="藏宝图"){
   	here=keys(map);
   	i=random(sizeof(map));
   	set("here",here[i]);
   	set("long","据说这是一个藏宝图，据说宝藏藏在"+map[here[i]]+"。\n");}
   else{
   set("skill",1);
   set("long","据说这个武功秘籍可以帮助你提高[linghui]自己的武功。\n");}
   return query("long");
}

void init()
{
  add_action("do_wa","wa");
  add_action("do_linghui","linghui");
}

int do_wa()
{
  object ob;
  object money;
  
  ob=this_player();
  if(!query("here")) return 0;
  if(query("here")!=base_name(environment(ob)))
  return notify_fail("这里似乎不是藏有宝藏的地方。\n");
  message_vision("$N深出双手挖了起来。\n",ob);
  money=new("/obj/money/gold");
  money->set_amount(5000);
  money->move(environment(ob));
  message_vision("$N挖出了一堆黄金！\n",ob);
  destruct(this_object());
  return 1;
}

int do_linghui(string arg)
{
   object ob;
   
   ob=this_player();
   if(!query("skill")) return 0;
   if(!arg) return notify_fail("你要领会什么武功？\n");
   if(!ob->query_skill(arg,1))
   return notify_fail("你没有学过这个武功！\n");
   message_vision("$N照着武功秘籍领悟起武功来。\n",ob);
   ob->set_skill(arg,ob->query_skill(arg,1)+10);
   if(ob->query_skill(arg,1)>ob->query("max_pot")-100)
   ob->set_skill(arg,ob->query("max_pot")-100);
   destruct(this_object());
  return 1;
}