//eff��������
//eff�����ħ

inherit SSERVER;
#include <ansi.h>

void hit_ob(object me, object victim) {
	int flag,ini_damage_apply,damage;
	string str;
	if(me->query_temp("apply_effskill_pomo",1))
		return;
	if (victim->query("eff_kee")<0 || !living(victim) )  
		return;
	if(!me->is_fighting(victim))
		return;
	me->add_temp("effskill_pomo_times",1);
	if(me->query_temp("effskill_pomo_times")<1)
		return;
	me->set_temp("apply_effskill_pomo",1);

	if(random(2)>0) {
		me->set_temp("effskill_pomo_times",-1);  
		damage=me->query("apply_points")*2;
		ini_damage_apply = me->query_temp("apply/damage");
		me->add_temp("pomo_time",-1);
		me->add_temp("apply/damage",damage);
		str=HIC"$N�������ۣ�˫�Ʋ��ϱ任���ƣ����������Ӱ������ȴϸ����˿��������˷�Ϯ��$n�����Ѩ��\n"NOR;
		me->set_temp("action_msg",str);
		flag=COMBAT_D->do_attack(me, victim,0,0,1);
		
		if(!me->is_fighting()){
			me->delete_temp("apply_effskill_pomo");
			me->delete_temp("action_msg");
			me->set_temp("apply/damage",ini_damage_apply);
			return; 
		}
	}          
	else{
		me->add_temp("pomo_time",-1);
	}  
	me->delete_temp("apply_effskill_pomo");
	me->delete_temp("action_msg");
	me->set_temp("apply/damage",ini_damage_apply);
}
 
