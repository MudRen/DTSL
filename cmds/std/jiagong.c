
#include <dbase.h>
#include <ansi.h>

#include "tiejiang.h"

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

void bad_weapon(object weapon);
void good_weapon(object weapon,int rate,int u_rate);

int main(object ob,string arg)
{
	object weapon,iron;
	string iron_name,weapon_name;	
	int strong,max_strong;
	string j="";
	
	if(ob->query("vocation")!="����")
	return notify_fail("ֻ���������ܼӹ�������\n");
	
	if(ob->query_skill("duanzao-jishu",1)<60)
	return notify_fail("��Ķ��켼��̫���ˣ��޷��ӹ�������\n");
	
	if(ob->query("max_force")<1000)
	return notify_fail("���������Ϊ̫�ͣ��޷��ӹ�������\n");
        
        if(member_array(base_name(environment(ob)),tiejiang_here)==-1)
        return notify_fail("�㻹�ǵ�������ȥ�ӹ������ɣ�\n");		
	
	if(ob->is_fighting())
	 return notify_fail("�㻹�ڴ����أ�\n");
	
	if(ob->is_busy())
	 return notify_fail("����æ���أ�\n");
	
	if(!arg)
		return notify_fail("��ʹ�� jiagong ���� with ��ʯ��\n");
	if(sscanf(arg,"%s with %s",weapon_name,iron_name)!=2)
	    return notify_fail("��ʹ�� jiagong ���� with ��ʯ��\n");
	if(!objectp(weapon=present(weapon_name,ob)))
		return notify_fail("�����ϲ�û���������!\n");
	
	if(!weapon->is_dazao())
		return notify_fail("����������ܱ��ӹ���\n");
	
	if(weapon->query("jiagong"))
		return notify_fail("��������Ѿ��ӹ����ˣ�\n");
    if(!objectp(iron=present(iron_name,ob)))
		return notify_fail("�����ϲ�û�����ֿ�ʯ!\n");
	if(!iron->query("weapon"))
		return notify_fail(iron->query("name")+"���ǿ�ʯ��\n");
	if(!weapon->query("skill_type"))
		return notify_fail("��ֻ�ܼӹ�������\n");
    
    strong=(int)weapon->query("strong",1);
	max_strong=(int)weapon->query("max_strong",1);
	 	
	 if(userp(ob)&&ob->query("gin")<800)
	 return notify_fail("�㷢���������ڵľ�Ѫ�޷��ӹ�������\n");
        
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
	int rate=0;
	int u_rate=0;
	
	if(!ob||!weapon||environment(weapon)!=ob)
		return;
	
	if(times>=sizeof(msg)){
		weapon->set("jiagong",1);
		if(present("bingpo shenzhu",ob)||present("huolong neidan",ob))
			rate=10;
			u_rate=3;
		rate+=random(ob->query_skill("duanzao-jishu",1)/10);
		if(random(ob->query_kar())<ob->query_kar()-3){
		 tell_object(ob,"\n��������ô��Ŭ������������������޷�ͻ�����ľ��ޣ����ڴﵽ���ޱ����ˡ�\n");
			bad_weapon(weapon);
		}
		else{
		 tell_object(ob,"\n�������Ŭ����������������ͻ�����ƣ���Խ�˱���\n");
		 good_weapon(weapon,rate,u_rate);
		}
		ob->add("max_force",-2);
		return;
    }
    message_vision(msg[times]+"\n",ob);
    ob->start_busy(5);
    
    call_out("do_msg",5,ob,weapon,times+1);
    
}

void bad_weapon(object weapon)
{
	weapon->set("weapon_prop/damage",weapon->query("weapon_prop/damage")/3);
	weapon->set("weapon_prop/min_damage",weapon->query("weapon_prop/min_damage")/3);
	if(random(100)>60)
	 weapon->set("weapon_prop/enhance_min_damage",0);
	if(random(100)>60)
	 weapon->set("weapon_prop/intelligence",0);
	if(random(100)>60)
	 weapon->set("weapon_prop/dodge",0);
	if(random(100)>60)
	 weapon->set("weapon_prop/karma",0);
	if(random(100)>60)
	 weapon->set("weapon_prop/dodgeaction",0);
	if(random(100)>60)
	 weapon->set("weapon_prop/constitution",0);
	if(random(100)>60)
	 weapon->set("weapon_prop/personality",0);
	if(random(100)>60)
	 weapon->set("weapon_prop/armor",0);
	if(random(100)>60)
	 weapon->set("weapon_prop/strength",0);
	
}

void good_weapon(object weapon,int rate,int u_rate)
{
	
	if(random(100)>u_rate) rate=1+random(2);
	else rate=random(10);
	
	weapon->add("weapon_prop/min_damage",random(rate)*10+1);
	if(weapon->query("weapon_prop/min_damage")>weapon->query("weapon_prop/damage"))
	weapon->set("weapon_prop/min_damage",weapon->query("weapon_prop/damage"));
	
	if(random(100)>90)
	 weapon->add("weapon_prop/enhance_min_damage",random(rate)+random(10)+5);
	else
	if(random(100)>60)
	 weapon->add("weapon_prop/enhance_min_damage",random(10));
	
	if(random(100)>90)
	 weapon->add("weapon_prop/enhance_max_damage",random(rate)+random(10)+5);
	else
	if(random(100)>60)
	 weapon->add("weapon_prop/enhance_max_damage",random(10));
	
	if(random(100)>90)
	 weapon->add("weapon_prop/double_damage",random(rate));
	else
	if(random(100)>60)
	 weapon->add("weapon_prop/double_damage",random(5));
	 	
	if(random(100)>80)
	 weapon->add("weapon_prop/dodge",random(rate)+random(10)+5);
	else
	if(random(100)>60)
	 weapon->add("weapon_prop/dodge",random(10)+5);
	 
	if(random(100)>80)
	 weapon->add("weapon_prop/armor",random(rate)+random(10)+5);
	else
	if(random(100)>60)
	 weapon->add("weapon_prop/armor",random(10)+5);
	
	if(random(100)>95)
	 weapon->add("weapon_prop/intelligence",random(rate/2)+1);	
	if(random(100)>95)
	 weapon->add("weapon_prop/karma",random(rate/2)+1);
	if(random(100)>95)
	 weapon->add("weapon_prop/dodgeaction",random(rate/2)+1);
	if(random(100)>95)
	 weapon->add("weapon_prop/constitution",random(rate/2)+1);
	if(random(100)>95)
	 weapon->add("weapon_prop/personality",random(rate/2)+1);
	
	if(random(100)>95)
	 weapon->add("weapon_prop/strength",random(rate/2)+1);
	
	if(random(100)>96)
	 weapon->add("super",1);
	 
}