
#include <ansi.h>
#include <job_money.h>
inherit ITEM;
int do_give(string arg);
void create()
{
   set_name(YEL"�ܺ�"NOR, ({ "letter","xin" }) );
   set_weight(10);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "paper");
	 set("long","����һ�������ɵ��ܺ���\n");
	 set("zhu_sx",1);
	 set("give_object",1);
         set("unit", "��");
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
    return notify_fail("��Ҫ�����͸�˭��\n");
    if(!objectp(ob=present(arg,environment(who))))
    return notify_fail("����û������ˣ�\n");
    if(!who->query_temp("zhu_sx")||query("owner")!=who)
    return notify_fail("����ź������������͵ġ�\n");
    if(query("npc_home")!=base_name(ob))
    return notify_fail("���ʹ����ˣ�\n");
    
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
	tell_object(who,"��ɹ��ؽ����͸���"+ob->name()+"��\n");
	tell_object(who,"������ж�����õ���"+""HIW""+chinese_number(exp)+""NOR""+"�㾭��ֵ "+""HIW""+chinese_number(pot)+""NOR""+"��Ǳ�� "+MONEY_D->money_str(sil)+"\n");
	tell_object(who,"���Ǯׯ��������ˣ�\n");
	destruct(this_object());
	return 1;
}