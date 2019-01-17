
#include <weapon.h>
#include <ansi.h>

inherit HAMMER;

void create()
{
	set_name(HIB"����"NOR, ({ "xiang long","hammer" }) );
	set_weight(9000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","����һ��������������������Ϊ������֮������\n");
		set("value", 400);
		//set("super",9);
		set("material", "steel");
		set("weapon_prop/dodge",60);
		set("weapon_prop/hammer",80);
		set("weapon_prop/parry",60);
		
	}
	init_hammer(270,300,300);

	set("wield_msg", HIC"$N"+HIC+"��ৡ���һ����$n"+HIC+"��ֻ�����֮����˸����硣\n"NOR);
	set("unwield_msg", "$N�����е�$n��������ĵ��ʡ�\n");


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
    
    owner->add("max_force",200);
    owner->add("max_kee",800);
       
    return 1;
}

int unequip()
{
   object owner;
    
    if(!environment()) return 0;
    if( !(owner = environment())->is_character() ) return 0;
    
    if(!::unequip()) return ::unequip();
    owner->add("max_force",-200);
    if(owner->query("force")>owner->query("max_force"))
      owner->set("force",owner->query("max_force"));
    
    owner->add("max_kee",-800);
    	if(owner->query("eff_kee")>owner->query("max_kee")){
      owner->set("eff_kee",owner->query("max_kee"));
      owner->set("kee",owner->query("max_kee"));}
    
   
    return 1;
}
