//job.
// 东溟任务。
//100k 有一个杀手
//500k 以后有两个杀手。
inherit NPC;
#include <job_money.h>
#include <ansi.h>
#include "map.h"
string give_job();
void create()
{
   set_name("大管家",({ "guan jia","guan","jia" }) );
        set("gender", "男性" );
        set("age", 42);
   set("long", "他是东溟的大管家。\n");
   set("combat_exp", 600000);
   set("str", 30);
   set_temp("apply/armor",30);
   set_temp("apply/damage",30);
   set_temp("apply/dodge",30);
   set("max_gin",2000);
   set("max_sen",2000);
   set("max_kee",2000);
   set("max_force",2000);
   set("force",2000);
   set("inquiry",([
     "宝物":(:give_job:),
     ]));
   setup();

}

string give_job()
{
  object me;
  object ob;
  string *t;
  int i;

  me=this_player();

  if(me->query("combat_exp")<100000)
  return "你的功夫太低了，很难做这个任务的。\n";
  if(me->query_temp("dm_job_find"))
  return "你还是赶快去寻找盗贼吧，东溟夫人最近催的很紧。\n";
  if(time()-me->query("busy_time")<120+random(20))
  return "你还是先歇歇吧！\n";
  if(me->query_temp("dtsl_job")&&
    me->query_temp("dtsl_job")!="东溟派寻宝任务")
  return "你正在做其他任务，还是先忙完其他的吧！\n";

  me->set_temp("dm_job_find",1);
  me->set_temp("dtsl_job","东溟派寻宝任务");

  i=random(sizeof(map));
  me->set_temp("dm_job_find_where",DM_JOB_PATH+map[i]);
  ob=new(__DIR__"ditu");
  ob->set("dm_job_find_where",DM_JOB_PATH+map[i]);
  ob->move(me);
  return "最近有盗贼偷走了东溟夫人的一件宝物，\n"+
         "据说此盗贼已经逃到了「屏风山」，你拿\n"+
         "这张地图去那里仔细搜查(soucha)吧！\n";

}

int accept_object(object who,object ob)
{
  int exp,pot,silver;

  if(!who->query_temp("dm_job_find"))
  return 0;
  if(!ob->query("dm_find_job"))
  return 0;
  if(ob->query("owner")!=who)
  return 0;

  who->delete_temp("dm_job_find");
  who->delete_temp("dm_job_find_where");
  who->delete_temp("have_killer");
  who->delete_temp("dtsl_job");

  who->set("busy_time",time());
  if(who->query("combat_exp")<500000)
  exp=200+random(30);
  else
  exp=220+random(30);
  pot=110+random(10);
  silver=who->query("max_pot");

  who->add("combat_exp",exp);
  who->add("potential",pot);
  who->add("deposit",silver);
  if(who->query("potential")>who->query("max_pot"))
	who->set("potential",who->query("max_pot"));
  tell_object(who,query("name")+"笑道：真是谢谢你了！\n"+
              "在这次行动中，你得到了"+HIW+chinese_number(exp)+NOR+"点经验，\n"+
              "                      "+HIY+chinese_number(pot)+NOR+"点潜能，\n"+
              "                      "+MONEY_D->money_str(silver)+"\n");
  add_shili(who,exp/3,silver/3);
  tell_object(who,"你的钱庄存款增加了！\n");
  return 1;
}
