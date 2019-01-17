
#include <ansi.h>
#include <job_money.h>
inherit ITEM;
int do_give(string arg);
void create()
{
   set_name(YEL"密涵"NOR, ({ "letter","xin" }) );
   set_weight(10);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "paper");
	 set("long","这是一封阴癸派的密涵。\n");
	 set("zhu_sx",1);
	 set("give_object",1);
         set("unit", "封");
   }
   setup();
}

void init()
{
   add_action("do_give","songxin");
}

int do_give(string arg)
{
    int exp,sil,pot;
    object who,ob;
    who=this_player();
    if(!arg)
    return notify_fail("你要把信送给谁？\n");
    if(!objectp(ob=present(arg,environment(who))))
    return notify_fail("这里没有这个人！\n");
    if(!who->query_temp("zhu_sx")||query("owner")!=who)
    return notify_fail("这封信好象不是让你来送的。\n");
    if(query("npc_home")!=base_name(ob))
    return notify_fail("你送错人了！\n");
    
        if(exp<200000)
	exp=who->query("max_pot")-30-random(5);
	else exp=220+random(20);
	if(exp<1000000)
	pot=who->query("max_pot")/3;
	else pot=120+random(10);
	sil=SONGXIN_JOB+who->query("max_pot")/5;
	who->add("combat_exp",exp);
	who->add("potential",pot);
	who->add("deposit",sil);
	add_shili(who,exp/3,sil/2);
	who->delete_temp("zhu_sx");
	who->delete_temp("dtsl_job");
	tell_object(who,"你成功地将信送给了"+ob->name()+"！\n");
	tell_object(who,"在这次行动中你得到了"+""HIW""+chinese_number(exp)+""NOR""+"点经验值 "+""HIW""+chinese_number(pot)+""NOR""+"点潜能 "+MONEY_D->money_str(sil)+"\n");
	tell_object(who,"你的钱庄存款增加了！\n");
	destruct(this_object());
	return 1;
}