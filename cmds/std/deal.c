// deal.c

inherit F_CLEAN_UP;

#include <ansi.h>


string swap_msg(string arg)
{
   switch(arg){
   	
   case "����": return "int";
   case "����": return "con";
   case "����": return "str";
   case "����": return "str";
   case "��": return "dex";
   default: return "error";
   }
}

int main(object me, string arg)
{
   
   int i,exp;
   string point_name,self_msg;
  
  if(!arg){  
  	exp = me->query("combat_exp");  	
  	if(!me->query("char_lev/lev")){
  		me->set("char_lev/lev",500000);
  		me->set("char_lev/times",0);
  	}
  	for(;;){
  		if(exp>=me->query("char_lev/lev")+500000*me->query("char_lev/times")){
  			me->set("char_lev/lev",me->query("char_lev/lev")+500000*me->query("char_lev/times"));  			
  			me->add("char_lev/times",1);
  			if(me->query("char_lev/times")<3)
  				me->add("char_lev/points",me->query("char_lev/times"));
  			else
  				me->add("char_lev/points",3);  				
  		}
  		else
  		break;
  	}
  	return notify_fail("�����ڿ��Է�������Ե�Ϊ"+HIY+"��"+
    	chinese_number(me->query("char_lev/points"))+"��"+NOR+"�㡣\n");
  }
  
  if(me->query("char_lev/points")<=0)
  	return notify_fail("���Ѿ�û�����Ե���Է����ˡ�\n");
  
  point_name=swap_msg(arg); 
  
  if(point_name=="error")
  return notify_fail("��ֻ��ѡ�����ԡ��������ǡ���������������������һ�֡�\n");
  
  me->add("char_lev/points",-1);
  me->add(point_name,1);
  tell_object(me,"���"+HIY+arg+NOR+"����ˣ�\n");
  return 1;
   
}


int help(object me)
{
	write(@HELP
ָ���ʽ��deal <������Ŀ>
 
�������Լ������ԡ�
�� deal ����
ÿ���һ��ս�����飬��ͻ������ԣ��������£�
500K  ս�����飬�ܻ�� 1 ������
1000K ս�����飬�ܻ�� 2 ������
2000K ս�����飬�ܻ�� 3 ������
3500K ս�����飬�ܻ�� 3 ������
5500K ս�����飬�ܻ�� 3 ������ 
�Դ����ơ�
HELP
    );
    return 1;
}
