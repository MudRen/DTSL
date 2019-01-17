
#include <ansi.h>
inherit ITEM;

void create()
{
   set_name(HIY"七"HIM"窍"HIC"玲"HIG"珑"HIW"玉"NOR, ({ "qiqiao yu","qiqiao","yu"}) );
   set_weight(5000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "iron");
     set("unit", "块");
     set("value", 10000000);
	 set("weapon",([
         "damage":120,
         "strong":120,
		 ]));
   }
   setup();
}

int is_get_of(object me,object ob)
{
  object dkiller;
  if(query("owner")==me->query("id"))
  return 1;
  dkiller=new(__DIR__"she");
  message_vision(HIR"猛然间从地下钻出一条$N!\n"NOR,dkiller);
  dkiller->move(environment(me));
  set("owner",me->query("id"));
  dkiller->kill_ob(me);
  call_out("move_object",2,ob,dkiller);
  return 1;
}

void move_object(object ob,object dkiller)
{
  if(!dkiller||!ob) return;
  ob->move(dkiller);
  message_vision("$N尾巴一卷，把"+ob->query("name")+"卷到了身上！\n",dkiller);
  return;
}
