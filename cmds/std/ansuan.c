// ansuan.c ����
//by Yu Jue 98.09
//good pro.
//copied by yanyan for dt. make some change.:-)
#include <ansi.h>
#include <org.h>

mapping default_where = ([
        "n":    "north",
        "s":    "south",
        "e":    "east",
        "w":    "west",
        "nu":   "northup",
        "su":   "southup",
        "eu":   "eastup",
        "wu":   "westup",
        "nd":   "northdown",
        "sd":   "southdown",
        "ed":   "eastdown",
        "wd":   "westdown",
        "ne":   "northeast",
        "nw":   "northwest",
        "se":   "southeast",
        "sw":   "southwest",
        "u":    "up",
        "d":    "down",
]);

mapping default_dirs = ([
        "north":                "����",
        "south":                "����",
        "east":                 "����",
        "west":                 "����",
        "northup":              "����",
        "southup":              "�ϱ�",
        "eastup":               "����",
        "westup":               "����",
        "northdown":            "����",
        "southdown":            "�ϱ�",
        "eastdown":             "����",
        "westdown":             "����",
        "northeast":            "����",
        "northwest":            "����",
        "southeast":            "����",
        "southwest":            "����",
        "up":                   "����",
        "down":                 "����",
        "enter":                "����",
        "out":                  "����",
]);

