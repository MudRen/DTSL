//ɫ�ս���
//��
#include <ansi.h>

inherit SSERVER;

#define REDUCE_DEX -125

int perform(object me,object target)
{ 
    object weapon;
    string msg;
    int damage;
    
   if(!target)
    if(!objectp(target=offensive_target(me)))
    return notify_fail("Ŀǰ��û�й�����Ŀ�꣡\n");
   if(!me->is_fighting())
	   return notify_fail("���ա�ֻ����ս����ʹ��!\n");
    weapon=me->query_temp("weapon");
    if(!weapon||weapon->query("skill_type")!="sword")
    return notify_fail("�����޽������ʹ�á��ա���\n");
    if(weapon->query("flag")==1)
		return notify_fail("�ϵ��ı������ʹ�ã�\n");
    if(!me->query_skill("sekong-jianfa",1))
    return notify_fail("��ѧ��ɫ�ս��������ʹ�á��ա���\n");
    if((int)me->query("max_force",1)<1500)
    return notify_fail("�������̫����!\n");
    if((int)me->query_skill("sword",1)<160)
    return notify_fail("��Ļ�������̫���ˣ�\n");
    if((int)me->query_skill("sekong-jianfa",1)<160)
    return notify_fail("��ġ�ɫ�ս������������ң�\n");
    if((int)me->query_skill("qingxin-force",1)<150)
    return notify_fail("��ġ��������ƾ����������ң�\n");
    if(me->query("apply_points")<=0)
    return notify_fail("ƾ��Ŀǰ�������޷�ʩչ���ա���\n");
    if(me->query("perform_quest/kong")
      &&time()-me->query_temp("perform_busy")<10)
       return notify_fail("����ʩչ���ա��־���Ҫ������������֧�֣�����Ϊ������������У�\n");
    if(!me->query("perform_quest/kong")
      &&time()-me->query_temp("perform_busy")<5)
       return notify_fail("����ʩչ���ա��־���Ҫ������������֧�֣�����Ϊ������������У�\n");
    
    damage=me->query("apply_points");
    
    if(!me->query("perform_quest/kong"))
    damage=damage/2;
    
    msg=HIC"��⼤�����������ա�$N"+HIC+"��$w"+HIC+"���������Ӱ����$n"+HIC+"�������С�$N"+HIC+"ȴ��������������ӣ�\n"+
        "�ڽ������������֣��Ʊ�������ǵ����£�ɭ���Ľ���Ʈҡ����֮���������������ѩ��\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("���ա�ֻ����ս����ʹ��!\n");
    
    msg=HIG"���������µ���ʽ��Ʈ�����ɵ����£�$N"+HIG+"ÿ�����ܶ�Ϥ�Ȼ��������߽���$n"+HIG+"��϶�ķ�\n"+
        "����$N"+HIG+"�����὿�񡢶��˸��ĵ���Ů��ֻ��˪��ѩ������ʹ�������缲�����Ŀ��½�\n"+
        "����ʵ������̾Ϊ��ֹ��\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("���ա�ֻ����ս����ʹ��!\n");
        
    msg=MAG"$N"+MAG+"�Ľ������޳ɹ棬��ÿ����һ�����������$n"+MAG+"�����㣬ÿһ������ǧ������֮����\n"+
        "�ɶ����֮�컯����������$N"+MAG+"���淢���Ľ���������к�ص�ˮ������϶���룬���˷���ʤ\n"+
        "����\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("���ա�ֻ����ս����ʹ��!\n");
    
    if(!me->query("perform_quest/kong")){    
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
       
    msg=HIG"�����ǰ�⻪��ʢ��$w"+HIG+"������������������㣬�ƿ������ܲ��ĺ�ҹ������������\n"+
        "���Ƽ򵥵�һ����ʵ�����ޱ����µ��ķ��ͽ����ƻ��ƿ죬�����ٶ���ʹ�����԰�\n"+
        "�գ�����������������ߵ���ͷ��������ʱ�ɸı乥������ĸо���\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("���ա�ֻ����ս����ʹ��!\n");
    
    msg=HIY"$w"+HIY+"��â��գ�����˸��������ʮ�ལ��ÿ������$n"+HIY+"���ò�ȫ��Ӧ����ÿ��������ʵ��\n"+
        "׾��ƫ���п�ɽ���ꡢ��ӯƮ�ݵĸо��������о����$n"+HIY+"�����α仯�����ǰ�$n"+HIY+"��ͨ��\n"+
        "͸һ�㣡\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("���ա�ֻ����ս����ʹ��!\n");
    
    msg=HIG"$N"+HIG+"�������������������������ţ�������һ�����ں���ʱ��üͻĿ��ҧ���гݡ�\n"+
        "ȴ���Ѿ������������ҵ�ͨ�����磬$w"+HIG+"��ȥ�޺ۣ�ʽʽ�����������۵Ľ�����������\n"+
        "�⣬���޲���������Ե��ֵĸ������С�\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    me->set("apply_points",0);
    me->set_temp("perform_busy",time());
    return 1;
}
