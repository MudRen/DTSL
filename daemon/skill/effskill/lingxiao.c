
//��ħ����ն��

/*
������ perform ��д������

�� /daemon/skill/��Ӧ��������/perform����/ �½�����Ӧ��perform�ļ���
�磺tianmo-zhan ���� dagger �࣬�� perform �ļ�Ŀ¼Ϊ��
    /daemon/skill/dagger/lingxiao.c
   ս��ϵͳ������� perform ���ṩ�ı�����Ѱ��ִ���ļ���
   �� perform lingxiao �ı���Ϊ��actionp_hit/lingxiao
   �� ս��ϵͳ�� �� /daemon/skill/effskill/ ��Ѱ��lingxiao.c ���
   �ļ�����ִ���ļ��� hit_ob(object me,object victim) ������
   
   ��������������͵�perform��ֻҪ��֤ �������� �� 
   /daemon/skill/effskill/ �µ�ִ���ļ�����һ�¾Ϳ����ˡ�
*/
/*
����˵����
flag:�����ж��Ƿ���жԷ���
     flag=COMBAT_D->do_attack(me, victim, me->query_temp("weapon"),0,1);
     do_attack����������1)me:��������2)victim:���ط�
                        3)me->query_temp("weapon"):������������
                        4)�Ƿ�ʹ���� apply ��ʹ�õ� mapping apply_action
                          һ����ã��˲�������Ϊ�㡣
                        5)��־��һ��Ϊ 1��
     ����ֵ flag Ϊ 1 ʱ����ʾ���У�0 Ϊû���С�

ini_damage_apply: ����������ĸ����˺���

ִ�з�ʽ��

1)�����ж� �������Ƿ��� apply_effskill_lingxiao ���� ������У���ִ�У�
    ���Է�ֹ������ѭ���С�
2) effskill_lingxiao_times ������ֵ��һ��

3) �� effskill_lingxiao_times �Ƿ�ﵽ ���� 2������ǣ��������

4) �趨 apply_effskill_lingxiao ��������ֹ������ѭ���С����� 1)��Ҫ�жϡ�

5) ���Ƿ���Գ����С�

6) �� effskill_lingxiao_times ������Ϊ -1���������Ҫ��ʹ�ô�����������
   �� �� �к�ſ��ԡ�

7) ɾ�� apply_effskill_lingxiao ���������Լ���ʹ�ô�������

*/


inherit SSERVER;

#include <ansi.h>

void show_msg(object me,object victim)
{
    string str;
    
     if (userp(victim))
          if (victim->query("eff_kee")<0 || 
          !living(victim) 
          )
                 {
          str="��˵"+victim->name()+""HIM"����"+me->name()+""HIM"��"HIW"��ħ����ն"HIM"֮�£�ʬ���������������µ��˺ۣ�"NOR;
                        message("channel:rumor",HIM"��ҥ�ԡ�ĳ�ˣ�"+str+"\n"NOR,users());
     }
     return;
}

void hit_ob(object me, object victim)
{   
    int flag,ini_damage_apply,damage;
    string str;
         //1)
     if(me->query_temp("apply_effskill_lingxiao",1))
     return;
     //2)
     me->add_temp("effskill_lingxiao_times",1);
    
    if (victim->query("eff_kee")<0 || !living(victim) )  
    return;
    
    if(!me->is_fighting(victim))
    return;
    //3)
    if(me->query_temp("effskill_lingxiao_times")<2)
    return;
    //4)
    me->set_temp("apply_effskill_lingxiao",1);
         
    //5)   
   if ( random(2)>0 ){
   	    //6)
   	    me->set_temp("effskill_lingxiao_times",-1);  
   	    
   	    damage=me->query("apply_points")*3/2+me->query_skill("tianmo-zhan",1)*2/3;//damage ȡ����
   	    
   	    if(!me->query("perform_quest/lingxiao"))
   	    damage=damage/2;
   	        	  
            me->add_temp("lingxiao_time",-1);
            
            me->add_temp("apply/damage",damage);
            str=HIG"$N"+HIG+"�߶���ħ�󷨣�ֻ�Գ����һ��Ĵָ���أ�����Ʈ�裬��������û�������Ƶģ�\n"+
               "���ޱ���ӯ����������̬��������Ȱ�Ʈ����������$n"+HIG+"������\n"NOR;
            me->set_temp("action_msg",str);//ս��ϵͳ�����ô˱�������
            flag=COMBAT_D->do_attack(me, victim, me->query_temp("weapon"),0,1);
            me->add_temp("apply/damage",-damage);
            if(!me->is_fighting()){
             me->delete_temp("apply_effskill_lingxiao");
             me->delete_temp("action_msg");
             show_msg(me,victim);
             return; 
            }    
            
      if(flag){
           me->add_temp("apply/damage",damage);
           str=HIR"$N"+HIR+"һ����������$n"+HIR+"���������������¶����ѩ��˪��С�ۣ�\n"+
               "��������ħն��ȡ$n"+HIR+"���ʺ��С��������������\n"NOR;
           me->set_temp("action_msg",str);
           flag=COMBAT_D->do_attack(me, victim, me->query_temp("weapon"),0,1);         
           me->add_temp("lingxiao_time",-1);
           me->add_temp("apply/damage",-damage);
           if(!me->is_fighting()){
             me->delete_temp("apply_effskill_lingxiao");
             me->delete_temp("action_msg");
             show_msg(me,victim);
             return; 
            } 
        }
      if(flag){
           me->add_temp("apply/damage",damage);
           str=WHT"$N"+WHT+"��������һ��������$n"+WHT+"��������������õ�����$wңָ$n"+WHT+"�����Ʊ��ˣ�\n"+
               "��������;�У��ٹ�������������һ�У�\n"NOR;
           me->set_temp("action_msg",str);
           flag=COMBAT_D->do_attack(me, victim, me->query_temp("weapon"),0,1);         
           me->add_temp("lingxiao_time",-1);
           me->add_temp("apply/damage",-damage);
           me->delete_temp("action_msg");
           
           show_msg(me,victim);
           if(!me->is_fighting()){
             me->delete_temp("apply_effskill_lingxiao");
             me->delete_temp("action_msg");
             return; 
            } 
           

           }  
          
    }             
    else{
     me->add_temp("lingxiao_time",-1);
    }
    //7)    
    me->delete_temp("apply_effskill_lingxiao");
    me->delete_temp("action_msg");
    
          
}
 
