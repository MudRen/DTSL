// 大唐双龙传

//官兵


inherit NPC;

#include <ansi.h>
#include <job_money.h>

string give_job();
int do_ok(string arg);
int cancel_job();

void create()
{
        set_name(HIY"官兵"NOR, ({ "guan bing", "bing"}) );
        set("gender", "男性");
        set("age", 35);
        set("long","这是高丽衙门的官兵，总管高丽的治安。\n");
        set("combat_exp", 300000+random(40000));
        set("attitude", "heroism");
        set("str", 30);
        set("max_kee", 1000);
        set("max_sen", 500);
        set("max_gin", 700);
        set("force", 400);
        set("max_force", 500);
        set("force_factor", 25);
        set_skill("blade", 100);
        set_skill("unarmed", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("force", 100);
        set("target_id","###");
        set("inquiry",([
         "job":(:give_job:),
         "巡逻":(:give_job:),
         "放弃":(:cancel_job:),
         
         ]));
        setup();

        carry_object("/d/gaoli/obj/gangdao")->wield();
        carry_object("/d/gaoli/obj/armor")->wear();
}

void init()
{
  add_action("do_ok","task");
}
string give_job()
{
  object me;
  me=this_player();
  if(me->query("combat_exp")>100000)
  return "让你做这么简单工作真是太可惜了！\n";
  if(me->query_temp("gaoli_xunluo"))
  return "我可不喜欢做事马虎的人！";
  if(time()-me->query_temp("gaoli_xunluo_busy")<40)
  return "你先歇歇再干活吧！\n";
  me->set_temp("gaoli_xunluo",1);
  return "好吧，麻烦"+RANK_D->query_respect(me)+"去高丽的周围巡逻一下吧！\n";
}

int do_ok(string arg)
{
  object me;string *here;
  me=this_player();
  
  if(!arg||arg!="ok")
  return notify_fail("什么？\n");
  if(!me->query_temp("gaoli_xunluo"))
  return notify_fail("什么？\n");
  here=me->query_temp("xunluo_dir");
  if(sizeof(here)<16)
  return notify_fail("你漏掉地方了，再仔细看看吧！\n");
  
  me->set("busy_time",time());
  me->delete_temp("xunluo_dir");
  me->delete_temp("gaoli_xunluo");
  JOBSYS_D->give_reward_xunluojob(me);
  return 1;
}

int cancel_job()
{
   object ob;
   
   ob=this_player();
   
   if(!ob->query_temp("gaoli_xunluo")){
   command("?");
   return 1;
   }
   
   JOBSYS_D->do_cancel_job("gaolixunluo",ob,this_object());
   
   command("heng");
   return 1;
}