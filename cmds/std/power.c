#include <power.h>
#include <org.h>

string orgmsg(object me)
{
	string msg;
	
	if(!me->query("shili"))
		return me->name()+"��û�м����κΰ�ᡣ\n";
	
		msg = "\n����"+str2left("���� "+HIG+ORG_D->get_shili(me)+NOR+" ������",70)+"��\n";
  	msg += "��                                                        ��\n";
  	if(me->query("shili/wide"))
  		msg +="��"+HIC+"�������ķ�Χ��"+strleft(HIW+me->query("shili/wide")+NOR+	
  			"        "+HIY+"��Ȩ����"+HIR+get_power(me->query("shili/power"))+NOR,81)+"��\n";
  	else
  		msg +="��"+HIC+"�������ķ�Χ��"+strleft(HIW+"��"+NOR+
  			"        "+HIY+"��Ȩ����"+HIR+get_power(me->query("shili/power"))+NOR,81)+"��\n";  
  	msg += "��"+HIG+"����ְ��"+strleft(HIM+ORG_D->query_guanzhi(me)+NOR,64)+"��\n";
  	msg += "��                                                        ��\n";
  	msg += "������������������������������������������������������������\n";
	
	return msg;
	
}

int main(object me,string arg)
{
  string wide,name,powerd;
  object ob;int power;  
  
  if(!arg){
  	
  	tell_object(me,orgmsg(me));
  	return 1;
  }
  
  if(sscanf(arg,"%s %s %d",name,wide,power)!=3)
   return notify_fail("��ʹ��power [ĳ��] [ĳ��Ȩ����Χ] [�ȼ�]��\n"+
   			"�磺power xx yz 3\n"+
   			"���д�����ʹ�� help power �鿴��\n");
  if(power<=0||power>=8)
  return notify_fail("�ȼ�Ȩ��ֻ����0~7\n");
  if(!objectp(ob=present(name,environment(me))))
  return notify_fail("����û������ˡ�\n");
  
  if(me==ob)
  	return notify_fail("������ͷ����ѽ���Һ�Ϳ�ˣ���ô�ܸ��Լ�����ְ���أ�\n");
  	
  if(!me->query("shili/leader"))
   return notify_fail("��е���־�ɥ��ԭ��ֻ������ſ�����ô����\n");
 if(me->query("shili/name")!=ob->query("shili/name"))
 	return notify_fail("����ϸһ����ԭ��"+ob->name()+"���Ǻ���һ���������ˣ�\n");
 
 if(!userp(ob))
 	return notify_fail(ob->name()+"�����ܳ���������̫���������ˣ����ҿɲ��ҵ���\n");	
 	
 wide=check_wide(wide);
 powerd=get_power(power);
  if(power==1)
  {
    ob->set("shili/leader",ob->query("shili/name"));
    me->delete("shili/leader");
    CHANNEL_D->do_channel(this_object(), "rumor",
	sprintf("%s��"+get_leader(ob)+HIM+"��λ��%s�ˡ�",me->name(), ob->name()));
    ORG_D->set_leader_log(ob,me);
    me->save();
    ob->save();
    return 1;
  }
 if(wide=="�޴�")
 return notify_fail("��ʹ��help power ����ѯ���г��С�\n");
 ob->set("shili/wide",wide);
 ob->set("shili/power",power);
 CHANNEL_D->do_channel(this_object(), "rumor",
	sprintf("%s����%s����"+HIW+wide+NOR+HIM",����"+HIR+powerd+NOR+HIM+"��Ȩ����",me->name(), ob->name()));
 me->save();
 ob->save();
 return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : power [ĳ��] [ĳ��Ȩ����Χ] [�ȼ�]
�磺power xx yz 3

Ŀǰ���������ĳ��д���

changan:����    luoyang:����       xiangyang:����      chengdu:�ɶ�
baling:����     hefei:�Ϸ�         jiujiang:�Ž�       yangzhou:����
hangzhou:����   xingyang:����      liyang:����         xucheng:���
pengliang:����  leshou:����        yuyang:����         shanhaiguan:ɽ����
taiyuan:̫ԭ    mayi:����          dingxiang:����      saiwai:����
suiye:��Ҷ      tuyuhun:���Ȼ�     gaoli:����

����
	�μ�
	���ϼ�
	�м�
	���¼�
	�¼�
	���¼�
	��ͼ�

HELP
    );
    return 1;
}