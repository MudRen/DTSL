
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int times)
{
   if( !living(me) ) {
      message("vision", me->name() + "ʹ��غ���һ����\n", environment(me), me);
	  me->set_temp("death_msg","���˶���ɢ���ˣ�\n");
   }
   else {
      tell_object(me, HIB "ͻȻ��ȫ��һ�󶶶������������������ɵ�[����ɢ]��\n" NOR );
      message("vision", me->name() + "���ӻ��˻Σ���Щվ�����ˡ�\n",
            environment(me), me);
	   me->start_busy(2);
   }
      me->receive_damage("kee", 25);
      me->receive_wound("gin", 10);
      me->apply_condition("dulongsan", times - 1);
   if( times < 1 ) return 0;
   return CND_CONTINUE;
}
