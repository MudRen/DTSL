
inherit NPC;
#include <ansi.h>
#include <job_money.h>
#include "pass.h"
string give_job();
int cancel_job();
int do_ok(string arg);

string *dirs1=({
"/d/changan",
});

string *dirs2=({
"/d/taishan","/d/mangshan","/d/pengliang",
});

string *dirs3=({
"/d/emeishan","/d/hengshan"
});



void create()
{
   set_name("张军官",({ "zhang junguan","zhang","junguan" }) );
        set("gender", "男性" );
        set("age", 35);
   set("long", "他是突厥的一名军官，专门负责突厥的情报工作。\n");
       
   set("combat_exp",200000);
   set("str", 30);
   set("per",10+random(20));
   set_skill("parry",30);
   set_skill("unarmed",30);
   set_skill("dodge",30);
   set("force",200);
   set("max_force",200);
   set_skill("force",30);
   set("inquiry",([
	   "job":(:give_job:),
	   "放弃":(:cancel_job:),
	   ]));
   
   set("target_id","####");//防止别人用 ansha 等命令杀他。
   
   setup();
   
}

void init()
{
	add_action("do_ok","jiaochai");
}

string give_job()
{
	object me;
	object target,paper;
	string *dirs,password;
	
	
	me=this_player();
	
	if(me->query_temp("tujue_jieying_job"))
	return "你还是快去吧！\n";
	
	if(me->query("combat_exp")<100000)
	 return "你的本领太低了，歇着去吧！\n";
	
  	if(time()-me->query("busy_time")<=40+random(5))
		return "你先歇歇吧！\n";
	if(me->query_temp("dtsl_job"))
   return "你正在做其他任务，先忙其他的吧！\n";
                
	target=new(__DIR__"mitan");
	target->set("last",time());	
	target->set("target",me);
	
	me->set_temp("target",target);
	target->add_array("target_id",me->query("id"));
	
	if(me->query("combat_exp")<300000)
	 dirs=dirs1;
	else
	if(me->query("combat_exp")<800000)
	 dirs=dirs1+dirs2;
	else
	 dirs=dirs1+dirs2+dirs3;
	
	if(!random_place(target,dirs))
	 return "突厥密探现在在哪里呢？让我想想... ...\n";
	
	target->set("long",query("long")+"据说突厥已经派"+me->name()+"来接应他了。\n");
		
	tell_object(me,query("name")+"给了你一个卷轴。\n");
	
	if(!(environment(target)))
          return "突厥密探现在在哪里呢？让我想想... ...\n";
        
        password=pass[random(sizeof(pass))]+" "+
        pass[random(sizeof(pass))];
        
        paper=new(__DIR__"paper");
	paper->set("target",target);
	paper->set("pass",password);
	paper->move(me);
	
        
	me->set_temp("dtsl_job","突厥接应密探任务");
	me->set_temp("tujue_jieying_job",1);
	me->add_temp_array("job_temp_killer",target);
	return "好吧,既然"+RANK_D->query_respect(me)+"愿意，你就去"+MISC_D->find_place(environment(target))+"\n去接应我们的"+target->name()+"吧！\n"+
	"本次接应的暗号是："+HIY+password+NOR+CYN+"，可千万不要忘记了！\n";
}

int do_ok(string arg)
{
	object me,ob,paper;
	
	
	me=this_player();
	
	if(!arg){
	command("heng");
	command("say 和我交付任务可不是这样的！");
	return 1;}
	
	if(!me->query_temp("tujue_jieying_job")){
	command("?");
	command("say 你在说什么？");
	return 1;}
	
	
		
	if(!objectp(ob=present(arg,environment(me)))){
		command("?");
	command("say 这里没有这个人啊！");
	return 1;}
	
	if(ob==me){
	
	 	command("kok "+me->query("id"));
	        command("say 你敢来我这里捣乱？？");
	 
	return 1;}
		
        if(ob->query("target")!=me){
        command("papaya "+me->query("id"));
	command("say 你接应错了！！！");
	return 1;}
	
	if(!ob->query("pass_ok")){
        command("sigh "+me->query("id"));
	command("say 你没和他对暗号，我怎么知道他是不是真的密探？");
	return 1;}
	
        if(objectp(paper=present("juan zhou",me)))
        destruct(paper);
                
        tell_object(environment(me),query("name")+"回头道：来人，把"+ob->name()+"快领到军机处！\n");
	tell_object(environment(me),"立刻出来一个人，把"+ob->name()+"领走了。\n");
	destruct(ob);
	
	JOBSYS_D->give_reward_tujuejy(me);
	
	me->delete_temp("tujue_jieying_job");
	me->delete_temp("come_killer");
	me->delete_temp("dtsl_job");
	me->delete_temp("target");	
	me->set("busy_time",time());	
	
	return 1;
}

int cancel_job()
{
   object ob;
   
   ob=this_player();
   
   if(!ob->query_temp("tujue_jieying_job")){
	command("? "+ob->query("id"));
	command("say 你在说什么？");
	return 1;}
   
   JOBSYS_D->do_cancel_job("tujuejy",ob,this_object());
        
	if(objectp(present("juan zhou",ob)))
        destruct(present("juan zhou",ob));
        
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