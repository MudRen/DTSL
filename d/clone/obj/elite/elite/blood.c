
#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	set_name(HIR"Ѫ"NOR, ({ "xue","sword" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","����һ��������������������Ϊ��Īа֮Ѫ����\n");
		set("value", 400);
		//set("super",9);
		set("material", "steel");
		set("weapon_prop/dodge",100);
		set("weapon_prop/sword",40);
		set("weapon_prop/moye",1);
	}
	init_sword(250,300,300);

	set("wield_msg", HIR"$N"+HIR+"��ৡ���һ����$n"+HIR+"��ֻ��һ��ĺ���������ɢ�˳�����\n"NOR);
	set("unwield_msg", "$N�����е�$n��������Ľ��ʡ�\n");


	setup();
}


int wield()
{
    object owner;
    
    if(!environment()) return 0;
    if( !(owner = environment())->is_character() ) return 0;
    
    if(!::wield()) return ::wield();
    
    if(owner->query("combat_exp")<3000000)
    return notify_fail("��Ŀǰ�޷�װ�������Ʒ��\n");
    
    owner->add("max_force",500);
    owner->add("max_sen",500);
    owner->add("eff_sen",500);
    
    if(owner->query_temp("apply/moye")==4){
    	message_vision(HIR"$N"+HIR+"������ð��������Σ��þò�����ɢ��\n"NOR,owner);
    	owner->add_temp("apply/damage",100);
    	owner->add_temp("apply/dodge",100);
    	owner->add("max_kee",500);
    	owner->add("max_force",1000);}
    
    return 1;
}

int unequip()
{
   object owner;
    
    if(!environment()) return 0;
    if( !(owner = environment())->is_character() ) return 0;
    
    if(!::unequip()) return ::unequip();
    owner->add("max_force",-500);
    if(owner->query("force")>owner->query("max_force"))
      owner->set("force",owner->query("max_force"));
    owner->add("max_sen",-500);
    owner->add("eff_sen",-500);
    if(owner->query("sen")>owner->query("eff_sen"))
      owner->set("sen",owner->query("eff_sen"));
    
    if(owner->query_temp("apply/moye")==3){
    	owner->add_temp("apply/damage",-100);
    	owner->add_temp("apply/dodge",-100);
    	owner->add("max_kee",-500);
    	if(owner->query("eff_kee")>owner->query("max_kee")){
      owner->set("eff_kee",owner->query("max_kee"));
      owner->set("kee",owner->query("max_kee"));}
    	owner->add("max_force",-1000);
    	if(owner->query("force")>owner->query("max_force"))
      owner->set("force",owner->query("max_force"));}
    
    return 1;
}
