// poison.c

#include <condition.h>
#include <ansi.h>
#include <medicine.h>

int update_condition(object me, mapping info)
{
	
	if( !mapp(info) ) return 0;
	
	if(!me->query_temp("medicine_add_temp_force")) return 0;
	
	if( info["times"] <=0 ){
	  me->add("force",-info["number"]);
	  if(me->query("force")<0)
	   me->set("force",0);
	  me->delete_temp("medicine_add_temp_force");
	  tell_object(me,HIY"\n����õ���ʱ����������ҩ��ЧӦ�����ˣ�\n"NOR);
	  return 0;
        }
        
	info["times"] --;

	me->apply_condition("add_temp_force", info);
	
	return CND_CONTINUE;
}
