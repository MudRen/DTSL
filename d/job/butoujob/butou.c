
inherit NPC;

#include <ansi.h>
#include <job_money.h>

#define INTER 3
#define COUNT 10

object *killers=({});

string *dirs=({
"/d/hengshan",
"/d/taishan",
"/d/huashan",
"/d/emeishan",
"/d/tuyuhun"
});

int give_job();
int do_ok(string arg);
void start_job();

nosave int job_flag=0;


void create()
{
   set_name("捕头",({ "bu tou","bu","tou" }) );
        set("gender", "男性" );
        set("age", 32);
   set("long", "这是长安的捕头，管理长安城的治安。\n");

   set("combat_exp", 200000);
   set("str", 28);
set("target_id","####");
   set("per", 23);
   set("attitude", "peaceful");
   set_skill("unarmed",70);
   set_skill("parry",70);
   set_skill("dodge",70);
   set_skill("force",70);
   set("max_force",200);
   set("force",200);
   set("inquiry",([
	   "盗贼":(:give_job:),
	   ]));
   setup();


}


string get_exp_msg(object ob)
{
  int exp;
  exp=ob->query("combat_exp");
  if(exp<=300000)
   return HIB"小贼"NOR;
  if(exp<=500000)
   return HIC"飞贼"NOR;
  if(exp<=800000)
   return HIG"大盗"NOR;
  if(exp<=1500000)
   return HIW"巨盗"NOR;
  if(exp<=2500000)
   return HIR"恶盗"NOR;
  return HIR"凶盗"NOR;
}


int give_job()
{
	object ob;
	int i;
	string msg;

        start_job();

	ob=this_player();
	msg="";

	if(sizeof(killers)<=0){
	tell_object(ob,"目前治安良好，没有盗贼。\n");
	return 1;}

        for(i=0;i<sizeof(killers);i++){

         if(!objectp(killers[i])) continue;
         if(!environment(killers[i])) continue;
         if(!living(killers[i])) continue;
          msg +=get_exp_msg(killers[i])+" "+killers[i]->name()+" "+
           "躲藏在"+MISC_D->find_place(environment(killers[i]))+"";
          if(killers[i]->is_fighting())
           msg +="  "+HIR"(正在被追杀中)"NOR;
           msg +="\n\n";
        }
        if(msg==""){
        tell_object(ob,"目前治安良好，没有盗贼。\n");
	return 1;}

        msg=HIG"\n\n目前捕头通缉以下要犯：\n\n"NOR+
            HIB"━━━━━━━━━━━━━━━━━━━━━━━\n\n"NOR+msg+"\n";
        msg +=HIB"━━━━━━━━━━━━━━━━━━━━━━━\n"NOR;
        ob->start_more(msg);
        tell_object(ob,query("name")+"说道：盗贼有强有弱，你要量力而行！\n\n");
        if(random(10)>5)
        command("addoil "+ob->query("id"));
        return 1;
	//return "对不起，这个任务还在修改中。\n";

}

void clean_killers()
{
   object *ob;
   int i,j;

   ob=children(__DIR__"killer");
   for(i=0,j=0;i<sizeof(ob);i++){
         if(ob[i]){
         destruct(ob[i]);
         j++;}

        }
   CHANNEL_D->do_channel(this_object(),"sys","长安捕头任务清除"+j+"个盗贼变量。\n");
}

void check_job()
{
  if(job_flag>=INTER){
   job_flag=0;
   start_job();

   return;
   }
   remove_call_out("check_job");
   call_out("check_job",300);
   job_flag++;
   return;
}

void start_job()
{
   object killer;

   int i;

   if(job_flag>0)
    return;

   remove_call_out("start_job");
   call_out("check_job",300);
   job_flag++;

   clean_killers();

   for(i=0;i<COUNT;i++){
     killer=new(__DIR__"killer");
     killer->set_status();
     killer->set("title",HBYEL+get_exp_msg(killer));
     if(!random_place(killer,dirs)){
     	 i--;
     	 destruct(killer);
     	 continue;}
     	  if(!environment(killer)){
     	 i--;
     	 destruct(killer);
     	 continue;}
     	killers +=({killer});
        }
     CHANNEL_D->do_channel(this_object(),"sys","长安捕头任务更新。\n");

     return;
}
