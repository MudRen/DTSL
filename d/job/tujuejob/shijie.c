
inherit NPC;
#include <ansi.h>
#include <job_money.h>

string *dirs=({
"/d/huashan"
});

string give_job();
int do_ok(string arg);
int cancel_job();

void create()
{
   set_name("牧人",({ "mu ren","mu","ren"}) );
        set("gender", "男性" );
		
        set("age",30+random(10));
   set("long", "这是一位突厥的放牧人。\n");
       
   set("combat_exp", 500000);
   set("str",30);
   
   set_skill("parry",120);
   set_skill("dodge",120);
   set_skill("force",120);
   set("force",1000);
   set("max_force",1000);
   
   set("target_id","####");
 
   set("inquiry",([
      "job":(:give_job:),
      "放弃":(:cancel_job:),
      ]));
   setup();
  
}

int accept_fight(object who)
{
  return 0;
}

void init()
{
   add_action("do_ok","task");
}

string give_job()
{
  object ob,sheep,room;
  string where;
  int i;
  
  ob=this_player();
  
   if(ob->query("family/family_name")!="突厥")
   return "只有突厥的弟子才可以做这个任务。\n";
   
   if(ob->query("combat_exp")>=100000)
   return "凭你的身手做这样的事情真是可惜了！\n";
   
   if(ob->query_temp("tujue_fangmu"))
   return "你做事可要有头有尾，不要马马乎乎。\n";
   
   if(time()-ob->query("busy_time")<40+random(20))
   return "年轻人做事何必急于一时呢，还是先歇会吧！\n";
   
   if(ob->query_temp("dtsl_job"))
   return "你正在做其他任务，先忙其他的吧！\n";
   
   ob->set_temp("dtsl_job","突厥放牧任务");
   ob->set_temp("tujue_fangmu",1);
   
   where=get_random_place(dirs);
   
   sheep=new(__DIR__"sheep");
   sheep->set("owner",ob);
   sheep->set("place",where);
   sheep->set("long","这是一只由"+ob->name()+"负责放养的绵羊。\n");
   sheep->move(environment(ob));
   sheep->set_leader(ob);
   ob->add_temp_array("job_temp_killer",sheep);
   room=load_object(where);
 
    return "好吧，麻烦你去"+MISC_D->find_place(room)+"放"+sheep->query("name")+
    "吧(wei sheep)！\n";
}

int do_ok(string arg)
{
   object ob,target;
   string paper_name;
   
   
   ob=this_player();
   
   if(!arg||sscanf(arg,"ok with %s",paper_name)!=1)
   return notify_fail("你得使用 task ok with xx 来交差。\n");
   if(!ob->query_temp("tujue_fangmu"))
  return notify_fail("你没有向"+query("name")+"要这个任务。\n");
   if(!objectp(target=present(paper_name,environment(ob))))
   return notify_fail("这里没有这个东西！\n");
   if(target->query("owner")!=ob)
  return notify_fail("这不是你的羊！\n");
   if(!target->query("job_ok"))
   return notify_fail("羊还没吃饱呢！\n");
   
  tell_object(ob,query("name")+"拍拍你的头：好，干得不错！\n");
  
   destruct(target);
      
   ob->delete_temp("tujue_fangmu");
   ob->delete_temp("dtsl_job");
   ob->set("busy_time",time());
   
   JOBSYS_D->give_reward_tjchujijob(ob);
   
   return 1;
}

int cancel_job()
{
  object ob;
  
  ob=this_player();
  
  if(!ob->query_temp("tujue_fangmu")){
    command("?");
    return 1;
  }
  
  JOBSYS_D->do_cancel_job("tjchujijob",ob,this_object());
  command("sigh");
  return 1;
}