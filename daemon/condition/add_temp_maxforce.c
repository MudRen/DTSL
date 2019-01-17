// poison.c

#include <condition.h>
#include <ansi.h>
#include <medicine.h>

int update_condition(object me, mapping info)
{
	
	if( !mapp(info) ) return 0;
	
	if(!me->query_temp("medicine_add_temp_maxforce")) return 0;
	
	if( info["times"] <=0 ){
	  me->add("max_force",-info["number"]);
	  if(me->query("max_force")<0)
	   me->set("max_force",0);
	  me->delete_temp("medicine_add_temp_maxforce");
	  tell_object(me,HIY"\n����õ���ʱ�����������޵�ҩ��ЧӦ�����ˣ�\n"NOR);
	  return 0;
        }
        
	info["times"] --;

	me->apply_condition("add_temp_maxforce", info);
	
	return CND_CONTINUE;
}
