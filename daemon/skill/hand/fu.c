//���⸿ӡ

#include <ansi.h>



inherit SSERVER;



#define REDUCE_DEX -30



int perform(object me,object target)

{ 

     int flag=0;

     

     object weapon;

     

     if(!target)

    if(!objectp(target=offensive_target(me)))

    return notify_fail("Ŀǰ��û�й�����Ŀ�꣡\n");

    

     weapon=me->query_temp("weapon");	

     if(weapon)

    return notify_fail("�������������ʹ�á����⸿ӡ����\n");

    if(!me->is_fighting())

    return notify_fail("ֻ����ս��ʱ�ſ���ʹ�á����⸿ӡ����\n");

    if(!me->query_skill("jiuzi-zhenyan",1))

    return notify_fail("��ѧ���������ԡ����ʹ�á����⸿ӡ����\n");

    if((int)me->query("max_force")<3000)

    return notify_fail("���������Ϊ̫����!\n");

    if((int)me->query("force")<200)

    return notify_fail("�����������ʹ�ô�����!\n");

    if((int)me->query_skill("jiuzi-zhenyan",1)<160)

    return notify_fail("��ľ�������̫���ˣ�\n");

    if((int)me->query_skill("strike",1)<160)

    return notify_fail("��Ļ����Ʒ��������ң�\n");

    

    if(time()-me->query_temp("perform_busy")<20)

      return notify_fail("����ʩչ�����⸿ӡ����Ҫ������������֧�֣�����Ϊ������������У�\n");
    

    me->add("force",-200);

    

    flag+= COMBAT_D->do_perform_attack(0,REDUCE_DEX,"",me,target,0,0,2);

    

    if(!me->is_fighting())

    return notify_fail("�����⸿ӡ��ֻ����ս����ʹ��!\n");

    

    flag+=COMBAT_D->do_perform_attack(0,REDUCE_DEX,"",me,target,0,0,2);

    

    if(flag){

       message_vision("\n$n��$N���У��������ɵÿ�к������\n",me,target);

       target->add("force",-me->query_skill("jiuzi-zhenyan",1)*2);

       if(target->query("force")<0)

        target->set("force",0);

    }

    

    me->set_temp("perform_busy",time());

    return 1;   

  

}  

