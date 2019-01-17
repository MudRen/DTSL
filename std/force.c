// force.c

inherit SKILL;

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int damage;
//	already taken care of in combatd.c
//        me->add("force", - factor );
        damage = (int)me->query_skill("force")/20 + factor
                - (int)victim->query_skill("force")/100;

        if( damage < 0 ) {
                if( !me->query_temp("weapon")
                &&      random(victim->query_skill("force")) > 
me->query_skill("force")/2 ) {
                        damage = - damage;
                        me->receive_damage( "kee", damage * 2 );
                        me->receive_wound( "kee", damage );
                        if( damage < 10 ) return 
"$N�ܵ�$n�����������ƺ�һ����\n";
                        else if( damage < 20 ) return 
"$N��$n���������𣬡��١���һ������������\n";
                        else if( damage < 40 ) return 
"$N��$N������һ���ؿ������ܵ�һ���ػ�����������������\n";
                        else return 
"$N��$n������һ����ǰһ�ڣ���������ɳ�������\n";
                }
                if( damage_bonus + damage < 0 ) return - damage_bonus;
                return damage;
        }

        damage -= victim->query_temp("apply/armor_vs_force");
        if( damage_bonus + damage < 0 ) return - damage_bonus;
                return random(damage) * 2 + 1;
}
 
