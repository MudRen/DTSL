
inherit NPC;

#include <ansi.h>
string give_job();
void create()
{
   set_name("������",({ "zhao"}) );
        set("gender", "����" );
		set("title","�ʷ�����");
       set("age", 42);
   set("long", "�������μұ����ʷ��������ܹ��μұ����ʲ���\n");
       
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
	   "����":(:give_job:),
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
		return "�������ڵ���������ô�򵥵Ĺ������ǿ�ϧ�ˣ�\n";
	if(me->query_temp("chazhang_job"))
		return "�μұ��ɲ�ϲ�����������ˣ�\n";
	if(time()-me->query("busy_time")<=150)
		return "�㻹����ЪЪ�ɣ�\n";
	if(me->query_temp("dtsl_job"))
   return "������������������æ�����İɣ�\n";
   me->set_temp("dtsl_job","�μұ���������");
	me->set("busy_time",time());
	switch(random(4))
	{
	case 0: me->set_temp("chazhang_job/1",1);return "���鷳"+RANK_D->query_respect(me)+"ȥ�����Ķ��Ҿ�¥ȥ����(chazhang)�ɣ����������ǵ����⡣\n";
	case 1: me->set_temp("chazhang_job/2",1);"/d/yangzhou/npc/zhao.c"->create();
	return "���鷳"+RANK_D->query_respect(me)+"ȥ���ݵ���¥ȥ����(chazhang)�ɣ����������ǵ����⡣\n";
	break;
        case 2: me->set_temp("chazhang_job/3",1);"/d/xiangyang/npc/chen.c"->create();
        return "���鷳"+RANK_D->query_respect(me)+"ȥ������Ӣ�۾�¥ȥ����(chazhang)�ɣ����������ǵ����⡣\n";
        break;
	case 3: me->set_temp("chazhang_job/4",1);"/d/jiujiang/npc/qu.c"->create();
	return "���鷳"+RANK_D->query_respect(me)+"ȥ�Ž��ķ��Ǿ�¥ȥ����(chazhang)�ɣ����������ǵ����⡣\n";
	break;
	}
}
    