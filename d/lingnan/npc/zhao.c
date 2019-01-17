
inherit NPC;

#include <ansi.h>
string give_job();
void create()
{
   set_name("赵先生",({ "zhao"}) );
        set("gender", "男性" );
		set("title","帐房先生");
       set("age", 42);
   set("long", "他就是宋家堡的帐房先生，总管宋家堡的帐簿。\n");
       
   set("combat_exp", 300000);
   set("str", 28);
   set("per", 24);
   set("attitude", "peaceful");
   set("gin",1000);
   set("max_gin",1000);
   set("kee",1000);
   set("max_kee",1000);
   set("sen",1000);
   set("max_sen",1000);
   set("force",1000);
   set("max_force",1000);
   set_skill("dodge",100);
   set_skill("parry",100);
   set_skill("unarmed",100);
   set_skill("cuff",100);
   /*set("inquiry",([
	   "查账":(:give_job:),
	   ]));*/
   set("shili",([
      "name":"songjia_b",
      ]));
   setup();
   carry_object(__DIR__"obj/chouyi")->wear();
 
}

string give_job()
{
	object me,ob;
	me=this_player();ob=this_object();
	if((int)me->query("combat_exp",1)>100000)
		return "以你现在的身手做这么简单的工作真是可惜了！\n";
	if(me->query_temp("chazhang_job"))
		return "宋家堡可不喜欢做事马虎的人！\n";
	if(time()-me->query("busy_time")<=150)
		return "你还是先歇歇吧！\n";
	if(me->query_temp("dtsl_job"))
   return "你正在做其他任务，先忙其他的吧！\n";
   me->set_temp("dtsl_job","宋家堡查账任务");
	me->set("busy_time",time());
	switch(random(4))
	{
	case 0: me->set_temp("chazhang_job/1",1);return "那麻烦"+RANK_D->query_respect(me)+"去洛阳的董家酒楼去查帐(chazhang)吧，那里有我们的生意。\n";
	case 1: me->set_temp("chazhang_job/2",1);"/d/yangzhou/npc/zhao.c"->create();
	return "那麻烦"+RANK_D->query_respect(me)+"去扬州的醉花楼去查帐(chazhang)吧，那里有我们的生意。\n";
	break;
        case 2: me->set_temp("chazhang_job/3",1);"/d/xiangyang/npc/chen.c"->create();
        return "那麻烦"+RANK_D->query_respect(me)+"去襄阳的英雄酒楼去查帐(chazhang)吧，那里有我们的生意。\n";
        break;
	case 3: me->set_temp("chazhang_job/4",1);"/d/jiujiang/npc/qu.c"->create();
	return "那麻烦"+RANK_D->query_respect(me)+"去九江的凤仪酒楼去查帐(chazhang)吧，那里有我们的生意。\n";
	break;
	}
}
    