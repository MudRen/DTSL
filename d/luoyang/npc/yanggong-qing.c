#include <ansi.h>
#include <job_money.h>
inherit NPC;
string give_job();
void create()
{
   set_name("杨公卿",({ "yang gongqing","yang","gong","qing" }) );
        set("gender", "男性" );
        set("age", 42);
   set("long", "他就是王世充的主要军师人物。\n");

   set("combat_exp", 200000);
   set("str", 20);
   set("per", 20);
   set("shili","wang");
   set("attitude", "peaceful");
   set_skill("dodge",100);
   set_skill("unarmed",100);
   set_skill("parry",100);
   set("inquiry",([
	   "叛徒":(:give_job:),
	   ]));
   setup();
   carry_object(__DIR__"obj/guanfu")->wear();

}

string give_job()
{
	object me;
	me=this_player();
	if(me->query_temp("yang_kill_pantu"))
		return ""+RANK_D->query_respect(me)+",王大人可不喜欢做事不认真的人啊!\n";
	if(time()-(int)me->query("busy_time",1)<=120)
		return ""+RANK_D->query_respect(me)+",你还是先歇歇吧!\n";
	if(me->query_temp("dtsl_job"))
        return "你正在做其他任务，先忙其他的吧！\n";
        if(!valid_do_job(me,"killpantu"))
	return "你的武功很高了，做这样的小事真是大才小用了！\n";
        me->set_temp("dtsl_job","杨公卿杀叛徒任务");
	switch(random(3))
	{   case 0:
		me->set_temp("yang_kill_pantu/1",1);
	     return "好吧,那么请"+RANK_D->query_respect(me)+"帮我们去[老君观]杀了可风那个妖道!\n别忘了拿回他的首级!\n";
        break;
	case 1:
		me->set_temp("yang_kill_pantu/2",1);
	     return "好吧,那么请"+RANK_D->query_respect(me)+"帮我们去峨眉山杀了可风那个妖道!\n别忘了拿回他的首级!\n";
        break;
	case 2:
		me->set_temp("yang_kill_pantu/3",1);
	     return "好吧,那么请"+RANK_D->query_respect(me)+"帮我们去岭南杀了可风那个妖道!\n别忘了拿回他的首级!\n";
        break;
	}
}

int accept_object(object me,object ob)
{
	int exp,pot,sil,famous,exp2;
	object npc;
	npc=this_object();
	if(!me->query_temp("yang_kill_pantu")) return 0;
	if((string)ob->query("dead_id")!="ke feng") return 0;
	if(ob->query("killed_by")!=me->query("id")) return 0;
	pot=me->query("max_pot")/3;
	exp=200+random(20);
	sil = 200 + random(200);
	me->add("combat_exp",exp);
	me->add("potential",pot);
	me->add("deposit",sil);
	add_shili(me,exp/3,sil);
	me->delete_temp("yang_kill_pantu");
	me->delete_temp("flag");
	me->delete_temp("dtsl_job");
	me->set("busy_time",time());
	tell_object(me,"杨公卿笑道:"+RANK_D->query_respect(me)+",谢谢了!\n");
	tell_object(me,"杨公卿奖励了你"+""HIW""+chinese_number(sil/100)+""NOR""+"两白银\n");
	tell_object(me,"你的钱庄存款增加了！\n");
	tell_object(me,"在这次行动中你得到了"+""HIW""+chinese_number(exp)+""NOR""+"点经验值 "+""HIW""+chinese_number(pot)+""NOR""+"点潜能.\n");
	return 1;
}
