#include <ansi.h>
inherit NPC;
#include <job_money.h>
string give_job();
int i=3;
void create()
{
   set_name("不智",({ "bu zhi","bu","zhi"}));
        set("gender", "男性" );
        set("age", 32);
   set("long", "这是静念禅院的得道高僧,他的佛经水平可是相当高的。\n");
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
   set_skill("chanzong-fofa",100);
//    set_skill("jinguang-daofa",150);
//    set_skill("wuxiang-zhangfa",90);
   set("staff",({"wuxiang-zhangfa"}));
   set_skill("liuyun",150);
   set("dodge",({"liuyun"}));
    create_family("静念禅院",5,"僧人");
	set("inquiry",([
		"讲经":(:give_job:),
		"菩提本非树,明镜亦非台":"本来无一物,何处惹尘埃",
		"何名坐禅":"内见自性不动，名为禅",
		"何名禅定":"外禅内定，是为禅定",
		]));
   setup();
   carry_object(__DIR__"obj/sengyi")->wear();
   carry_object(__DIR__"obj/staff")->wield();

}

void init()
{
	object ob,ob2;
	ob=this_player();
	ob2=this_object();
	::init();
	if(!ob||!present(ob,environment())) return;

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
	remove_call_out("welcome");
	return;
}

string give_job()
{
	object ob,me;string str;
	ob=this_object();me=this_player();

	if(me->query("class")!="bonze") return "不是佛家弟子,如何去讲经传法?\n";
	if((int)me->query_skill("chanzong-fofa",1)<=30)
		return "你的[禅宗佛法]修为太低了,还是先学习吧!\n";
	if(me->query_temp("buzhi_jiangjing"))
		return "你还是先做完手中的事吧!马马虎虎,怎么可以?\n";
	if(time()-me->query("busy_time")<120)
	return "你还是歇歇吧！\n";
	if(me->query_temp("dtsl_job"))
        return "你正在做其他任务，先忙其他的吧！\n";
        if(!valid_do_job(me,"jiangjing"))
	return "你的佛法修为已经很高了，不用再出去讲经了！\n";
	me->set("busy_time",time());
	me->set_temp("dtsl_job","静念禅院讲经任务");
	if((int)me->query("combat_exp",1)>=100000)
	{ call_out("killer_jj",15,me);str="路上可能有恶人,你要小心!\n";
	  me->set_temp("other_give",100);
	}
	else str="\n";
	switch(random(i))
	{
	case 0: me->set_temp("buzhi_jiangjing/1",1);return "好吧,你去成都的一个寺庙去讲经吧!\n"+str;
	case 1: me->set_temp("buzhi_jiangjing/2",1);return "好吧,你去扬州的白马寺去讲经吧!\n"+str;
	case 2: me->set_temp("buzhi_jiangjing/3",1);return "好吧,你去长安的宝象寺去讲经吧!\n"+str;

	}
}

void killer_jj(object me)
{
	object killer;
	if(!objectp(me)||!me->query_temp("buzhi_jiangjing")) {remove_call_out("killer_jj");return;}
	if(me->query_temp("buzhi_jiangjing"))
	{
		killer=new(__DIR__"killer");
	killer->set("combat_exp",(int)me->query("combat_exp",1)-20);
	copy_object(killer,me);
	set_all_skill(killer,me->query("max_pot")-140);
	killer->set_name("杀手",({"killer"}));
	killer->delete("family");
	killer->delete("nickname");
	killer->delete("shili");
	killer->move(environment(me));
	message_vision(HIR"$N朝$n冷笑道:什么佛法佛经,老子就不信这个,你就把小命留在这里好了!\n"NOR,killer,me);
	message_vision("$N似乎跟上$n了!\n",killer,me);
	me->start_busy(1);
	killer->set_leader(me);
	killer->kill_ob(me);
	}
	remove_call_out("killer_jj");
	return;
}
