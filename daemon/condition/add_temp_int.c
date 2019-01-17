// poison.c

#include <condition.h>
#include <ansi.h>
#include <medicine.h>

int update_condition(object me, mapping info)
{
	
	if( !mapp(info) ) return 0;
	
	if(!me->query_temp("medicine_add_temp_int")) return 0;
	
	if( info["times"] <=0 ){
	  me->add_temp("apply/intelligence",-info["number"]);
	  tell_object(me,HIY"\n����õ���ʱ�������Ե�ҩ��ЧӦ�����ˣ�\n"NOR);
	  return 0;
        }
        
	info["times"] --;

	me->apply_condition("add_temp_int", info);
	
	return CND_CONTINUE;
}
