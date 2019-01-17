//��ɱ��for killer vocation.
#include <ansi.h>
#include <org.h>

#define TIME_TICK1 ((time())*60)
#define MAX_LIGHT_TIME 1200
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
		return notify_fail("ָ���ʽ��ansha <����> at <����>\n");

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

	if (env == old_env) return notify_fail("��һ���ط��޷���ɱ��\n");
    if( !old_env->valid_leave(me, where) ) {
        write(query_notify_fail());
        return 1;
        }
        if(me->query("vocation")!="ɱ��")
        return notify_fail("ֻ��ɱ�ֿ���ʹ��������\n");
	if( env->query("no_fight") )
		return notify_fail("�����ֹս����\n");

	if( !objectp(target = present(who, env)) )
		return notify_fail("�������û�д��ˡ�\n");
        
        if(objectp(target->query_temp("city_war_guard")))
        return notify_fail("�Է������������أ�\n");
	
	if ( userp(me) && userp(target) && target->query("age") < 13 )
		return notify_fail("�е�ְҵ���°ɣ�С����Ҳ���Ź���?\n");
	if ( userp(me) && userp(target) && target->query("combat_exp") < 15000 )
		return notify_fail("������������Ҳֵ����ȥ��ɱ��\n");

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
		return notify_fail("����æ��ս���أ�������˼��ɱ���ˣ�\n");

	if( !living(target) )
		return notify_fail(target->name() + "���Ѿ������ˣ��㻹�õ��Ű�����\n"); 

	if( (int)me->query("sen") < 100 )
		return notify_fail("���޷����о��������㲻�˱��ˡ�\n");
        if(me->query("bellicosity")<200)
        return notify_fail("���ɱ���������޷����а�ɱ��\n");
        if (!((	(strsrch(CHINESE_D->chinese_date(TIME_TICK1), "��ʱ") >= 0) ||
		(strsrch(CHINESE_D->chinese_date(TIME_TICK1), "��ʱ") >= 0) ||
		(strsrch(CHINESE_D->chinese_date(TIME_TICK1), "��ʱ") >= 0) ||
		(strsrch(CHINESE_D->chinese_date(TIME_TICK1), "��ʱ") >= 0) ) 
		&&me->query_temp("light")<time()-MAX_LIGHT_TIME))
	return notify_fail("�㻹�ǵ�����ȫ���������ж��ɣ�\n");
	if(!environment(me)->query("outdoors"))
	return notify_fail("�����ڻ��ǲ�Ҫ�����־ٶ��ĺá�\n");
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
        me->kill_ob(target);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0,1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0,1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0,1);
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
		message_vision(CYN"$Nһʱû�з�������$n���˸����ֲ�����\n"NOR, target, me);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0,2);
	} else {
		message_vision(CYN"$N����ḻ������ϸ����������$n������\n"NOR, target, me);
		COMBAT_D->do_attack(target, me, target->query_temp("weapon"),0, 1);
	}

	if( random(me->query("combat_exp")) < (int)target->query("combat_exp")/3 ) {
		me->set_temp("apply/name", name);

		tell_object(target, CYN"��һ����ԭ����" + me->name() + "�ڰ�ɱ�㣡\n"NOR);
		write(CYN "���ã��㱻" + target->name() + "�����ˣ�\n"NOR);
		message_vision(CYN"$N�ȵ���$n����Ұ�ɱ�ң��Ҹ���û�꣡\n"NOR, target, me);
		if (!userp(target)) target->kill_ob(me);
		else target->fight_ob(me);
		me->start_busy(1);
	} else {
		tell_room(env, CYN "\n" + gen + "ת˲������\n\n"NOR, ({me}));
		write(CYN"\n�������˻�ԭ����\n\n"NOR);

		me->move(old_env);
		tell_room(old_env, CYN "\nת�ۼ�" + gen + "�ֻص�ԭ����\n\n"NOR, ({me}));

		me->set_temp("apply/name", name);

		tell_object(target, CYN"��һ���񣬿���ʲô��û������\n"NOR);		
	}

	me->start_busy(1);
	me->receive_damage("sen", 50);

	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : ansha <����> at <����>

���ָ�����㰵ɱλ��<����>��<����>��
Ϊɱ��ר��ָ�
������ɱ��>=200.

HELP
);
	return 1;
}
