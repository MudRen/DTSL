
inherit NPC;
#include <ansi.h>
#include <job_money.h>
int do_cha(string arg);
mapping *name=({
(["name":"��","id":"zhao",]),(["name":"Ǯ","id":"qian",]),(["name":"��","id":"sun",]),
(["name":"��","id":"zhou",]),(["name":"��","id":"wu",]),(["name":"֣","id":"zheng",]),
(["name":"��","id":"li",]),(["name":"��","id":"wang",]),(["name":"��","id":"liu",]),
(["name":"���","id":"zhuge",]),(["name":"��","id":"ding",]),(["name":"��","id":"jin",]),
});
void create()
{
   mapping newname;
   newname=name[random(sizeof(name))];
      set_name(newname["name"]+"�ϰ�",({ newname["id"]}) );
        set("gender", "����" );
        set("age", 32);
   set("long", "������[��¥]���ϰ��ˣ�һ�����ĵ����ơ�\n");
       
   set("combat_exp", 200000);
   set("str", 27);
   set("per", 24);
   set_skill("force",120);
   set("force",800);
   set("max_force",800);
   set("attitude", "friendly");
   set("vendor_goods",({
	   __DIR__"obj/yu",
	   __DIR__"obj/kaoya",
	   __DIR__"obj/jiudai",
	   __DIR__"obj/zhouzi",
   }));
   setup();
    carry_object(__DIR__"obj/chouyi")->wear();
  
}

void init()
{
	add_action("do_list","list");
	add_action("do_buy","buy");
	add_action("do_cha","chazhang");
	
}

int do_cha(string arg)
{
	/*object me,ob,money;int exp,pot,sil;
	me=this_player();
	if(!arg||!present(arg,environment(me)))
		return notify_fail("��Ҫ��˭���ʣ�\n");
	if(!me->query_temp("chazhang_job/2"))
		return notify_fail("��û�������ʵ�Ȩ����\n");
	me->set_temp("busy_time",time());
	exp=me->query("max_pot")/3+random(10);
	pot=me->query("max_pot")/4;
	sil=CHA_JOB;
	me->add("combat_exp",exp);
	me->add("potential",pot);
	if(me->query("potential")>me->query("max_pot"))
	me->set("potential",me->query("max_pot"));
	me->add("deposit",sil);
	add_shili(me,exp/2,CHA_JOB/2);
	me->delete_temp("chazhang_job");
	me->delete_temp("dtsl_job");
	tell_object(me,"������ж��У���õ��ˣ�"
               +""HIW""+chinese_number(exp)+""NOR""+"�㾭��ֵ"
               +""HIW""+chinese_number(pot)+""NOR""+"��Ǳ��"
               +""HIW""+chinese_number(sil)+""NOR""+"��ͭǮ\n");
        tell_object(me,"���Ǯׯ��������ˣ�\n");*/
	return 1;
}
