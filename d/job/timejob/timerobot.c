//job.
// 随机任务。:-P

inherit NPC;

#include <ansi.h>
#include <job_money.h>

#define TOTAL_TASK 25

int do_list();
int do_ok(string arg);
int do_task();

void create()
{
   set_name("飞云子",({ "feiyun zi","feiyun","zi" }) );
        set("gender", "男性" );
        set("age", 42);
        set("nickname",HIW"嗜宝如命"NOR);
   set("long", "他就是喜欢搜集宝物的飞云子，没有人知道他的真正来历。\n");
   set("combat_exp", 600000);
   set("str", 30);
   set_temp("apply/armor",30000);
   set_temp("apply/damage",30000);
   set_temp("apply/dodge",300000);
   set("max_gin",2000);
   set("max_sen",2000);
   set("max_kee",2000);
   set("max_force",2000);
   set("force",2000);
   set("target_id","###");
   set("save_id","random_job_npc");
   set("inquiry",([
     "yanyan":"如果对这个任务有什么意见，请直接给他发e-mail。\n",
     "真冰河":"如果对这个任务有什么意见，请直接给他发e-mail。\n",
     "job":(:do_task:),
     "宝物":(:do_task:),
     ]));
 setup();
  
}
void init()
{
  add_action("do_list","list");
  add_action("do_ok","lingshang");
 
}

int do_list()
{
    object jobctrl,ob,msg;
    
    ob=this_player();
    
    jobctrl=load_object(__DIR__"jobctrl.c");
    
    msg=jobctrl->do_list();
    
    ob->start_more(msg);
    
    return 1;
}
int do_task()
{
  object ob,tool,jobctrl;
  
  ob=this_player();
  jobctrl=load_object(__DIR__"jobctrl.c");
  
  jobctrl->start_job();
  
  if(ob->query_temp("random_job")){
  command("push "+ob->query("id"));
  return 1;
  }
 
 if(this_object()->query("tasks")>=TOTAL_TASK){
      tell_object(ob,"目前宝物已经寻找完毕，等等吧！\n");
      return 1;
      }
   
  if(ob->query_temp("dtsl_job")){
  command("kok "+ob->query("id"));
  tell_object(ob,"你正做其他任务呢，先忙其他的吧！\n");
  return 1;
  }
 // if(!valid_do_job(ob,"randomjob"))
 // return notify_fail("你的武功很高了，做这样的小事真是大才小用了！\n");
  ob->set_temp("dtsl_job","随机任务");
  tool=new(__DIR__"tool");
  tool->move(ob);
 tool->set("owner",ob);
  tell_object(ob,"飞云子偷偷告诉你:你拿着这把锄头，去把我想要的宝物挖回来领赏就可以了！\n");
  ob->set_temp("random_job",1);
  return 1;
}


string *dirs1=({
"/d/xiangyang","/d/jiujiang",
"/d/chengdu",
});

string *dirs2=({
"/d/taishan","/d/huashan",
"/d/hengshan","/d/wuyishan"
});

string *dirs3=({
"/d/changan","/d/taiyuan","/d/suiye"
});

string *dirs4=({
"/d/dongming","/d/baling","/d/dingxiang",
"/d/saiwai"
});

int do_ok(string arg)
{
  object ob,thing,killer;
  string *dirs;
  
  
  ob=this_player();
  
  if(!arg)
  return notify_fail("飞云子一瞪眼：你拿什么来领赏啊？\n");
  if(!objectp(thing=present(arg,ob)))
  return notify_fail("飞云子冷笑道:你根本没有这个东西，想来骗我吗？\n");
  if(!thing->query("baowu"))
  return notify_fail("飞云子砰地一声踹了你一脚：这种破烂也来骗我！！\n");
  
  if(thing->query("owner")!=ob)
  return notify_fail("这是你挖到的宝物吗？？\n");
  
  if(ob->query("combat_exp")>=1000000&&
     !ob->query_temp("killed_fyz_killer")){
  
  if(ob->query("combat_exp")<400000)
   dirs=dirs1;
  else
  if(ob->query("combat_exp")<600000)
   dirs=dirs1+dirs2;
  else
  if(ob->query("combat_exp")<800000)
   dirs=dirs1+dirs2+dirs3;
  else
  dirs=dirs1+dirs2+dirs3+dirs4;
  
  killer=new(__DIR__"killer");
  killer->set_status(ob);
  
  
  if(!random_place(killer,dirs))
   return notify_fail("你觉得四周隐约有杀气闪现，不由得停了手！\n");
  
  if(!environment(killer))
   return notify_fail("你觉得四周隐约有杀气闪现，不由得停了手！\n");
  
  message_vision("\n只见一个黑影从$N身后闪过，抢了"+thing->query("name")+
  "转身跑了！！\n\n",ob);
  thing->move(killer);
  
  tell_object(ob,"你一楞神，旋即大声喊道：臭贼！往哪里跑！！\n");
  ob->move(environment(killer));
  tell_room(environment(),ob->name()+"身行一晃，朝盗贼追去！！\n");
  message_vision(HIW"$N"+HIW+"快步拦在$n"+HIW+"面前：臭贼，将宝物还给我！！\n"NOR,ob,killer);
  killer->kill_ob(ob);
  ob->add_temp_array("job_temp_killer",killer);
  return 1;
  }
  
  message_vision("飞云子看着$N手中的"+thing->name()+",双眼发直：对，这就是我想要的宝物！\n",ob);
  destruct(thing);
  if(present("chu tou",ob))
  destruct(present("chu tou",ob));
  
  ob->set("busy_time",time());
  ob->delete_temp("random_job");
  ob->delete_temp("dtsl_job");
  ob->delete_temp("killed_fyz_killer");
  
  JOBSYS_D->give_reward_feiyunzi(ob);
  
  return 1;
}

int accept_fight(object who)
{
   return notify_fail("你别打鬼主意了！\n");
}

void kill_ob(object ob)
{
   tell_object(ob,"你别打鬼主意了！\n");
   ob->remove_killer(this_object());
   return;
}
