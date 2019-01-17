
#include <dbase.h>
#include <ansi.h>

#include "tiejiang.h"

string *msg=({
HIY"$N"+HIY+"���������˺���¯�ӵĻ�Խ��Խ���ˣ�\n"NOR,
HIR"ֻ������Խ��Խ����$N"+HIR+"��Щ�ܲ����ˡ�\n"NOR,
HIB"$N"+HIB+"��ͣ�Ļ�����������ƹƹ���ҵ��ô��ű�����\n"NOR,
HIB"$N"+HIB+"��ͣ�Ļ�����������ƹƹ���ҵ��ô��ű�����\n"NOR,
RED"$N"+RED+"��Щ�����������������ӳ��ͨ�졣\n"NOR,
YEL"$N"+YEL+"�����ڱ����ϵ���ʶһ����Ĩȥ��\n"NOR,
YEL"$N"+YEL+"��ע��Ѫ������Ϊ�����������ԡ�\n"NOR,

});

int check_legal_id(string id);

int main(object ob,string arg)
{
	object weapon,iron;
	string id,weapon_name;	
	int strong,max_strong;
	string j="";
	
	if(ob->query("vocation")!="����")
	return notify_fail("ֻ���������ܸ�����ȷ�����ˡ�\n");
	
	if(ob->query_skill("duanzao-jishu",1)<60)
	return notify_fail("��Ķ��켼��̫���ˣ��޷�������ȷ�����ˡ�\n");
	
	if(ob->query("max_force")<1000)
	return notify_fail("���������Ϊ̫�ͣ��޷�������ȷ�����ˣ�\n");	
	
	if(member_array(base_name(environment(ob)),tiejiang_here)==-1)
        return notify_fail("�㻹�ǵ�������ȥ������ȷ�����˰ɣ�\n");	
	
	if(ob->is_fighting())
	 return notify_fail("�㻹�ڴ����أ�\n");
	
	if(ob->is_busy())
	 return notify_fail("����æ���أ�\n");
	
	if(!arg)
		return notify_fail("��ʹ�� renzhu ���� with ����id��\n");
	if(sscanf(arg,"%s with %s",weapon_name,id)!=2)
	    return notify_fail("��ʹ�� renzhu ���� with ����id��\n");
	
	if(!check_legal_id(id))
	 return 1;
	 
	if(!objectp(weapon=present(weapon_name,ob)))
		return notify_fail("�����ϲ�û���������!\n");
	
	if(!weapon->is_dazao())
		return notify_fail("����������ܱ�ȷ�����ˣ�\n");
	
	if(weapon->query("user")!="")
		return notify_fail("��������Ѿ��������ˣ�\n");
   
	if(!weapon->query("skill_type"))
		return notify_fail("��ֻ�ܸ�����ȷ�����ˣ�\n");
        
	 if(userp(ob)&&ob->query("gin")<800)
	 return notify_fail("�㷢���������ڵľ�Ѫ�޷�������ȷ�����ˡ�\n");
        
	message_vision("$N��"+weapon->query("name")+"�ŵ�"+environment(ob)->query("short")+"����¯�ϡ�\n",ob);
	message_vision(RED"\n$N"+RED+"�������䣬�𡰺�����һ������������\n"NOR,ob);
	
	if(userp(ob))
	 ob->receive_damage("gin",800);
		
	ob->start_busy(5);
	
	call_out("do_msg",5,ob,weapon,id,0);
	
	return 1;
	
	
}

void do_msg(object ob,object weapon,string id,int times)
{
	int rate=0;
	
	if(!ob||!weapon||environment(weapon)!=ob)
		return;
	
	if(times>=sizeof(msg)){
		weapon->set("user",id);
		
		tell_object(ob,HIC"������ѱ������е������Ѿ��㹻��ʶ�Լ��������ˡ�\n"NOR,);
		
		return;
    }
    message_vision(msg[times]+"\n",ob);
    ob->start_busy(5);
    
    call_out("do_msg",5,ob,weapon,id,times+1);
    
}



int check_legal_id(string id)
{
	int i;
	i = strlen(id);
	if((strlen(id) < 3) || (strlen(id) > 8)) 
	{
		write("�Բ������˵����ֱ����� 3 �� 8 ��Ӣ����ĸ��\n");
		return 0;
	}
	while(i--)
		if(id[i]<'a' || id[i]>'z') 
		{
			write("�Բ������˵�Ӣ������ֻ����Ӣ����ĸ��\n");
			return 0;
		}
	
	return 1;
}