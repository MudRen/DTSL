
#include <dbase.h>
#include <ansi.h>

#include "tiejiang.h"

string result_strong(int i);

string *msg=({
HIY"$N"+HIY+"���������˺���¯�ӵĻ�Խ��Խ���ˣ�\n"NOR,
HIY"$N"+HIY+"���������˺���¯�ӵĻ�Խ��Խ���ˣ�\n"NOR,
HIR"ֻ������Խ��Խ����$N"+HIR+"��Щ�ܲ����ˡ�\n"NOR,
HIR"ֻ������Խ��Խ����$N"+HIR+"��Щ�ܲ����ˡ�\n"NOR,
HIB"$N"+HIB+"��ͣ�Ļ�����������ƹƹ���ҵ��ô��ű�����\n"NOR,
HIB"$N"+HIB+"��ͣ�Ļ�����������ƹƹ���ҵ��ô��ű�����\n"NOR,
RED"$N"+RED+"��Щ�����������������ӳ��ͨ�졣\n"NOR,
RED"$N"+RED+"��Щ�����������������ӳ��ͨ�졣\n"NOR,
});

int main(object ob,string arg)
{
	object weapon,iron;
	string iron_name,weapon_name;	
	int strong,max_strong;
	string j="";
	
	if(userp(ob)&&ob->query("vocation")!="����")
	return notify_fail("ֻ�������������������\n");
	
	if(userp(ob)&&ob->query_skill("duanzao-jishu",1)<60)
	return notify_fail("��Ķ��켼��̫���ˣ��޷����������\n");
	
	if(ob->is_fighting())
	 return notify_fail("�㻹�ڴ����أ�\n");
	
	if(ob->is_busy())
	 return notify_fail("����æ���أ�\n");
	
	if(member_array(base_name(environment(ob)),tiejiang_here)==-1)
        return notify_fail("�㻹�ǵ�������ȥ��������ɣ�\n");
	
	if(!arg)
		return notify_fail("��ʹ��xiuli ���� with ��ʯ��\n");
	if(sscanf(arg,"%s with %s",weapon_name,iron_name)!=2)
	    return notify_fail("��ʹ��xiuli ���� with ��ʯ��\n");
	
	if(!objectp(weapon=present(weapon_name,ob)))
		return notify_fail("�����ϲ�û���������!\n");
    if(!objectp(iron=present(iron_name,ob)))
		return notify_fail("�����ϲ�û�����ֿ�ʯ!\n");
	if(!iron->query("weapon"))
		return notify_fail(iron->query("name")+"���ǿ�ʯ��\n");
	if(!weapon->query("skill_type"))
		return notify_fail("��ֻ����������\n");
    
    strong=(int)weapon->query("strong",1);
	max_strong=(int)weapon->query("max_strong",1);
	 
	 if(!max_strong) max_strong=strong+100;	 

	 if(strong*100/max_strong==100)
	   return notify_fail(weapon->query("name")+"û���𻵣������޲�!\n");
	 j=result_strong(strong*100/max_strong);
	 tell_object(ob,"��ı����Ѿ�"+j+"\n");
     
	 if(userp(ob)&&ob->query("gin")<800)
	 return notify_fail("�㷢���������ڵľ�Ѫ�޷����������\n");
        
	message_vision("$N��"+weapon->query("name")+"�ŵ�"+environment(ob)->query("short")+"����¯�ϡ�\n",ob);
	message_vision(RED"\n$N"+RED+"�������䣬�𡰺�����һ������������\n"NOR,ob);
	
	if(userp(ob))
	 ob->receive_damage("gin",800);
	
	if(iron->query_amount()&&
	 iron->query_amount()>1)
	 iron->set_amount(iron->query_amount()-1);
	else
        destruct(iron);
        
	ob->start_busy(5);
	
	call_out("do_msg",5,ob,weapon,0);
	
	return 1;
	
	
}

void do_msg(object ob,object weapon,int times)
{
	
	if(!ob||!weapon||environment(weapon)!=ob)
		return;
	
	if(times>=sizeof(msg)){
		message_vision("$N���˲����������޺���"+weapon->query("name")+"��\n",ob);
		if(weapon->query("strong",1)<=0)
		weapon->set("name",weapon->query("org_name"));
	        weapon->set("strong",weapon->query("max_strong"));
	        weapon->set("flag",0);
		return;
    }
    message_vision(msg[times]+"\n",ob);
    ob->start_busy(5);
    
    call_out("do_msg",5,ob,weapon,times+1);
    
}

string result_strong(int i)
{
	if(i>=100)
	   return HIG"�������"NOR;
	if(i>=90)
		return HIG"��΢��"NOR;
	else if(i>=80) return HIG"�����"NOR;
	else if(i>=70) return GRN"������"NOR;
	else if(i>=60) return GRN"���˽ϴ�"NOR;
	else if(i>=50) return CYN"��ð뻵"NOR;
	else if(i>=40) return CYN"������"NOR;
	else if(i>=30) return BLU"�����۶�"NOR;
	else if(i>=20) return BLU"���Ʋ���"NOR;
	else if(i>=10) return RED"���ò���"NOR;
	else return RED"����֮��"NOR;
}
  
