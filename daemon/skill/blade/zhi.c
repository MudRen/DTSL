//����ʮ��֧��
//�ۻ���ʽpfm.
#include <ansi.h>

inherit SSERVER;

#define REDUCE_DEX -150


int perform(object me,object target)
{ 
    object weapon;
    int damage;
    string msg;
    
    weapon=me->query_temp("weapon");
    
    if(!target)
    if(!objectp(target=offensive_target(me)))
    return notify_fail("Ŀǰ��û�й�����Ŀ�꣡\n");
    if(!me->is_fighting())
    return notify_fail("������ʮ��֧��ֻ����ս����ʹ�ã�\n");
   if(!weapon)
    return notify_fail("�������������ʹ�á�����ʮ��֧����\n");
   if(weapon->query("skill_type")!="blade")
   return notify_fail("��ʹ�õ��������Ͳ��ԣ�\n");
   if(weapon->query("flag")==1)
		return notify_fail("�ϵ��ı������ʹ�ã�\n");
    if(!me->query_skill("zhehua-baishi"))
    return notify_fail("��ѧ���ۻ���ʽ�����ʹ�á�����ʮ��֧����\n");
    if((int)me->query("max_force")<1500)
    return notify_fail("���������Ϊ̫����!\n");
    if((int)me->query_skill("blade",1)<160)
    return notify_fail("��Ļ�������̫���ˣ�\n");
    if((int)me->query_skill("zhehua-baishi",1)<160)
    return notify_fail("����ۻ���ʽ�������ң�\n");
    if(me->query_skill("huachan",1)<160)
    return notify_fail("��Ļ�����Ϊ̫���ˣ�\n");
    if(me->query_skill("flower-force",1)<150)
    return notify_fail("��ķɻ���ˮ��Ϊ̫���ˣ�\n");
    if(me->query("execute_quest/busiyin"))
    return notify_fail("����˲���ӡ���޷���ʩչ������ʮ��֧����\n");
    
    if(!me->query("perform_quest/zhi")
      &&time()-me->query_temp("perform_busy")<5)
      return notify_fail("����ʩչ������ʮ��֧����Ҫ������������֧�֣�����Ϊ������������У�\n");
    
    if( (me->query("perform_quest/zhi")||me->query("perform_quest/zhi_fail") )
      &&time()-me->query_temp("perform_busy")<10)
      return notify_fail("����ʩչ������ʮ��֧����Ҫ������������֧�֣�����Ϊ������������У�\n");
    
    if(me->query("apply_points")<=0)
    return notify_fail("ƾ��Ŀǰ�������޷�ʩչ������ʮ��֧����\n");
    
    damage=me->query("apply_points");
    
    if(me->query("perform_quest/zhi_fail"))
    damage=damage*3/4;
    else
    if(!me->query("perform_quest/zhi"))
    damage=damage/2;
    else
    me->set("apply_points",0);
    
    msg=HIC"һ���ۼ䣬$N"+HIC+"ٿȻ�����ˡ�һ��紵����$n"+HIC+"����ʽ����΢�磬��ɼ����������$N"+HIC+"������Ҷ��\n"+
        "ȴ��Ʈ��$n"+HIC+"��������ؼ����Կɶݣ��޵ؿɻ�޴����ӵ�һ��һ����ȴ��Ȼ��紵����\n"+
        "����ס$N"+HIC+"��\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("������ʮ��֧��ֻ����ս����ʹ��!\n");
    
    msg=HIM"$N"+HIM+"��$w"+HIM+"�����ſ�����ͬ�ʻ�ŭ�ţ�������ɱ�ţ����濴ȥȴ�������������ڽ��ȼ�������\n"+
        "��һ�����ݵĳ�Ȼ��ζ������Ϊ���˻��������ɣ�ȴ���ʷ׳ʣ���û���ּ֮��\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("������ʮ��֧��ֻ����ս����ʹ��!\n");
    
    msg=WHT"$N"+WHT+"ȫ����һƬ��Ӱ�������裬ֻ��$N"+WHT+"Խ��Խ�����赽��󣬴�����Χ������ͬ�����ѩ��\n"+
        "����һ�����εķ��ߣ�������һ�𣬶�$N"+WHT+"��Ϊ����������ģ���ǧ�ٶ�ѩ�����裬���ס��\n"+
        "Ӱ��Ȼ����$w"+WHT+"ʼ��δ������\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("������ʮ��֧��ֻ����ս����ʹ��!\n");
    
    msg=HIY"$N"+HIY+"�����趯��$w"+HIY+"�漣��ҫ����������ͬ�¹������ȹ��ϣ�����̫��һ�������¹�����\n"+
        "��˲���ѣ˸�������������¾���������$N"+HIY+"���������£���â���������ϣ��羲������\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("������ʮ��֧��ֻ����ս����ʹ��!\n");
    
    if(!me->query("perform_quest/zhi")){
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
    
    damage=damage*me->query("perform_quest/zhi_damage")/90;
    
    msg=YEL"$N"+YEL+"��$w"+YEL+"��ס��ã�������������ӰΧס$n"+YEL+"����������߽ࡣ�ȷ���˪ŭ�ţ��躮����\n"+
        "�����������ϵ����ˣ���īɫ��ʾ�����޶�Ŀ�Ĺ�ʡ�\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("������ʮ��֧��ֻ����ս����ʹ��!\n");
    
    msg=HIM"$w"+HIM+"ת����$N"+HIM+"��ͬ��ѩ��˪��$N"+HIM+"����������������ɫ���ã�һʱ����������಻ͬ����\n"+
        "�����ʣ��������취��ⲻ��Ѱ������������أ��֮����������¶��������������\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("������ʮ��֧��ֻ����ս����ʹ��!\n");
    
    msg=HIG"$N"+HIG+"����������$w"+HIG+"ƬƬ���䣬��紵������ƬƬ$w"+HIG+"�������𶯷���������������ζ�Ƴ���\n"+
        "$n"+HIG+"�������ƣ����������ε�����������һ����������$w"+HIG+"Ĥ�ݵ�������ȫȻ���˼�������\n"+
         "��Ƭ��\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("������ʮ��֧��ֻ����ս����ʹ��!\n");
    
    msg=HIY"�ռ�仯��ɢ����$w"+HIY+"����Ů����ͻȻ������$n"+HIY+"����ǰ����ׯ�����ʣ����������࣬\n"+
        "ͤͤ��������Ů����������Ϊ֮�㵹��$N"+HIY+"���κ�$w"+HIY+"��������òң���Ӧ��\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("������ʮ��֧��ֻ����ս����ʹ��!\n");
    
    if(random(100)>70){
    	msg="\n$n�������ƣ���������Ȼ��У���ͬ����һ�㣬���ް�����ƿ��ԣ�\n";
        target->start_busy(2);
       if(random(100)>80){
        msg+="\n$N������ã�$n��ͬ���ݻ�Ӱ��������������������������\n";
        target->start_busy(4);
        if(random(100)>90){
         msg+="\n$N���ڻ����趯����ͬ����֮�꣬ңң��ס$n��\n";
         target->start_busy(6);  
           if(random(100)>95){
             msg+="\n"+weapon->name()+"���£����ϵ������绨��������л��$n���ɷ���ٯ���Ứ��Ц�գ�\n"+
                  "������ٯ֪��˭�ĸ�̾��\n";
             target->start_busy(8); 
           }
        }
      }
      
      message_vision(msg,me,target);
    }
        
   me->set_temp("perform_busy",time());
   
 return 1;   
  
} 

