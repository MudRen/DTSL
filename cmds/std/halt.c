
#include "/doc/help.h"
inherit F_CLEAN_UP;
#include <ansi.h>

int main(object me, string arg)
{
   object ob;
   
   if( arg && wizardp(me) ) {
		ob = present(arg, environment(me));
		if( !ob ) return notify_fail("û��������\n");
		if( !ob->is_fighting() ) return notify_fail(ob->name()+"���ڲ�æ��\n");
		ob->remove_all_enemy();
                message_vision("\n$N����ʦ������ֹͣ��$n��ս����\n", me, ob);
		return 1;
	}
    
    if(wizardp(me)&&me->is_fighting()){
      
       me->remove_all_killer();
       tell_object(me,"������ʦ������ֹͣ��ս����\n");
       message_vision("\n$N���һԾ������սȦ�����ˡ�\n",me);
       return 1;
       }
    
	if (!me->is_busy() && me->is_fighting()) {
	        
	        me->remove_all_enemy();
                message_vision("\n$N�������һԾ������սȦ�����ˡ�\n", me); 
		return 1;
	}
   if(!me->is_busy()){
    tell_object(me,"�����ڲ�æ��\n");
    return 1;}
   
   me->interrupt_me();
   
   if(me->is_busy())
    tell_object(me,"�����ں�æ��ͣ��������\n");
   
   return 1;
}

int help(object me)
{
   write(@HELP
ָ���ʽ: halt

����ֹͣ���������йص�ս��,���������ɡ�
HELP
   );
   return 1;
}
