
#include <weapon.h>
#include <ansi.h>

inherit SWORD;

string *name=({HIC"���"NOR,HIR"���"NOR,HIW"���"NOR,HIR"��Ѫ"NOR});

void create()
{
	int i;
	i=random(sizeof(name));
	
	set_name(name[i], ({ "sword" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","����һ������������������\n");
		set("value", 100000);
		//set("super",9);		
		set("material", "steel");
		set("weapon_prop/dodge",10);
		set("weapon_prop/sword",5);
		
	}
	init_sword(160,300,300);

	set("wield_msg", "$N��ৡ���һ����$n��ֻ��һ���������������\n"NOR);
	set("unwield_msg", "$N�����е�$n��������Ľ��ʡ�\n");


	setup();
}


int wield()
{
    object owner;
    
    if(!environment()) return 0;
    if( !(owner = environment())->is_character() ) return 0;
    
    if(!::wield()) return ::wield();
    
    if(owner->query("combat_exp")<500000)
    return notify_fail("��Ŀǰ�޷�װ�������Ʒ��\n");
    
    owner->add("max_force",2);
    owner->add("max_kee",50);
    
    
    
    return 1;
}

int unequip()
{
   object owner;
    
    if(!environment()) return 0;
    if( !(owner = environment())->is_character() ) return 0;
    
    if(!::unequip()) return ::unequip();
    owner->add("max_force",-2);
    if(owner->query("force")>owner->query("max_force"))
      owner->set("force",owner->query("max_force"));
   
   owner->add("max_kee",-50);
    	if(owner->query("eff_kee")>owner->query("max_kee")){
      owner->set("eff_kee",owner->query("max_kee"));
      owner->set("kee",owner->query("max_kee"));}
   
   
    return 1;
}
