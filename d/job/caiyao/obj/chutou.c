
#include <weapon.h>

inherit STAFF;

int do_action();

void create()
{
        set_name("��ͷ", ({ "chu tou","chu","tou" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�ѿ����൱��ͨ�ĳ�ͷ");
                set("material", "wood");
                set("no_give",1);
                set("no_get",1);
                set("no_drop",1);
                set("no_steal",1);
                set("no_save",1);
        }
        init_staff(10,20,20);

      set("wield_msg", "$N��$n�������������С�\n");
        set("unwield_msg", "$N�ɿ������е�$n��\n");

// The setup() is required.

        setup();
}

void init()
{
  add_action("do_action","wa");
}

int do_action()
{
   object ob,medicine,tool;
   
   ob=this_player();
   
   tool=ob->query_temp("weapon");
   
   if(ob->is_busy())
   return notify_fail("����æ���أ�\n");
   if(ob->is_fighting())
   return notify_fail("�㻹���ȴ��̰ɣ�\n");
   
   if(!objectp(tool)||tool!=this_object())
    return notify_fail("��Ӧ���Ȱѳ�ͷװ����������ҩ��\n");
    
   if(query("place")!=base_name(environment(ob))+".c")
    return notify_fail("����ҩ�ĵص㲻�ԡ�\n");
   
   if(ob->query_temp("wei_ok"))
   return notify_fail("����Ĳ�ҩ�Ѿ������ˣ����Ի�ȥ��Τ��٢�ˡ�\n");
   
   if(ob->query_temp("wei_job/count")==12)
	{
		medicine=new(__DIR__"caoyao");
		medicine->set("owner",ob);
		medicine->move(ob);
		message_vision("$N�ڵ���һ��"+medicine->name()+"\n",ob);
		//ob->delete_temp("wei_job");
		ob->set_temp("wei_ok",1);
		return 1;
	}
   ob->add_temp("wei_job/count",1+random(1));
   
	ob->receive_damage("sen",20+random(10));
	ob->start_busy(random(2));
	message_vision("$N����"+tool->name()+"����������\n",ob);
	return 1;
}