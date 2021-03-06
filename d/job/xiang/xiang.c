
inherit NPC;
#include <ansi.h>
#include <job_money.h>
string give_job();
int cancel_job();
int do_ok(string arg);
int do_action1();

string *dir=({
"/d/hangzhou","/d/yangzhou","/d/pengliang",
"/d/taishan"});

void create()
{
   set_name("香玉山",({ "xiang yushan","xiang","yushan" }) );
   set("gender", "男性" );
   set("age", 25);
   set("long", "他是[巴陵帮]的香玉山。\n");
       
   set("combat_exp",80000);
   set("str", 10);
   set("per", 25);
   set_skill("parry",30);
   set_skill("unarmed",30);
   set_skill("dodge",30);
   set("force",200);
   set("max_force",200);
   set_skill("force",30);
   set("attitude", "peaceful");
   set("inquiry",([
	   "贩卖人口":(:give_job:),
	   "放弃":(:cancel_job:),
	   "救人":(:do_action1:),
	   ]));
   
   set("target_id","####");//防止别人用 ansha 等命令杀他。
   
   setup();
   carry_object(__DIR__"chouyi")->wear();
  
}

void init()
{
	add_action("do_ok","jiaochai");
}

string give_job()
{
	object me;
	object target,guard,mixiang;
	
	
	me=this_player();
	
	if(me->query_temp("fanmai_job"))
	return "你还是快去吧！\n";
	
	if(me->query("combat_exp")<100000)
	 return "你的本领太低了，歇着去吧！\n";
	
  	if(time()-me->query("busy_time")<=40+random(5))
		return "你先歇歇吧！\n";
	if(me->query_temp("dtsl_job"))
   return "你正在做其他任务，先忙其他的吧！\n";
   if(!valid_do_job(me,"qiangjie"))
	return "你的武功很高了，做这样的小事真是大才小用了！\n";
                
	target=new(__DIR__"girl");
	target->set("last",time());
	mixiang=new(__DIR__"mixiang");
	target->set("target",me);
	me->set_temp("target",target);
	target->set("target_id",me->query("id"));
	mixiang->set("target",target);
	mixiang->move(me);
	
	if(!random_place(target,dir))
	 return "现在哪里的女人比较受欢迎呢？让我想想... ...\n";
	
	target->set("long",query("long")+"据说香玉山最近已经派新入门的人贩子"+me->name()+"来抢劫她了。\n");
		
	tell_object(me,"香玉山给了你一个迷香。\n");
	tell_object(me,"香玉山诡笑道： 我们妓院最近需要几个姑娘。\n");
	
	if(!(environment(target)))
          return "现在哪里的女人比较受欢迎呢？让我想想... ...\n";
        
        guard=new(__DIR__"guard");
        guard->set_status(me);
        guard->move(environment(target));
        guard->set_leader(target);
        
	me->set_temp("dtsl_job","香玉山贩卖人口任务");
	me->set_temp("fanmai_job",1);
	me->add_temp_array("job_temp_killer",target);
	me->add_temp_array("job_temp_killer",guard);
	return "好吧,既然"+RANK_D->query_respect(me)+"愿意，你就去"+MISC_D->find_place(environment(target))+"\n找"+target->name()+"来给我，我不会亏待你的！\n";
}

int do_ok(string arg)
{
	object me,ob,mixiang;
	
	
	me=this_player();
	
	if(!arg){
	command("grin");
	command("say 没有女人，拿什么来交差？？");
	return 1;}
	
	if(!me->query_temp("fanmai_job")){
	command("?");
	command("say 你在说什么？");
	return 1;}
	
	
		
	if(
	!objectp(ob=present(arg,me))&&
	!objectp(ob=present(arg,environment(me)))){
		command("?");
	command("say 没有这个人啊！");
	return 1;}
	
	if(ob==me){
	
	 if(me->query("gender")=="女性"){
		command("grin");
	        command("say 好哇，今天晚上我等你... ...");
	        }
	 else{
	     command("pei");
	        command("say 我可不好这个！");
	       }
	return 1;}
	
	if(ob->query("gender")=="男性"){
		command("shake");
	command("say 男人我可不要！");
	return 1;}
        if(ob->query("target")!=me){
        command("kok "+me->query("id"));
	command("say 你抓错人了！");
	return 1;}
	
        if(objectp(mixiang=present("mixiang",me)))
        destruct(mixiang);
        
        tell_object(environment(me),"香玉山回头道：来人，把这位姑娘领进去！\n");
	tell_object(environment(me),"立刻出来一个人，把"+ob->name()+"领进去了。\n");
	destruct(ob);
	
	me->delete_temp("fanmai_job");
	me->delete_temp("come_guard");
	me->delete_temp("dtsl_job");
	me->delete_temp("target");
		
	me->set("busy_time",time());
	if(me->query("gender")=="女性")
	tell_object(me,"没想到现在女人都这么坏了，唉... ...\n");
	
	JOBSYS_D->give_reward_xiangfanmai(me);	
	return 1;
}

int cancel_job()
{
   object ob;
   
   ob=this_player();
   
   if(!ob->query_temp("fanmai_job")){
	command("pei "+ob->query("id"));
	command("say 你在说什么？");
	return 1;}
   
   JOBSYS_D->do_cancel_job("fanmaijob",ob,this_object());
   

	
	if(objectp(present("mixiang",ob)))
        destruct(present("mixiang",ob));
        
        if(objectp(ob->query_temp("target")))
          destruct(ob->query_temp("target"));
	
     command("sigh "+ob->query("id"));
     command("say 既然你这么没用，我也没有办法了！\n");
     return 1;
}

int accept_fight(object who)
{
   return 0;
}

void kill_ob(object ob)
{
  ob->remove_killer(this_object());
  command("bi "+ob->query("id"));
  return;
}

int accept_object(object ob,object obj)
{
   object target,killer;
   
   if(obj->query("daughter")!="lianrou")
   return 0;
   
   if(ob->query("dtsl_quest_ysdodge_help_ok"))
   return 0;
   
   command("grin");
   command("say 你可真行啊，找来这么漂亮的女人！\n");
   message_vision("$N一挥手，出来一个手下，把莲柔带走了！\n",this_object());
   target=new("/d/quest/yunshuai-dodge/lianrou");
   killer=new(__DIR__"killer");
   copy_object(target,obj);
   target->move("/d/quest/yunshuai-dodge/migong8");
   killer->set_status(ob);
   killer->move("/d/quest/yunshuai-dodge/migong8");
   ob->set("dtsl_quest_ysdodge_help_ok",1);
   return 1;
}

int do_action1()
{
   object ob;
   
   ob=this_player();
   
   if(ob->query_skill("jiuying-dodge",1)){
     command("say 你甭想打这个歪主意了！\n");
     return 1;
   }
      
   command("say 好，敢来我这里救人，有胆量，就怕你是有去无回！");
   ob->move("/d/quest/yunshuai-dodge/migong1");
   
   return 1;
}