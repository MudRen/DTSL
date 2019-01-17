
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
	 set("no_give",1);
	 set("no_drop",1);
	 set("no_get",1);
	 set("give_object",1);
         set("unit", "��");
   }
   setup();
}

void init()
{
   add_action("do_give","songxin");
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
    return notify_fail("��Ҫ�����͸�˭��\n");
    if(!objectp(ob=present(arg,environment(who))))
    return notify_fail("����û������ˣ�\n");
    if(!who->query_temp("zhu_sx")||query("owner")!=who)
    return notify_fail("����ź������������͵ġ�\n");
    if(query("target")!=(ob))
    return notify_fail("���ʹ����ˣ�\n");
    
    JOBSYS_D->give_reward_songxin(who);
        
	who->delete_temp("zhu_sx");
	who->delete_temp("dtsl_job");
	who->delete_temp("need_killer");
	who->delete_temp("need_killer_flags");
	tell_object(who,"��ɹ��ؽ����͸���"+ob->name()+"��\n");	
	message_vision("\n$Nһ��˫ȭ�����Ǻ�����ڣ�\n$N�Ҵ����ˡ�\n",ob);
	destruct(ob);
	destruct(this_object());
	return 1;
}
