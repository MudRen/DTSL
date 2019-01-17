
#include <weapon.h>
#include <ansi.h>

inherit DAGGER;

void create()
{
	set_name(HIR"����"NOR, ({ "cai yu","dagger" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 300);
		set("long","����һ�����������̱��У���Ϊ���ɷ�֮���𡹡�\n");
		set("material", "steel");
		set("weapon_prop/dodge",80);
		set("weapon_prop/dagger",50);
		set("weapon_prop/feifeng",1);
	}
	init_dagger(200,300,300);

	set("wield_msg", HIR"$N"+HIR+"�ӻ�������һ��$n"+HIR+"�������У�ֻ��һ���ʹ����������ܡ�\n"NOR);
	set("unwield_msg", "$N�����е�$n���뻳�С�\n");


	setup();
}

int wield()
{
    object owner;
    
    if(!environment()) return 0;
    if( !(owner = environment())->is_character() ) return 0;
    
    if(!::wield()) return ::wield();
    
    if(owner->query("combat_exp")<2000000)
    return notify_fail("��Ŀǰ�޷�װ�������Ʒ��\n");
    
    if(owner->query_temp("apply/feifeng")==5){
    	message_vision(HIY"$N"+HIY+"�������ֳ������ɫ�Ļ��󣬾þò�����ʧ��\n"NOR,owner);
    	owner->add_temp("apply/damage",100);
    	owner->add("max_kee",1000);
    	owner->add("max_force",200);
    	owner->add_temp("apply/dagger",50);}
    
    return 1;
}

int unequip()
{
   object owner;
    
    if(!environment()) return 0;
    if( !(owner = environment())->is_character() ) return 0;
    
    if(!::unequip()) return ::unequip();
    
    if(owner->query_temp("apply/feifeng")==4){
    	owner->add_temp("apply/damage",-100);
    	owner->add("max_kee",-1000);
    	if(owner->query("eff_kee")>owner->query("max_kee")){
      owner->set("eff_kee",owner->query("max_kee"));
      owner->set("kee",owner->query("max_kee"));}
      
      owner->add("max_force",-200);
    if(owner->query("force")>owner->query("max_force"))
      owner->set("force",owner->query("max_force"));
      
      owner->add_temp("apply/dagger",-50);}
    
    return 1;
}