int main(object me, string arg)
{
	string who, where, dir, undir, where_temp, *name;
	object env, old_env;
	mapping exits;
	object target;
	string gen;

	if( !arg || sscanf(arg, "%s at %s", who, where_temp)!=2 ) 
		return notify_fail("ָ���ʽ��ansuan <����> at <����>\n");

	env = environment(me);
	if(!env) return notify_fail("������Ҳȥ���ˡ�\n");
	if(me->query("pker"))
	return notify_fail("ͨ����������ʵ�ش���ɣ�\n");
	
	if(objectp(me->query_temp("city_war_guard")))
        return notify_fail("�������������أ�\n");
	
	old_env = env;

	if( !undefinedp(default_where[where_temp]) )
		where = default_where[where_temp];
	else
		where = where_temp;

	if( !mapp(exits = env->query("exits")) || undefinedp(exits[where]) )
		return notify_fail("û���������\n");

	if( !objectp(env = find_object(exits[where])) ) {
		call_other(exits[where], "???");
		env = find_object(exits[where]);
	}

	if (env == old_env) return notify_fail("ֱ���� kill ָ����ˡ�\n");
    if( !old_env->valid_leave(me, where) ) {
        write(query_notify_fail());
        return 1;
        }

	if( env->query("no_fight") )
		return notify_fail("�����ֹս����\n");

	if( !objectp(target = present(who, env)) )
		return notify_fail("�������û�д��ˡ�\n");
	
	if(objectp(target->query_temp("city_war_guard")))
        return notify_fail("�Է������������أ�\n");

	if (wiz_level(me) < wiz_level(target))
		return notify_fail("�㲻�ܹ�����ʦ�ȼ�����ߵĶ��֡�\n");

	if ( userp(me) && userp(target) && target->query("age") < 17 )
		return notify_fail("����ĳ�̫����, �����޸���֮�������Ҳ�µ����֡�\n");
	if ( userp(me) && userp(target) && target->query("combat_exp") < 15000 )
		return notify_fail("����ĳ�̫����, �����޸���֮�������Ҳ�µ����֡�\n");

	if( !target->is_character() || target->is_corpse() )
		return notify_fail("�����һ�㣬�ǲ��������\n");
	
	if( target->is_city_war_guard() )
		return notify_fail("�㲻�ܹ����Է���\n");
        
        if(stringp(target->query("target_id"))&&target->query("target_id")!=me->query("id"))
	return notify_fail(target->name()+"������������ս������\n");
	
	if(arrayp(target->query("target_id"))&&
	   member_array(me->query("id"),target->query("target_id"))==-1)
	   return notify_fail(target->name()+"������������ս������\n");
	
	if(userp(me)&&userp(target)&&
	  me->query("shili/name")&&target->query("shili/name")){
	  if(me->query("shili/name")==target->query("shili/name"))
	   return notify_fail("ͬһ�����Ӳ�Ҫ��ɱ�ˣ�\n");
	  if(ORG_D->if_friend_org(me,target))
	   return notify_fail("���˰����Ӽ䲻�ܻ�ɱ��\n");
	}
        
	if( me->is_busy() )
		return notify_fail("��Ķ�����û����ɣ����ܰ��㡣\n");

	if( me->is_fighting() )
		return notify_fail("����æ��ս���أ�������˼������ˣ�\n");

	if( !living(target) )
		return notify_fail(target->name() + "���Ѿ������ˣ��㻹�õ��Ű�����\n"); 

	if( (int)me->query("sen") < 100 )
		return notify_fail("���޷����о��������㲻�˱��ˡ�\n");

	dir = env->query("short");
	if( !undefinedp(default_dirs[where]) )
		dir = default_dirs[where] + dir;

	undir = old_env->query("short");

	if(me->query("gender") == "Ů��")
		gen = "ٻӰ";
	else
		gen = "��Ӱ";

	write(CYN "����Ϣ���������������" + dir + "��" + target->name() + "��ȥ��\n" NOR);
	tell_room(old_env, CYN "\nһ��" + gen + "��Ȼ��" + dir + "��ȥ��\n" NOR, ({me}));
	message_vision(CYN "\nһ��" + gen + "��Ȼ��" + undir + "��$N������\n\n" NOR, target);

	name = me->query_temp("apply/name");
	me->set_temp("apply/name", ({gen}));

	me->move(environment(target));

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0,2);

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
		message_vision(CYN"$Nһʱû�з�������$n���˸����ֲ�����\n"NOR, target, me);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0,2);
		
	} else {
		message_vision(CYN"$N����ḻ������ϸ����������$n������\n"NOR, target, me);
		COMBAT_D->do_attack(target, me, target->query_temp("weapon"),0, 1);
		
	}

	if( random(me->query("combat_exp")) < (int)target->query("combat_exp")/3 ) {
		me->set_temp("apply/name", name);

		tell_object(target, CYN"��һ����ԭ����" + me->name() + "�ڰ����㣡\n"NOR);
		write(CYN "���ã��㱻" + target->name() + "�����ˣ�\n"NOR);
		message_vision(CYN"$N�ȵ���$n����Ұ����ң��Ҹ���û�꣡\n"NOR, target, me);
		if (!userp(target)) target->kill_ob(me);
		else target->fight_ob(me);
		me->start_busy(4);
		if(target->accept_ansuan(me,2));//ʧ��
	} else {
		tell_room(env, CYN "\n" + gen + "ת˲������\n\n"NOR, ({me}));
		write(CYN"\n�������˻�ԭ����\n\n"NOR);

		me->move(old_env);
		tell_room(old_env, CYN "\nת�ۼ�" + gen + "�ֻص�ԭ����\n\n"NOR, ({me}));

		me->set_temp("apply/name", name);

		tell_object(target, CYN"��һ���񣬿���ʲô��û������\n"NOR);
		tell_room(env, CYN + target->name() + "һ���֣̿���Ȼ��֪������˭�İ��㣡\n"NOR,
			({target}));
		write(CYN "������" + target->name() + "��Ȼû��������\n"NOR);
		write(CYN "��ɿ���������һ���޹������ӡ�\n"NOR);
		if(target->accept_ansuan(me,1));//�ɹ���
	}

	me->start_busy(3);
	me->receive_damage("sen", 50);

	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : ansuan <����> at <����>

���ָ�����㰵��λ��<����>��<����>��

HELP
);
	return 1;
}
