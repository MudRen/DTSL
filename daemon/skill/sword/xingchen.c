//��ת����
//��ת�ǳ�
#include <ansi.h>

inherit SSERVER;

#define REDUCE_DEX 100

int perform(object me,object target)
{ 
    object weapon;
    string msg;
    int damage,flag;
    
    flag=0;
   if(!target)
    if(!objectp(target=offensive_target(me)))
    return notify_fail("Ŀǰ��û�й�����Ŀ�꣡\n");
   if(!me->is_fighting())
	   return notify_fail("����ת�ǳ� ��ֻ����ս����ʹ��!\n");
    weapon=me->query_temp("weapon");
    if(!weapon||weapon->query("skill_type")!="sword")
    return notify_fail("�����޽������ʹ�á���ת�ǳ� ����\n");
    if(weapon->query("flag")==1)
		return notify_fail("�ϵ��ı������ʹ�ã�\n");
    if(!me->query_skill("jiuzhuan-jianjue",1))
    return notify_fail("��ѧ����ת���������ʹ�á���ת�ǳ� ����\n");
    if((int)me->query("max_force",1)<1500)
    return notify_fail("�������̫����!\n");
    if((int)me->query_skill("sword",1)<160)
    return notify_fail("��Ļ�������̫���ˣ�\n");
    if((int)me->query_skill("jiuzhuan-jianjue",1)<160)
    return notify_fail("��ġ���ת�������������ң�\n");
    if((int)me->query_skill("jiuxuan-dafa",1)<150)
    return notify_fail("��ġ������󷨡��������ң�\n");
    if(me->query("apply_points")<=0)
    return notify_fail("ƾ��Ŀǰ�������޷�ʩչ����ת�ǳ� ����\n");
    if(me->query("perform_quest/xingchen")
      &&time()-me->query_temp("perform_busy")<10)
       return notify_fail("����ʩչ����ת�ǳ�����Ҫ������������֧�֣�����Ϊ������������У�\n");
    if(!me->query("perform_quest/xingchen")
      &&time()-me->query_temp("perform_busy")<5)
       return notify_fail("����ʩչ����ת�ǳ�����Ҫ������������֧�֣�����Ϊ������������У�\n");
    
    damage=me->query("apply_points");
    
    if(!me->query("perform_quest/xingchen"))
    damage=damage/3;
    else damage=damage/2;
    
    msg=HIG"$N"+HIG+"��$w"+HIG+"��������ȫ�����������$n"+HIG+"��Ϊ��̾�ı仯���Ժ���֮��ܹ�$n"+HIG+"�Ĺ�������\n"+
        "�����������ݰ�����ת����$w"+HIG+"���ƣ�����$n"+HIG+"��$l�����������㡣\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("����ת�ǳ� ��ֻ����ս����ʹ��!\n");
    
    msg=HIY"$N"+HIY+"����ңָ$n"+HIY+"����ס���������µ÷�����ֻ���׵�����$n"+HIY+"�е�����һ�����µĽ�����\n"+
        "�ܰ�ȫ�������۴��棬��ȡ��仯�޶����������Դ��⡣�˽������������Ƕ���ɽ��\n"+
        "֮�ƣ�\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("����ת�ǳ� ��ֻ����ս����ʹ��!\n");
        
    msg=MAG"$N"+MAG+"����$w"+MAG+"������տտ����â�����������˼���̬���ߺ��������Ķ�������������\n"+
        "��������������ʯ�㱻�������ĳ�ˮ�������$w"+MAG+"�ķ�⣬ɲ�Ǽ���������һ��������\n"+
        "�滯Ϊһ����⣬������ϼ������Ĳ����ǹ⣬���ǰ���$n"+MAG+"˫Ŀ���λ�ñ������˵���\n"+
        "�����繴�����ǵ�ħ�����������㣬���������㡣\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("����ת�ǳ� ��ֻ����ս����ʹ��!\n");
    
    if(!me->query("perform_quest/xingchen")){    
      me->set_temp("perform_busy",time());
      return 1;
    }
    me->set_temp("perform_busy",time());
    call_out("perform2",3,me,target,weapon,damage);
    
    return 1;   
  
}  

