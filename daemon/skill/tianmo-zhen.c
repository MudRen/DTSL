//��ħ��


inherit SKILL;

#include <ansi.h>

string query_type()
{
  return "literate";
}

int valid_learn(object me)
{
    return 1;
}

object offensive_target(object me)
{
	int sz;
	object *enemy,target;

	enemy = me->query_enemy();
	if( !enemy || !arrayp(enemy) ) return 0;

	sz = sizeof(enemy);
	if( sz > 4 ) sz = 4;

	if( sz > 0 ){
	  target=enemy[random(sz)];
	  return target;
	}
	else return 0;
}

int form_array(object me)
{
   object *t,target;
   int i,fight_flag=0,damage;
   
   t=me->query_team();
   t=t-({0});
   if(sizeof(t)!=4) return notify_fail("Ҫʩչ��ħ��ֻ�����ĸ��ˣ�\n");
   
   if(time()-me->query_temp("form_busy")<10)
   return notify_fail("���������㣬�޷�ʩչ��ħ��\n");
   
   for(i=0;i<sizeof(t);i++)
    if(objectp(t[i])){
     if(environment(t[i])!=environment(me))
      return notify_fail("���˲�����վ��һ��\n");
     if(t[i]->query_skill("tianmo-zhen",1)<160)
      return notify_fail(t[i]->name()+"��ħ����Ϊ̫���ˣ�\n");
    }
   target=offensive_target(me);
   if(!target)
   return notify_fail("��û��ս����Ŀ�꣡\n");
   
   if(me->is_killing(target->query("id")))
    fight_flag=1;
   message_vision(HIR"\n$N"+HIR+"һ����Х������ħ�󡹣���ʱ���ܺ����ȷ�Ѫ��һ�㣡\n"NOR,me);
   for(i=0;i<sizeof(t);i++){
      if(!t[i]->is_fighting(target)){
        if(fight_flag) {t[i]->kill_ob(target);target->kill_ob(t[i]);}
        else {t[i]->fight_ob(target);target->fight_ob(t[i]);}
      }
      t[i]->set_temp("form_busy",time());
      damage=t[i]->query("apply_points");
      t[i]->add_temp("apply/damage",damage);
      COMBAT_D->do_attack(t[i],target,t[i]->query_temp("weapon"),0,2);
      t[i]->add_temp("apply/damage",-damage);
   }
   
   return 1;
} 