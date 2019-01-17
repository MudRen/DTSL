
#include <ansi.h>
#include <job_money.h>
inherit ITEM;
int do_give(string arg);
void create()
{
   set_name(YEL"������"NOR, ({ "order" }) );
   set_weight(10);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "paper");
	 set("long","����һ���������Ķ�������\n");
	 set("order_job",1);
	 set("no_give",1);
	 set("no_drop",1);
	 set("give_object",1);
         set("unit", "��");
   }
   setup();
}

void init()
{
   add_action("do_give","songdan");
}

int is_get_of(object me,object ob)
{
	if(query("owner")!=me)
	return notify_fail("����������������\n");
	return 1;
}

int do_give(string arg)
{
    object who,ob;
    
    who=this_player();
    
    if(!arg)
    return notify_fail("��Ҫ�Ѷ������͸�˭��\n");
    if(!objectp(ob=present(arg,environment(who))))
    return notify_fail("����û������ˣ�\n");
    if(!who->query_temp("order_job")||query("owner")!=who)
    return notify_fail("���Ŷ������������������͵ġ�\n");
    if(query("target")!=(ob))
    return notify_fail("���ʹ����ˣ�\n");
        
        JOBSYS_D->give_reward_tradejob(who);
        
	who->delete_temp("order_job");
	who->delete_temp("dtsl_job");
	who->delete_temp("need_killer");
	who->delete_temp("need_killer_flags");
	who->set("busy_time",time());
	
	tell_object(who,"��ɹ��ؽ��������͸���"+ob->name()+"��\n");	
	message_vision("\n$N���˻��֣��´��ٺ����ɣ�\n$N�Ҵ����ˡ�\n",ob);
	destruct(ob);
	destruct(this_object());
	return 1;
}
