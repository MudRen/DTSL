// parryd.c
//use by combatd.c
//written by yanyan.2000.11.

inherit F_DBASE;

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
#include "/adm/daemons/parry.h"

void do_weapon_fight(object me,object victim,object weapon,object vweapon);

void do_parry(object me,object victim,object weapon,object vweapon)
{
	
	string skill_name;
	string parry_msg,*limbs,limb;
	
	skill_name=victim->reset_action(vweapon);
	
	if(!skill_name) return;
	
	parry_msg=SKILL_D(skill_name)->query_parry_action(victim,me);
	
	if(!stringp(parry_msg)){//�������û���м�������ʹ��Ĭ�ϵģ���parry.h�С�
	
	if(weapon&&vweapon)
	 parry_msg=parry1[random(sizeof(parry1))];
	else
	if(!weapon&&vweapon)
	 parry_msg=parry2[random(sizeof(parry2))];
	else
	if(weapon&&!vweapon)
	 parry_msg=parry3[random(sizeof(parry3))];
	else
	 parry_msg=parry4[random(sizeof(parry4))];
	
	}
	
	limbs=me->query("limbs");
	limb=limbs[random(sizeof(limbs))];
	
	parry_msg=replace_string(parry_msg,"$l",limb);
	if(weapon)
	parry_msg=replace_string(parry_msg,"$v",weapon->name());
	if(vweapon)
	parry_msg=replace_string(parry_msg,"$w",vweapon->name());
	
	message_vision(parry_msg,victim,me);
	
	if(weapon&&vweapon){
		
		if(vweapon->query("flag")&&random(10)>6){
		  vweapon->add("weapon_prop/damage",-1);
		  if(vweapon->query("weapon_prop/damage")<0)
		    vweapon->set("weapon_prop/damage",0);
		}
		do_weapon_fight(me,victim,weapon,vweapon);
		return;
	}else if(weapon&&!vweapon){
		if(victim->query("force")>(2*me->query("force")+800)&&
		   victim->query("eff_kee")*100/victim->query("max_kee")>=60&&
		   victim->query("max_force")>me->query("max_force")*3/2){
			message_vision(HIW"ֻ�����һ����$N���е�"+weapon->name()+"��$n��������ˣ�\n"NOR,me,victim);
			weapon->unequip();
			weapon->move(environment(me));
			me->reset_action(0);
			return;
		}
	    return;
		}
	else return;
  
   return;
	
}
void do_weapon_fight(object me,object victim,object weapon,object vweapon)
{
   int v_super,super;
   
   v_super=vweapon->query("super");
   super=weapon->query("super");
   
      if(random(10)>2)
    return;
   
   if(!v_super&&!super){
   	weapon->add("strong",-random(3));
        vweapon->add("strong",-random(3));
   }
   else
   if(random(v_super+super)>super)
    weapon->add("strong",-vweapon->query("super",1)-random(3));
   else
    vweapon->add("strong",-weapon->query("super",1)-random(3));
   
  
   if((int)weapon->query("strong",1)<=0&&(int)weapon->query("flag",1)!=1)
   {
	   message_vision(HIW"ֻ���ҵ�һ����$N���е�"+weapon->name()+"�Ѷ�Ϊ����!\n"NOR,me);
	   weapon->set("flag",1);
	   weapon->set("org_name",weapon->name());
	   weapon->set("name","�ϵ���"+weapon->name());
	   if(!userp(me)){
         weapon->unequip();
		 weapon->move(environment(me));}
   }
   if((int)vweapon->query("strong",1)<=0&&(int)vweapon->query("flag",1)!=1)
   {
	   message_vision(HIW"ֻ���ҵ�һ����$N���е�"+vweapon->name()+"�Ѷ�Ϊ����!\n"NOR,victim);
	   vweapon->set("flag",1);
	   vweapon->set("org_name",vweapon->name());
	   vweapon->set("name","�ϵ���"+vweapon->name());
	   if(!userp(victim)){
		   vweapon->unequip();
		   vweapon->move(environment(victim));}
   }
   
   if(weapon->query("strong")<=0){
    weapon->set("strong",0);
    weapon->add("weapon_prop/damage",-1);
    if(weapon->query("weapon_prop/damage")<0)
     weapon->set("weapon_prop/damage",0);
   }
   
   if(vweapon->query("strong")<0){
    vweapon->set("strong",0);	
    vweapon->add("weapon_prop/damage",-1);
    if(vweapon->query("weapon_prop/damage")<0)
     vweapon->set("weapon_prop/damage",0);
   }
	
	return;
}
