// get.c

#include <ansi.h>

inherit F_CLEAN_UP;

int do_get(object me, object ob);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string from, item;
	object obj, *inv, env, obj2;
	int i, amount;

	if( !arg ) return notify_fail("��Ҫ����ʲô������\n");
	if( me->is_busy() )
		return notify_fail("����һ��������û����ɣ�\n");

	// Check if a container is specified.
	if( sscanf(arg, "%s from %s", arg, from)==2 ) {
		env = present(from, me);
		if(!env) env = present(from, environment(me));
		if(!env) return notify_fail("���Ҳ��� " + from + " ����������\n");
		if(env->query("no_get_from"))
		return notify_fail("�㲻�ܴ������ö�����\n");
		if(living(env) && (wiz_level(me) <= wiz_level(env)))
			return notify_fail("�����ʦ�ȼ�����ȶԷ��ߣ���������\n");
	} else env = environment(me);
    if (!wizardp(me) && environment(me)&&environment(me)->query("no_get_from"))
		return notify_fail("���컯�յ������ٰ���\n");
if( !wizardp(me) && userp(env) ) {
    if( env->query("disable_type")==" <˯����>" )
            return notify_fail(HIR"���˼�˯����ʱ�����֣��ٺ٣���Ҳ̫ȱ���ˣ�\n"NOR);

	if((int)env->query_temp("sleeped")>0) 
		return notify_fail(HIR"���˼�˯����ʱ�����֣��ٺ٣���Ҳ̫ȱ���ˣ�\n"NOR);

	if( env->query("disable_type")==" <���Բ�����>" )
            return notify_fail(HIR"���˼һ��Բ��ѵ�ʱ�����֣��ٺ٣���Ҳ̫ȱ���ˣ�\n"NOR);

	if( env ->query_temp("netdead") )
                return notify_fail("�㲻�������޳ܵ��ö��ߵ��˵Ķ���.\n");
       }

	// Check if a certain amount is specified.
	if(sscanf(arg, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, env)) )
			return notify_fail("����û������������\n");
		if( !obj->query_amount() )
			return notify_fail( obj->name() + "���ܱ��ֿ����ߡ�\n");
		if( amount < 1 )
			return notify_fail("�����ĸ���������һ����\n");
		if( amount > obj->query_amount() )
			return notify_fail("����û����ô���" + obj->name() + "��\n");
		else if( amount == (int)obj->query_amount() ) {
			return do_get(me, obj);
		} else {
			obj2 = new(base_name(obj));
			obj2->set_amount( obj->query_amount() - amount);
			obj->set_amount( amount );
			// Counting precise amount costs more time.
			if( me->is_fighting() ) me->start_busy(3);
			if (do_get(me, obj)) {
				obj2->move(env);
				return 1;
			}
			obj2->move(env);
			return 0;
		}
	}

	// Check if we are makeing a quick get.
	if(arg=="all") {
		if( me->is_fighting() )	return notify_fail("�㻹��ս���У�ֻ��һ����һ����\n");
		if( !env->query_max_encumbrance() )	return notify_fail("�ǲ���������\n");
                if( env->query("no_get_from") )	return notify_fail("�㲻�ܴ��������ó���������\n");

		inv = all_inventory(env);
		if( !sizeof(inv) )
			return notify_fail("������û���κζ�����\n");

		for(i=0; i<sizeof(inv); i++)
			do_get(me, inv[i]);

		write("Ok��\n");
		return 1;
	}

	if( !objectp(obj = present(arg, env)) || living(obj) )
		return notify_fail("�㸽��û������������\n");

	if( !wizardp(me) && obj->query("no_get") ) {
		if (stringp(obj->query("no_get")))
			return notify_fail(obj->query("no_get"));
		return notify_fail("��������ò�������\n");
	}
	
	return do_get(me, obj);
}
	
int do_get(object me, object obj)
{
      object old_env;
	int equipped;
	
	notify_fail("�㲻�ܼ���"+obj->name()+"��\n");

	if( !obj ) return 0;
	old_env = environment(obj);

	if( obj->is_character() ) {
		if( living(obj) ) return 0;
		//	if( !userp(obj) && !obj->is_corpse() )
		//		return notify_fail("��ֻ�ܱ���������ҵ����塣\n");
		// If we try to save someone from combat, take the risk :P
	} 
	
	if(!obj->is_character()&&!obj->is_get_of(me,obj))
	  return obj->is_get_of(me,obj);
	if( !wizardp(me) && 
	    (obj->query("no_get")||
	     obj->query("no_give")||
	     obj->query("no_drop")||
	     obj->query("nogive_player")
	    )
	  ) return 0;

         if(((int)me->query_encumbrance() + (int)obj->query_weight()) > (int)me->query_max_encumbrance()||sizeof(all_inventory(me))>=30 )
     return notify_fail("�����ϵĶ���̫���ˣ����ܼ���"+obj->name()+"��\n");

	
	if( obj->query("equipped") ) equipped = 1;
	if( obj->move(me) ) {
                if( obj->query("embedded") ) obj->delete("embedded");
		if( me->is_fighting() ) me->start_busy(1);
		if(obj->query("shouji"))
			message_vision("$N��$n����������ϡ�\n",me,obj);//add by yanyan.2000.
		else if( obj->is_character() )//changed by yanyan.
			message_vision( "$N��$n�����������ڱ��ϡ�\n", me, obj );
		 
		
		else
			message_vision( sprintf("$N%sһ%s$n��\n", 
				old_env==environment(me)? "����":
					(old_env->is_character() ?
						"��" + old_env->name() + "����" + (equipped? "����" : "�ѳ�"):
						"��" + old_env->name() + "���ó�"),
				obj->query("unit")), me, obj );
		return 1;
	}
	else return 0;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : get <��Ʒ����> [from <������>]
 
���ָ��������������ϻ������ڵ�ĳ����Ʒ.
 
HELP
    );
    return 1;
}
 
