
#include <condition.h>

int update_condition(object me, int flag)
{
	object killer;
	
	flag--;
	
	if(flag<=0){
		
	 killer=new(__DIR__"killer");
	 killer->set_status(me);
	 killer->move(environment(me));
	 tell_object(me,"\nһ����紵������\n");
	 message_vision("\n$N��$n�ȵ����μұ����࣬����������\n\n",killer,me);
	 killer->kill_ob(me);
	 killer->set_leader(me);
        
        me->add("kill_same_party_flags/killers",-2);
        if(me->query("kill_same_party_flags/killers")<=0)
         return 0;
        me->apply_condition("kill_same_party",10);        
	return CND_CONTINUE;
        }
                  
        me->apply_condition("kill_same_party",flag);
        
	return CND_CONTINUE;
}
