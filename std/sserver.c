// sserver.c

inherit F_CLEAN_UP;

// This function selects a random target for offensive perform or exert eg./functions.
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
	  if(target->query_temp("no_eff_perform")){
	   tell_object(me,"\n"+target->name()+"�书�߳������ѱܿ�����Ĺ��ƣ�\n");
	   return 0;
	  }
	  else return target;
	}
	else return 0;
}
