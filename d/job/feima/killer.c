
inherit NPC;
#include <ansi.h>
#include <job_money.h>

string do_zhaoxiang();
void create()
{
   set_name("陶叔盛",({ "tao shusheng","tao"}) );
        set("gender", "男性" );
        set("age", 40);
        set_skill("force",100);
        set_skill("tianmo-huanzong",100);
        set_skill("tianmo-dafa",100);
        set_skill("parry",100);
        set_skill("linglong-yuquan",100);
        // set_skill("pojun-quan",100);
        set_skill("dujie-zhi",100);
        set_skill("cuff",100);
        set_skill("finger",100);
        set_skill("dodge",100);
        set_temp("apply/armor",30);
   set("long", "他就是飞马牧场的四大执事之三。\n");
   set("inquiry",([
       "招降":(:do_zhaoxiang:),
       ]));
   setup();

}

int kill_object(object killer,object victim)
{
  if(query("target_id")==victim->query("target_id")){
   message_vision(HIR"$N纵声大笑：就凭你也想缉杀本大爷！\n"NOR,killer);
   destruct(killer);
   return 1;}
  return 1;
}

void init()
{
  set("last",time());
}

int clear()
{
  if(time()-query("last")<300)
  return 0;
  if(!query("no_msg")){
  message_vision("$N匆匆地走了。\n",this_object());
  set("no_msg",1);
  call_out("dispear",1);}
  return 1;
}

void dispear()
{
   destruct(this_object());
   return;
}

int chat()
{
   object ob;
   if(clear())
   return 1;
   ob=query_temp("last_damage_from");
   if(!ob) return ::chat();
   if(!ob->query_temp("shang_kill_pantu")||
     query("target_id")!=ob->query("id"))
   return ::chat();
   if(query("zx_flag"))
   return ::chat();
   if(query("eff_kee")*100/query("max_kee")<JOBSYS_D->get_up_lev())
     if(random(100)<JOBSYS_D->get_random_lev())
       return ::chat();
     else{
      if(!query("no_msg"))
      tell_object(ob,HIC+query("name")+"准备投降了，如果想招降"+query("name")+"，请使用\n"+
                     "ask xxx about 招降 命令！\n"NOR);
      set("no_msg",1);
      ob->set_temp("shang_kill_pantu_zx",this_object());
      set("busy_time",time());
      return ::chat();}
   else return ::chat();
   return ::chat();
}

string do_zhaoxiang()
{
   object ob;
   object thing;

   ob=this_player();
   if(!ob->query_temp("shang_kill_pantu_zx"))
   return "你说什么呢？老子一点也不懂啊！\n";
   if(ob->query_temp("shang_kill_pantu_zx")!=this_object())
   return "你说什么呢？老子一点也不懂啊！\n";
   set("zx_flag",1);
   ob->remove_all_enemy();
   this_object()->remove_all_enemy();
   if(!query("no_fight"))
   message_vision("\n$N和$n身行向后一跃，跳出战圈！\n",ob,this_object());
   set("no_fight",1);
   if(time()-query("busy_time")<30)
   return "你容我再想一想！\n";

   ob->delete_temp("shang_kill_pantu_zx");
   ob->set_temp("zhaoxiang_killer",1);
   if(random(2)==1){
     kill_ob(ob);
     return "大爷我改变主意了，要杀要剐随你的便了！\n";}
    thing=new("/d/job/funjob/thing");
    thing->move(ob);
    tell_object(ob,query("name")+"给了你一个"+thing->query("name")+"。\n");

   return "看在宝物的份上，能不能放过在下？";

}
