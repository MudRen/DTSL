
inherit ITEM;

#include <ansi.h>
#include <job_money.h>


int do_xianbao(string arg);

void create()
{
   set_name("藏宝图", ({ "map"}) );
   set_weight(100);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "paper");
     set("duobao_job",1);
     set("rumor",1);
     set("no_drop",1);
     set("no_give",1);
     set("no_get",1);
     set("unit", "个");
     set("value", 4000000);
     set("long","这是一个藏宝图。\n");
   }
   setup();
}

void init()
{
    add_action("do_xianbao","xianbao");
}

int do_xianbao(string arg)
{
   object ob,target;
   int exp,money,pot;
   
   ob=this_player();
   if(!arg)
   return notify_fail("你要给谁献宝？\n");
   if(!objectp(target=present(arg,environment(ob))))
   return notify_fail("这里没有这个人。\n");
if(base_name(environment(target))!="/d/haisha/fenzangpeng")
   return notify_fail("你企图利用BUG的野心被巫师发现了！\n");
   if(!query("duobao_job"))
   return notify_fail("这么珍贵的宝物可不要献错人了！\n");
   
   ob->delete("job");
  ob->delete_temp("dtsl_job");
  
  ob->set("busy_time",time());
  exp=300+random(50);
  pot=ob->query("max_pot")*2/3;
  money=ob->query("max_pot")+random(30);
  
  ob->add("combat_exp",exp);
  ob->add("potential",pot);
  if(ob->query("potential")>ob->query("max_pot")*3/2)
  ob->set("potential",ob->query("max_pot")*3/2);
  ob->add("deposit",money);
 add_shili(ob,exp,money);
 
 tell_object(ob,"蔡胜哈哈一笑，好，"+RANK_D->query_respect(ob)+",好样的！\n");
  tell_object(ob,"这次行动你得到了"+HIW+chinese_number(exp)+NOR+"点经验。\n");
  tell_object(ob,"这次行动你得到了"+HIY+chinese_number(pot)+NOR+"点潜能。\n");
  tell_object(ob,"                "+HIW+chinese_number(money/100)+NOR+"两白银。\n");
  tell_object(ob,"你的钱庄存款增加了！\n");
  destruct(this_object());
  return 1;
}
  
