// poison.c

#include <condition.h>
#include <ansi.h>
#include <medicine.h>

int update_condition(object me, mapping info)
{
	mapping heal;
        string *types;
        int i;
        
	if( !mapp(info) ) return 0;

	types=keys(info);
        for(i=0;i<sizeof(types);i++){
           if(!functionp(poison_type[types[i]])){
              continue;
           }
           evaluate(poison_type[types[i]],me,info[types[i]]);
        }

	info["times"] --;

	me->apply_condition("quest_poison", info);
	message_vision(HIB"$N"+HIB+"�е�"+info["names"]+"�����ˣ�\n\n"NOR,me);
	if( info["times"] <=0 ) return 0;

	return CND_CONTINUE;
}
