//action.

#include <ansi.h>

string strleft(string msg,int blank)
{
while(strlen(msg)<blank)
	msg = msg+" ";

return msg;	
		
}

string str2left(string msg,int blank)
{
if(strlen(msg)%2!=0)
	msg = msg+" ";
while(strlen(msg)<blank)
	msg = msg+"��";

return msg;	
		
}

int main(object me,string arg)
{
        mapping *action;
        string *performs;
        int i;
        string msg;
	
	if(!arg) return notify_fail("������ action �书���� �ĸ�ʽ.\n");
	if(file_size("/daemon/skill/"+arg+".c")<=0)
		return notify_fail("û�������书!\n");
	if(!me->query_skill(arg,1)&&!wizardp(me))
	return notify_fail("��û��ѧϰ����书��\n");
	msg = "";	
	if(action=SKILL_D(arg)->query_all_action(me))
	{
	  msg = "\n����"+str2left(HIG+arg+NOR+" ����",50)+"����������������������������\n";
	  for(i=0;i<sizeof(action);i++){
	    msg = msg+strleft("����"+chinese_number(i+1)+"�� ",15)+
	    					strleft("��"+action[i]["name"]+"��",25)+
	    				  strleft("������"+action[i]["apply_factor"],24)+"��\n";
	    
	  }
	  msg = msg+"������������������������������������������������������������������\n";
	  
	}
	if(performs=SKILL_D(arg)->query_perform())
	{
	  msg = msg+"����"+str2left(HIG+arg+NOR+" �����⹦",50)+"����������������������������\n";
	  for(i=0;i<sizeof(performs);i++)	
	   msg = msg+strleft("��perform			"+
	   									HIY+performs[i]+NOR,60)+"��\n";
	  msg = msg+"������������������������������������������������������������������\n";
	}
	if(performs=SKILL_D(arg)->query_exert())
	{
	  msg = msg+"����"+str2left(HIG+arg+NOR+" �����ڹ�",50)+"����������������������������\n";
	  for(i=0;i<sizeof(performs);i++)	
	   msg = msg+strleft("��exert			"+
	   									HIY+performs[i]+NOR,66)+"��\n";
	  msg = msg+"������������������������������������������������������������������\n";
	}
	if(performs=SKILL_D(arg)->query_execute())
	{
	  msg = msg+"����"+str2left(HIG+arg+NOR+" �����÷�",50)+"����������������������������\n";
	  for(i=0;i<sizeof(performs);i++)	
	   msg = msg+strleft("��execute			"+
	   									HIY+performs[i]+NOR,60)+"��\n";
	  msg = msg+"������������������������������������������������������������������\n";
	}
	if(msg=="")
	  tell_object(me,"\n����书û����ϸ��˵���ļ���\n\n");
	else
	  tell_object(me,msg);
	return 1;
}