// perform.c
//written by yanyan. for dt.
//2000.12
inherit F_CLEAN_UP;
#include <skill.h>

int main(object me, string arg)
{
	object target;
	string type,*performs,*skl,perf;
	mapping skills;
	int i,flag;
        int p_damage;
        	
	flag=0;
	seteuid(getuid());

	if( me->is_busy() )
		return notify_fail(" ����һ��������û����ɣ�����ʩ���⹦��\n");
	if(me->query_temp("no_eff_combat"))
	return notify_fail("�������޷�ʩչ�⹦��\n");
 
    if( !arg ) return notify_fail("��Ҫ���⹦��ʲô��\n");
   if ( !wizardp(me)&&environment(me) && environment(me)->query("no_fight")&&!environment(me)->query("leitai")) 
     return notify_fail("���ﲻ��ʩ���⹦��\n");

        if( sscanf(arg, "%s on %s", perf, arg)==2 ) {
                target = present(arg, environment(me));
                if( !target ) target = present(arg, me);
                if( !target ) return notify_fail("����û�� " + arg + "��\n");

 
                if( userp(me) && userp(target) && 
                    target->query_temp("netdead") )
                   return notify_fail("�Է����ڶ����У����ܶ���ʩ���⹦��\n");
                if(target->query_temp("no_eff_perform"))
                return notify_fail("�Է����书�߳����޷���Է�ʩչ�⹦��\n");
               arg=perf+" "+arg;
        } else if(sscanf(arg, "%s %s", perf, arg)==2 ) {
     arg=perf+" "+arg;
        } else perf=arg;
		
    skills=me->query_skills();
	if(!sizeof(skills)) 
		return notify_fail("��û���κμ���!\n");
	skl=keys(skills);
	for(i=0;i<sizeof(skl);i++)
	{
           performs=SKILL_D(skl[i])->query_perform();
	   if(!sizeof(performs)) continue;
	   if(sizeof(performs)>sizeof(performs-({perf})))
	   {
		   flag=1;
		   type=SKILL_D(skl[i])->query_type();
		   break;
	   }
	} 
       if(flag==0)
       return notify_fail("����⹦��û�д˼���!\n");
       
       p_damage=me->query_temp("csj_skill_damage");
       if(p_damage&&time()-me->query_temp("csj_damage_time")<p_damage/7){
         tell_object(me,"\n�����˳��������ˣ����˼Ӿ��ˣ�\n");
         me->receive_wound("kee",p_damage*3);
         return 1;
       }
	  return (int)SKILL_D(type)->perform_action(me,arg);
	  
}