int perform2(object me,object target,object weapon,int damage)
{ 
        string msg;
        
        if(!me) return 1;
        if(!target||!living(target)){
         me->set_temp("perform_busy",time());
         return 1;
        }
        me->set_temp("perform_busy",time());
        if(!weapon||me->query_temp("weapon")!=weapon)
        return 1;
        if(me->is_busy())
        return 1;
  
        if(!me->is_fighting(target))
	   return 1;
       
    msg=HIG"$N"+HIG+"�����ݳ�һ˿Ц�⣬$w"+HIG+"�����Ľ�������$n"+HIG+"�����������ƹ����أ���϶����Ĺ�����\n"+
        "ٿ��$n"+HIG+"��ǰ�ֳ������ǵ㣬ÿһ�㶼�ƺ�����$n"+HIG+"��������ÿһ�㶼��ˮ�㲻��������\n"+
        "���ϵ��ǿգ��ڱ仯�������Ծߺ㳣�����ζ��������������ˮ���������಻�ϵĳ����о���\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("����ת�ǳ� ��ֻ����ս����ʹ��!\n");
    
    msg=HIY"$N"+HIY+"�����ݳ���һ˿Ц�⣬����$w"+HIY+"����$n"+HIY+"ȴû�з���Ӧ�еľ��죬ƾ������������Ը�\n"+
        "ɽ��ţ�ķ�������ȥ$n"+HIY+"�ľ�����$w"+HIY+"�Ƶ�$n"+HIY+"�����������һ�������Ļ��ߣ�����$n"+HIY+"���\n"+
        "������������������ǿ�����������$n"+HIY+"�������ŵر�$w"+HIY+"ǣ��������ȥ��\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("����ת�ǳ� ��ֻ����ս����ʹ��!\n");
    
    msg=HIG"$N"+HIG+"¶��������ɫ��$w"+HIG+"���ڿ��п�ݼ��鼶�����������ĳ��������̬���������Ƶ�\n"+
        "$n"+HIG+"�ۻ����ң��޴����֣���֪�ù���δ���ٿ����$N"+HIG+"�ְ��ƶ�Ȩ�������ϡ������Ƚ���\n"+
        "�Խ��ȵУ�$N"+HIG+"�����������ȣ�ǣ��$n"+HIG+"�ı����ߡ�\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("����ת�ǳ� ��ֻ����ս����ʹ��!\n");
    
    me->set_temp("perform_busy",time());
    call_out("perform3",3,me,target,weapon,damage);
    
    me->add("apply_points",50);
    me->set_temp("perform_busy",time());
    return 1;
}

int perform3(object me,object target,object weapon,int damage)
{ 
        string msg;
        
        if(!me) return 1;
        if(!target||!living(target)){
         me->set_temp("perform_busy",time());
         return 1;
        }
        me->set_temp("perform_busy",time());
        if(!weapon||me->query_temp("weapon")!=weapon)
        return 1;
        if(me->is_busy())
        return 1;
  
        if(!me->is_fighting(target))
	   return 1;
       
    msg=HIG"$N"+HIG+"һ��Ц��$w"+HIG+"����һ������ȴ��ʵ�Ľ�Ȧ����Ȧ���Ծ���������󣬽���΢��\n"+
        "��һȦһȦ���ӡ�������ǡ��$n"+HIG+"����֮����$n"+HIG+"��������ˮ�����޵ر���ਵ�һ�β�ʣ��\n"+
        "�����γ��κ���в����һ�и�ʹ����ȥ��\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("����ת�ǳ� ��ֻ����ս����ʹ��!\n");
    
    msg=HIY"$N"+HIY+"ٿ�ؽ����ʢ��$N"+HIY+"������ǣ���£�������â���ǣ�$w"+HIY+"��һ��һ����С�����������\n"+
        "�׽������Ž�ǰ�ƣ���������İѴ�С�����������$n"+HIY+"�������ڻ���$n"+HIY+"һ�̣�������\n"+
        "��С���ɻ������ƵĽ������Ե��ʯ��ĸ��پ�£�������������Կ��ܵľ��˽�����\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("����ת�ǳ� ��ֻ����ս����ʹ��!\n");
    
    msg=HIC"$N"+HIC+"���������$w"+HIC+"�����ǧ������ȥ��$w"+HIC+"�����������е�������ǰ����ѭ�ž��ô��\n"+
        "���������·�ߣ����Ҳ����������������$n"+HIC+"��ȫ���֡����и����ǵ��޿ɵ����˽���\n"+
        "���������Ƕ���ɽ��֮�ơ�\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
   
    me->set("apply_points",0);
    me->set_temp("perform_busy",time());
    return 1;
}
