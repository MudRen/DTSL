
#include <skill.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
   string force,*force_skill,*force_exert,exert;
   int result,i,flag;string tar,ski;
   int p_damage;
   
   seteuid(getuid());
   flag=0;
   if( me->is_busy() )
     return notify_fail("( ����һ��������û����ɣ�����ʩ���ڹ���)\n");
   if(me&&environment(me)&&environment(me)->query("no_exert"))
   return notify_fail("���ﲻ��ʹ���ڹ�!\n");
   if(!arg) return notify_fail("��Ҫ���ڹ���ʲô��\n");
   if(sscanf(arg,"%s %s",ski,tar)==2||sscanf(arg,"%s on %s",ski,tar)==2)
       arg=ski+" "+tar;
   else ski=arg;
   force_skill=me->query("force_skill");
   if(sizeof(force_skill)==0&&!me->query_skill("force"))
	   return notify_fail("��û��ѧ���κ��ڹ�!\n");
   
   p_damage=me->query_temp("bsy_skill_damage");
   if(p_damage&&time()-me->query_temp("bsy_damage_time")<p_damage/7){
        tell_object(me,"\n�����˲���ӡ���ˣ����˼Ӿ��ˣ�\n");
        me->receive_wound("kee",p_damage*3/2);
        return 1;
   }
   
   for(i=0;i<sizeof(force_skill);i++)
   {
	   force_exert=SKILL_D(force_skill[i])->query_exert();
	   if(sizeof(force_exert)<=0) continue;
	   if(sizeof(force_exert-({ski}))<sizeof(force_exert))
	   {
		   flag=1;break;
	   }
	  
   }
   if(flag==1) 
   {
     
     if( SKILL_D("force")->exert_function(me, arg) ) 
	 {

       
        return 1;
     }
	 else return (int)SKILL_D("force")->exert_function(me,arg);
   }
   else 
   {
	   force_exert=SKILL_D("force")->query_exert();
       if(sizeof(force_exert-({ski}))<sizeof(force_exert))
	   {
		   if( SKILL_D("force")->exert_function(me, arg) ) 
			   return 1;
		   else return (int)SKILL_D("force")->exert_function(me,arg);
	   }

	   else return notify_fail("����ڹ�û�����ֹ���!\n");
   }
 


}

