#include <ansi.h>
#include <job_money.h>
inherit NPC;
inherit F_SAVE;
string give_job();
string query_save_file()
{

	string id2;

	if( !stringp(id2 = query("npc_id")) ) return 0;
	return DATA_DIR + "npc/boss/" + id2;
}
void create()
{
   set_name("商秀珣",({ "shang xiuxun","shang"}) );
        set("gender", "女性" );
		
        set("age", 25);
   set("long", "她就是飞马场主.仪态万千，乌黑漂亮的秀发像两道小瀑布般倾泻在她刀削似
的香肩处，美得异乎寻常，差可以跟婠婠媲美的劲服女郎，步入门来，对他们的存在没有半丝
讶异。淡雅的装束更突出了她出众的脸庞和晒得古铜色闪闪发亮的娇嫩肌肤，散发着灼热的青春
和令人艳羡的健康气息。她那对美眸深邃难测，浓密的眼睫毛更为她这双像荡漾着最香最醇的仙
酿的凤目增添了她的神秘感。\n");
       
   set("combat_exp",600000);
   set("str", 24);
   set("per", 27);
   set("attitude", "peaceful");
   set_skill("unarmed",170);
   set_skill("dodge",170);
   set_skill("parry",170);
   set_skill("sword",170);
   set_skill("qingxuan-jianfa",170);

   set_skill("babu-ganchan",170);
   set("sword",({"qingxuan-jianfa"}));
   set("dodge",({"babu-ganchan"}));
   set("inquiry",([
	   "叛徒":(:give_job:),
	   ]));
   set("shili",([
       "name":"feima_b",
       "leader":"feima_b",
       ]));
   set("npc_id","shangxiuxun");
   setup();
   carry_object(__DIR__"obj/shayi")->wear();
   carry_object(__DIR__"obj/changjian")->wield();
   restore();
}

void init()
{
	object ob,ob2;
	ob=this_player();
	ob2=this_object();
	::init();
	if(!ob||!present(ob,environment())||ob2->is_fighting()) return;
	call_out("welcome",1,ob,ob2);
	
}

void welcome(object ob,object ob2)
{
   if(!ob||!present(ob,environment())||ob2->is_fighting()) return;
	switch(random(2))
	{
	case 0: message_vision("$N说道:谁让你进来的,出去!\n",ob2);break;
	case 1: message_vision("$N抬头看了看$n\n",ob2,ob);
	}
	remove_call_out("welcome");
	return;
}

string give_job()
{
   object me;object ob;
   ob=this_object();
   me=this_player();
   if(me->query_temp("shang_kill_pantu"))
	   return "你还是先把叛徒杀死再说吧!\n";
   if(ob->query("job_time"))
	   if(time()-ob->query("job_time")<=120)
		   return "恩..这个,已经有人帮忙了,你先等会吧!\n";
   
   ob->set("job_time",time());
   call_out("cancel_shang_kill_pantu",300,me);
   switch(random(3))
   {
   case 0: me->set_temp("shang_kill_pantu/1",1);return "好吧,你去把飞马牧场的叛徒杀死,别忘了拿回他的首级!\n听说他在扬州的一座废弃的园子里藏身!\n";break;
   case 1: me->set_temp("shang_kill_pantu/2",1);return "好吧,你去把飞马牧场的叛徒杀死,别忘了拿回他的首级!\n听说他在成都的一个富户之家藏身!\n";break;
   case 2: me->set_temp("shang_kill_pantu/3",1);return "好吧,你去把飞马牧场的叛徒杀死,别忘了拿回他的首级!\n听说他经常躲藏在襄阳的街头小巷中!\n";break;
   }
   
}

void cancel_shang_kill_pantu(object me)
{
	if(!objectp(me)) {remove_call_out("cancel_shang_kill_pantu");return;}
	if(me->query_temp("shang_kill_pantu"))
	{
		tell_object(me,HIW"你做事太慢了,你的任务被取消了!\n"NOR);
		me->delete_temp("shang_kill_pantu");
		remove_call_out("cancel_shang_kill_pantu");
		return;
	}
	remove_call_out("cancel_shang_kill_pantu");
}

int accept_object(object me,object ob)
{
	int exp,sil,pot,famous,i,j;
	object npc;
	j=10;
	npc=this_object();
	if(!me->query_temp("shang_kill_pantu"))
		return 0;
	if((string)ob->query("dead_id")!="tao shusheng")
		return 0;
	me->delete_temp("shang_kill_pantu");
        exp=me->query("max_pot");
        famous=exp/2;
        pot=me->query("max_pot")/4;
	me->add("combat_exp",exp);
	sil=FEIMA_JOB;
	pot=50+random(10);
	me->add("potential",pot);
	me->add("deposit",FEIMA_JOB);
	add_shili(me,exp/3,FEIMA_JOB/2);
	tell_object(me,HIW"\n你被奖励了"+exp+"点经验值 "+famous+"点江湖声望"+pot+"点潜能"+sil/100+"两白银\n"NOR);
	tell_object(me,HIW"谢谢了,为我们飞马牧场做了这么大的好事!\n"NOR);
	tell_object(me,"你的钱庄存款增加了！\n");
	return 1;
}

int accept_enroll(object me)
{
	object ob;
	ob=this_object();
	if(me->query("shili"))
	if(me->query("shili/name")!=ob->query("shili/name"))
	 return notify_fail("我们飞马牧场可不要其他帮派的人！\n");
	if(!ob->query("shili/leader"))
	 return notify_fail("我已经不是场主了，和我说没用的！\n");
	if(me->query("shili/name")==ob->query("shili/name"))
	 return notify_fail("你高声喊道：飞马牧场威武林！\n");
	me->set_temp("mark_join",ob->query("shili/name"));
	message_vision("$N朝$n笑道：希望$n能好好干，使我们飞马牧场威武林！\n",ob,me);
	tell_object(me,"请去势力名单榜处打 join 命令就算加入了！\n");
	CHANNEL_D->do_channel(this_object(), "rumor",
	sprintf("%s加入了飞马牧场！\n",me->name()));
	return 1;
}