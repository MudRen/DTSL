
inherit NPC;
#include <ansi.h>
//#include <job_money.h>
//int do_cha(string arg);
void create()
{
   set_name("����",({ "dong fang","dong","fang" }) );
        set("gender", "����" );
        set("age", 40);
   set("long", "���Ƕ��Ҿ�¥���ϰ塣�����书Ҳ����һ�����ġ�\n");
       
   set("combat_exp",300000);
   set("str",26);
   set("per", 22);
   set("force",500);
   set("max_force",500);
   set("kee",800);
   set("max_kee",800);
   set("sen",500);
   set("max_sen",500);
   set_skill("dodge",80);
   set_skill("parry",80);
   set_skill("unarmed",80);
   set("attitude", "peaceful");
  setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

/*void init()
{
	add_action("do_cha","chazhang");
}
int do_cha(string arg)
{
	object me,ob,money;int exp,pot,sil;
	me=this_player();
	if(!arg||!present(arg,environment(me)))
		return notify_fail("��Ҫ��˭���ʣ�\n");
	if(!me->query_temp("chazhang_job/1"))
		return notify_fail("��û�������ʵ�Ȩ����\n");
	me->set_temp("busy_time",time());
	exp=me->query("max_pot")/3+random(10);
	pot=me->query("max_pot")/4;
	sil=CHA_JOB;
	me->add("combat_exp",exp);
	me->add("potential",pot);
	me->add("deposit",sil);
	add_shili(me,exp/2,CHA_JOB/2);
	me->delete_temp("chazhang_job");
	me->delete_temp("dtsl_job");
	tell_object(me,"������ж��У���õ��ˣ�"
               +""HIW""+chinese_number(exp)+""NOR""+"�㾭��ֵ"
               +""HIW""+chinese_number(pot)+""NOR""+"��Ǳ��"
               +""HIW""+chinese_number(sil)+""NOR""+"��ͭǮ\n");
        tell_object(me,"���Ǯׯ��������ˣ�\n");
	return 1;
}
*/