//execute.c

inherit F_CLEAN_UP;
#include <skill.h>

int main(object me, string arg)
{
	object target;
	string type,*executes,*skl,exec;
	mapping skills;
	int i;int flag;
	
	flag=0;
	seteuid(getuid());

	if( me->is_busy() )
		return notify_fail("����һ��������û����ɣ�����ʩ���ķ���\n");
                        
    if( !arg ) return notify_fail("��Ҫʹ��ʲô�ķ���\n");
   if ( !wizardp(me)&&environment(me) && environment(me)->query("no_fight")&&!environment(me)->query("leitai")) 
     return notify_fail("���ﲻ��ʹ���ķ���\n");

   if( sscanf(arg, "%s on %s", exec, arg)==2 ) {
   	target = present(arg, environment(me));
    if( !target ) target = present(arg, me);
    if( !target ) return notify_fail("����û�� " + arg + "��\n");

    if( userp(me) && userp(target) && 
       	target->query_temp("netdead") )
    	return notify_fail("�Է����ڶ����У����ܶ���ʩ���ķ���\n");
    	arg=exec+" "+arg;
   } 
   else 
   if(sscanf(arg, "%s %s", exec, arg)==2 ) {
     arg=exec+" "+arg;
   } 
   else 
   	exec=arg;
		
   skills=me->query_skills();
   if(!sizeof(skills)) 
		return notify_fail("��û���κμ���!\n");
	 skl=keys(skills);
	
	for(i=0;i<sizeof(skl);i++)
	{
     executes=SKILL_D(skl[i])->query_execute();
	   if(!sizeof(executes)) continue;
	   if(member_array(exec,executes)!=-1)
	   {
		   flag=1;
		   type="xinfa";
		   break;
	   }
	} 
       if(flag==0)
       return notify_fail("��û������ķ�����ʩչ!\n");
          
       return (int)SKILL_D(type)->execute_action(me,arg);
}

int help()
{
  write("
    ����ʹ�����������ʹ������ѧ���ķ���
\n");
return 1;
}