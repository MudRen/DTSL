

inherit SSERVER;

#include <ansi.h>


void hit_ob(object me, object victim)
{   
    int flag,ini_damage_apply,damage;
    string str;
         //1)
     if(me->query_temp("apply_effskill_feilong",1))
     return;
     //2)
     me->add_temp("effskill_feilong_times",1);
    
    if (victim->query("eff_kee")<0 || !living(victim) )  
    return;
    
    if(!me->is_fighting(victim))
    return;
    //3)
    if(me->query_temp("effskill_feilong_times")<2)
    return;
    //4)
    me->set_temp("apply_effskill_feilong",1);
         
    //5)   
   if ( random(2)>0 ){
   	    //6)
   	    me->set_temp("effskill_feilong_times",-1);  
   	    
   	    damage=me->query("apply_points")*3/2+me->query_skill("dijian-jue",1)*2/3;//damage ȡ����
   	    
   	    if(me->query_skill("dijian-jue",1)<160)
   	     damage=damage/2;
   	      	   
           ini_damage_apply = me->query_temp("apply/damage");
            me->add_temp("feilong_time",-1);
            
            me->add_temp("apply/damage",damage);
            str=HIG"$N"+HIG+"ʹ������������һʽ������$w"+HIG+"ɢ����㽣�⣬����������\n"NOR;
            me->set_temp("action_msg",str);//ս��ϵͳ�����ô˱�������
            flag=COMBAT_D->do_attack(me, victim, me->query_temp("weapon"),0,1);
            if(!me->is_fighting()){
             me->delete_temp("apply_effskill_feilong");
             me->delete_temp("action_msg");
             me->set_temp("apply/damage",ini_damage_apply);
             
             return; 
            }    
            
      if(flag){
           me->add_temp("apply/damage",damage);
           str=HIR"��㽣��ɢȥ�����صĽ����·������룬�ƿ�֮���̶�֮�������Ƿ��������ڶ�ʽ��\n"NOR;
           me->set_temp("action_msg",str);
           flag=COMBAT_D->do_attack(me, victim, me->query_temp("weapon"),0,1);         
           me->add_temp("feilong_time",-1);
           me->delete_temp("action_msg");
           if(!me->is_fighting()){
             me->delete_temp("apply_effskill_feilong");
             me->delete_temp("action_msg");
             me->set_temp("apply/damage",ini_damage_apply);
            
             return; 
            } 
        }
      if(flag){
           me->add_temp("apply/damage",damage);
           str=WHT"����͸�������$N"+WHT+"����$w"+WHT+"����һ�����磬����������ĸ��ٶȽ���������\n"NOR;
           me->set_temp("action_msg",str);
           flag=COMBAT_D->do_attack(me, victim, me->query_temp("weapon"),0,1);         
           me->add_temp("feilong_time",-1);
           me->delete_temp("action_msg");
           
           if(!me->is_fighting()){
             me->delete_temp("apply_effskill_feilong");
             me->delete_temp("action_msg");
             me->set_temp("apply/damage",ini_damage_apply);
             return; 
            } 
           

           }  
          
    }             
    else{
     me->add_temp("feilong_time",-1);
    }
    //7)    
    me->delete_temp("apply_effskill_feilong");
    me->delete_temp("action_msg");
    me->set_temp("apply/damage",ini_damage_apply);
          
}
 
