//ɢ�ְ���
//���ˡ�

#include <ansi.h>

inherit SSERVER;

#define REDUCE_DEX -50

int perform(object me,object target)
{ 
   object weapon;
   string msg;
   int damage,flag=0;
   int str,inte;
   int add;
   
    weapon=me->query_temp("weapon");
   
   if(!target)
    if(!objectp(target=offensive_target(me)))
    return notify_fail("Ŀǰ��û�й�����Ŀ�꣡\n");
   if(!me->is_fighting())
   return notify_fail("�����ˡ�ֻ����ս����ʹ��!\n");
   if(weapon)
    return notify_fail("�������������ʹ�á����ˡ���\n");
    if(!me->query_skill("sanshou-strike",1))
    return notify_fail("��ѧ��ɢ�ְ��ˡ����ʹ�á����ˡ���\n");
    if((int)me->query("max_force")<1500)
    return notify_fail("���������Ϊ̫����!\n");
    if((int)me->query_skill("strike",1)<120)
    return notify_fail("��Ļ����Ʒ�̫���ˣ�\n");
    if((int)me->query_skill("sanshou-strike",1)<120)
    return notify_fail("��ġ�ɢ�ְ��ˡ��������ң�\n");
    
    if(me->query("apply_points")<=0)
    return notify_fail("ƾ��Ŀǰ�������޷�ʩչ�����ˡ���\n");
    if(me->query("perform_quest/bapu")
      &&time()-me->query_temp("perform_busy")<10)
      return notify_fail("����ʩչ�����ˡ���Ҫ������������֧�֣�����Ϊ������������У�\n");
    if(!me->query("perform_quest/bapu")
      &&time()-me->query_temp("perform_busy")<5)
      return notify_fail("����ʩչ�����ˡ���Ҫ������������֧�֣�����Ϊ������������У�\n");
    
    damage=me->query("apply_points");
    if(!me->query("perform_quest/bapu"))
    	damage=damage/2;
    else{
   		str = me->query("str");
		inte = me->query("int"); 
    	if(str>=38&&inte>=38){  			
  			add = str-38;
  			if(inte-38>add)
  				add = inte-38;
  			damage = damage+damage*(add/2)*20/100;
  			
  		}
  		else
  		if(str>=35&&inte>=35)
  			damage = damage*2/3;
  		else
  			damage = damage/2;
    
    
   	}
    me->set("apply_points",0);
    
    msg=HIY"$N"+HIY+"˫�ֺ�ʲ��˫Ŀ����ʢ��Ŀע$n"+HIY+"������$n"+HIY+"���ٵ�ͬһɲ�ǣ�$N"+HIY+"��£�����ַֿ���\n"+
        "��Ԥ֪��$n"+HIY+"�����ı仯��$N"+HIY+"��ǰ��������˷��ˣ��������죬ֻ�����ٶ��ϵ�������\n"+
        "�⣬�ɽ��˿���ͷʹ���ѣ�ƫ���������ÿ���\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    if(!me->is_fighting())
    return notify_fail("�����ˡ�ֻ����ս����ʹ��!\n");
   
    msg=HIG"$N"+HIG+"ٿ�ر��Ա�������$n"+HIG+"�������������鰴��ǰ����������������ִ�����̽����\n"+
        "�Ʊ�ץ��ץ��ָ����������������ִ�����̽�����Ʊ�ץ��ץ��ָ�������Ĵָ����\n"+
        "�ʻ�������$n"+HIG+"�Ĺ�������仯֮�����ƾ�о��жϵ���λ�ã�����̾Ϊ��ֹ��\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    if(!me->is_fighting())
    return notify_fail("�����ˡ�ֻ����ս����ʹ��!\n");
   
    msg=HIR"$N"+HIR+"ͷ�½��ϵ�����$n"+HIR+"�Ϸ������Ӱ��´죬ײ��$n"+HIR+"����֮�ڣ�������ͷ��Ӳ�$n"+HIR+"ͷ�ǣ�\n"+
        "һ�����������������\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    if(!me->is_fighting())
    return notify_fail("�����ˡ�ֻ����ս����ʹ��!\n");
    
    msg=WHT"$N"+WHT+"���ֻ��ţ��������ģ�ٿ���������У���ǧ��������ͷ�����С����ǰ���ֶ�׷\n"+
        "���������ģ����������ֺ�����$n"+WHT+"��ȥ�������ֳ��ƺ�ͯŪȸ��������ɫ�������\n"+
        "�ε��������������С�������Ծ�£�׷�������������������\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    
    if(!me->query("perform_quest/bapu")){
    	me->set_temp("perform_busy",time());
        return 1;
    }
    
    call_out("perform2",3,me,target,damage);
    me->set_temp("perform_busy",time());
    return 1;   
  
}  

int perform2(object me,object target,int damage)
{
    string msg;
    int flag=0;
    
    if(!me||!target)
    return 1;
    if(!me->is_fighting(target))
    return 1;
    
    if(me->query_temp("weapon"))
    return 1;
    
    if(me->is_busy())
    return 1;
    
    msg=HIG"$N"+HIG+"�Ա������ָ������̬��˫Ŀ��â������ļ��ֱͦ��ǣ�ȫ�������޷��Զ�����ü\n"+
        "���ţ���̬����������Σ���$n"+HIG+"��Ⱥ���ѷɫ��һȭ�����������������¾���������\n"+
        "�κ����ݵ�����仯��ȴ���Ǻ���α���һȭ����$n"+HIG+"��$l��\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    if(!me->is_fighting())
    return notify_fail("�����ˡ�ֻ����ս����ʹ��!\n");
  
    msg=HIY"$N"+HIY+"��ǧ���򻯵Ķ������ƽ����ˡ��������£�˫��ʩ������Ī����ַ�����¯���ࡢ\n"+
        "�����˻���������������һ����Զ����$n"+HIY+"��֯�����ζ���ʵ�������������˿������\n"+
        "�����ļ�ǡ����$n"+HIY+"������ʵ�������������˿�����������ļ�ǡ����$n"+HIY+"���潻���һ\n"+
        "�̻������������۷壬����$n"+HIY+"��ɱ��һ�С�\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    if(!me->is_fighting())
    return notify_fail("�����ˡ�ֻ����ս����ʹ��!\n");
   
    msg=WHT"$n"+WHT+"����$N"+WHT+"���Ż�����ĵ��������˲������ŵ�����ں��������·�����$N����һƬ\n"+
        "��ë�㣬����$n"+WHT+"����Ŀ�쩱��ε�������ˣ��Ժ���֮���Ź��������������������\n"+
        "�������ţ���ȷΪ��ʵ������������£����г��������������г������\n"NOR;
    
    flag = COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    if(!me->is_fighting())
    return notify_fail("�����ˡ�ֻ����ս����ʹ��!\n");
    
    msg=HIC"$N"+HIC+"ͻ��һ����Х���ڿ��к�Ȼ���������Ӱ㼲��׶�£��������棬���$n"+HIC+"��ʹ����ɫ\n"+
        "���һ�У�$N"+HIC+"������̬���ţ�����������������ηӰ�񼣶�ȥ֮���ߣ�������������\n"+
        "���࣬��������Ӱ��������֪��������Ӱ��������Ϣ�����������ӡ���$N"+HIC+"�����˵�\n"+
        "�ϰ�գ�����$n"+HIC+"ǿ����һ����\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    if(flag){
      message_vision("\n$n��$N���У����β��ɵ�һ�ͣ�\n\n",me,target);
      target->start_busy(3);
    }
    
    me->set_temp("perform_busy",time());
    return 1;
}
