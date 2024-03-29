
inherit NPC;

#include <ansi.h>
#include <job_money.h>

string give_job();
int do_ok(string arg);

string *dir1=({
"/d/huashan","/d/changan"
});

string *dir2=({
"/d/emeishan","/d/wuyishan"
});

string *dir3=({
"/d/taishan","/d/hengshan"
});

void create()
{
   set_name("不智",({ "bu zhi","bu","zhi"}));
        set("gender", "男性" );
        set("age", 32);
   set("long", "这是静念禅院的得道高僧，他的佛经水平可是相当高的。\n");
   set("class","bonze");
   set("combat_exp", 400000);
   set("str", 28);
   set("per", 22);
   set("attitude", "peaceful");
   set_skill("dodge",80);
   set_skill("parry",90);
   set_skill("staff",90);
   set_skill("force",150);
   set_skill("blade",150);
   set_skill("chanzong-fofa",150);
//    set_skill("chanzong-fofa",100);
//    set_skill("jinguang-daofa",150);
//    set_skill("wuxiang-zhangfa",90);
   set_skill("liuyun",150);

   set("target_id","####");//防止别人用 ansha 等命令杀他。

    create_family("静念禅院",5,"僧人");
	set("inquiry",([
		"经书":(:give_job:),
		"菩提本非树,明镜亦非台":"本来无一物,何处惹尘埃",
		"何名坐禅":"内见自性不动，名为禅",
		"何名禅定":"外禅内定，是为禅定",
		]));
   setup();
   carry_object("/d/chanyuan/npc/obj/sengyi")->wear();
   carry_object("/d/chanyuan/npc/obj/staff")->wield();

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

void init()
{
	object ob,ob2;

	add_action("do_ok","jiaochai");

	ob=this_player();
	ob2=this_object();
	::init();
	if(!ob||!present(ob,environment())) return;
	remove_call_out("welcome");
	call_out("welcome",1,ob,ob2);

}

void welcome(object ob,object ob2)
{
   if(!ob||!present(ob,environment())) return;
	switch(random(2))
	{
	case 0: message_vision("$N低声诵道：阿弥陀佛!\n",ob2);break;
	case 1: message_vision("$N对$n道：佛渡有缘人。\n",ob2,ob);
	}

	return;
}

string give_job()
{
	object ob,me;
	string str,*dirs;

	me=this_player();

	if(me->query("class")!="bonze")
	return "这样的事情还是我们佛门弟子自己解决吧！\n";

	if(me->query("combat_exp")<100000)
	return "你的能力还不足够抢回经书！\n";

	if(me->query_temp("buzhi_jiangjing"))
		return "你还是先做完手中的事吧!马马虎虎,怎么可以?\n";


	      if(time()-me->query("busy_time")<40+random(5))
	          return "你还是歇歇吧！\n";

	if(me->query_temp("dtsl_job"))
        return "你正在做其他任务，先忙其他的吧！\n";

        if(!valid_do_job(me,"jiangjing"))
	return "让你做这样的事真是太委屈了！\n";

	if(me->query("combat_exp")<400000)
	  dirs=dir1;
	else
	  if(me->query("combat_exp")<800000)
	  dirs=dir1+dir2;
	else
	  dirs=dir1+dir2+dir3;

	ob=new(__DIR__"killer");

	if(!ob->set_status(me))
	return "抢夺经书的人出了问题，快去报告巫师吧！\n";

	if(!random_place(ob,dirs))
	return "抢夺经书的人在哪里呢？让我想想... ...\n";

	if(!environment(ob))
	return "抢夺经书的人在哪里呢？让我想想... ...\n";

	me->set_temp("dtsl_job","静念禅院讲经任务");
	me->set_temp("buzhi_jiangjing",1);

	return "前几天有个叫"+ob->name()+CYN+"的人偷走了寺中的经书，\n"+
	"据说他现在躲藏在"+MISC_D->find_place(environment(ob))+CYN+"，你速去把经书抢夺回来！\n";

}

int do_ok(string arg)
{
   object ob,book;
   string name;


   ob=this_player();


   if(!ob->query_temp("buzhi_jiangjing")){
    command("?");
    command("say 你想做什么？");
    return 1;}

   if(!arg||sscanf(arg,"with %s",name)!=1){
   	command("hehe");
   return notify_fail("请使用 jiaochai with xxx 来完成任务。\n");
   }

   if(!objectp(book=present(name,ob))){
   	command("kok "+ob->query("id"));
   	command("say 出家人怎么还说谎话？");
   	return 1;
    }


        ob->delete_temp("dtsl_job");
        ob->delete_temp("buzhi_jiangjing");
        ob->set("busy_time",time());
       command("say "+RANK_D->query_respect(ob)+"果然勇敢！我代表藏经阁谢谢你了！");
       destruct(book);

       JOBSYS_D->give_reward_jj(ob);

     return 1;
}
