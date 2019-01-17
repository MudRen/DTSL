
#include <ansi.h>
inherit ROOM;

int do_tiao();
void create ()
{
  set ("short",WHT"�ٲ���"NOR);
  set ("long", @LONG
�������ٲ������棬���϶��µ����ҵ�ˮ������������ϣ�������
��ˮ����ˮ���ܴ���ס��������ߣ�ֻ�ܿ�����ǰһƬ�׹⣬ˮ���
������������������Щ���顣
LONG);

  set("exits", ([ 
 "out":__DIR__"pubu",
     ]));
  set("add_force",1);
   set("valid_startroom", 1);
   set("outdoors","huashan");
   set("no_select",1);
  setup();
 
}

void init()
{
	object *ob,here;int i;
	add_action("do_tiao","tiao");
	here=load_object(__DIR__"shui");
	ob=all_inventory(here);

	for(i=0;i<sizeof(ob);i++)
	{
		if(objectp(ob[i])&&ob[i]->query_skill("force",1)<100&&
			!ob[i]->query_temp("add_force")){
			ob[i]->set_temp("add_force",1);
			call_out("add_force",1,ob[i]);
		}
	}
	return;
}

void add_force(object ob)
{
	object here;
	if(!ob) return;
	here=environment(ob);
	if(!here->query("add_force")){
	 ob->delete_temp("add_force");
	 return;
	}
	if(ob->query_skill("force",1)>=101)
	return;
	if(ob->is_busy())
	return;
	tell_object(ob,"\nˮ���͵س����ͷ�ϳ�������!\n");
	if(ob->query("sen")<ob->query_skill("force",1)/3)
	{
		message_vision("$N���÷ǳ�ƣ�ͣ��Ѿ�֧�ֲ�ס�ˣ�\n",ob);
		ob->unconcious();
		ob->move(__DIR__"pubu");
		return ;
	}
	ob->receive_damage("sen",ob->query_skill("force",1)/3?ob->query_skill("force",1)/3:1);
	ob->improve_skill("force",ob->query_skill("force",1)/3+ob->query_int()/2);
	tell_object(ob,"������ȫ��ҧ�����˹�����\n");
	call_out("add_force",3+random(2),ob);
	return;
}

int do_tiao()
{
	object ob;
	ob=this_player();
	message_vision("$N���Աߵ�̶ˮ���˹�ȥ��\n",ob);
	ob->move(__DIR__"tan");
    return 1;
}
